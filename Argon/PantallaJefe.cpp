#include "PantallaJefe.h"

PantallaJefe::PantallaJefe(Jugador* &jugador) {
	int x;
	mEntradas = AdminEntradas::Instancia();
	mAudio = AdminAudio::Instancia();

	mJugador = jugador;

	mAccionSeleccionada = 0;

	NotificarAtaque = false;
	mPeleaTerminada = false;

	mLayout = new Layout(mJugador);

	mFondo = new Textura("background/pelea.png");
	mFondo->Padre(this);
	mFondo->Pos(Vector2(400.0f, 300.0f));

	x = rand() % 2;
	if (mJugador->Piso() == 0) {
		switch (x) {
			case 0:
				x = rand() % 100 + 150;
				mEnemigo = new Enemigo(200, 15, x, "sprites/boss0.png");
				break;
			case 1:
				x = rand() % 100 + 150;
				mEnemigo = new Enemigo(200, 15, x, "sprites/boss1.png");
				break;
		}
	}
	else if (mJugador->Piso() == 1) {
		x = rand() % 100 + 250;
		mEnemigo = new Enemigo(400, 20, x, "sprites/boss2.png");
	}
	else if (mJugador->Piso() == 2) {
		x = rand() % 100 + 250;
		mEnemigo = new Enemigo(800, 25, x, "sprites/boss3.png");
	}
	
}

PantallaJefe::~PantallaJefe() {

	mEntradas = NULL;
	mAudio = NULL;

	delete mLayout;
	mLayout = NULL;

	delete mFondo;
	mFondo = NULL;

	delete mEnemigo;
	mEnemigo = NULL;
}

bool PantallaJefe::Terminada() {

	return mPeleaTerminada;
}

void PantallaJefe::CambiarAccion(int cambio) {

	mAccionSeleccionada += cambio;

	if (mAccionSeleccionada < 0) {
		mAccionSeleccionada = 3;
	}
	else if (mAccionSeleccionada > 3) {
		mAccionSeleccionada = 0;
	}

	mLayout->CambiarColor(mAccionSeleccionada);
}

void PantallaJefe::Actualizar() {

	delete mLayout;
	mLayout = NULL;
	mLayout = new Layout(mJugador);
	mLayout->CambiarColor(mAccionSeleccionada);

	mEnemigo->Actualizar();

	if (mEnemigo->Vida() <= 0) {
		system("cls");
		printf("-------------------------------------\nVICTORIA!\nHAS OBTENIDO %i DE ORO!\n-------------------------------------\n", mEnemigo->Recompensa());
		mJugador->RecuperarMana();
		mJugador->Recompensa(mEnemigo->Recompensa());
		mJugador->ResetiarTurno();
		mJugador->RecuperarVida100();
		mPeleaTerminada = true;
	}
	else if (mJugador->VidaRestante() <= 0) {
		mPeleaTerminada = true;
		printf("HAS SIDO DERROTADO\n");
	}

	if (!NotificarAtaque && !mPeleaTerminada) {
		NotificarAtaque = true;
		printf("-------------------------------------\nTURNO #%i\n-------------------------------------\n", mJugador->Turno());
		if (mJugador->Turno() % 3 == 0 && mJugador->Turno() != 0) {
			printf("-------------------------------------\nVA A SER ATACADO POR %i EN ESTE TURNO\n-------------------------------------\n", mEnemigo->Atacar() * 5);
		}
		else {
			printf("-------------------------------------\nVA A SER ATACADO POR %i EN ESTE TURNO\n-------------------------------------\n", mEnemigo->Atacar());
		}
		
	}

	if (mEntradas->TeclaPresionada(SDL_SCANCODE_RIGHT) && (mAccionSeleccionada != 3)) {
		CambiarAccion(1);
	}
	else if (mEntradas->TeclaPresionada(SDL_SCANCODE_LEFT) && (mAccionSeleccionada != 0)) {
		CambiarAccion(-1);
	}
	else if (mEntradas->TeclaPresionada(SDL_SCANCODE_DOWN) && (mAccionSeleccionada == 0 || mAccionSeleccionada == 1)) {
		CambiarAccion(2);
	}
	else if (mEntradas->TeclaPresionada(SDL_SCANCODE_UP) && (mAccionSeleccionada == 2 || mAccionSeleccionada == 3)) {
		CambiarAccion(-2);
	}

	if (mEntradas->TeclaPresionada(SDL_SCANCODE_RETURN)) {
		switch (mAccionSeleccionada) {
		case 0: // Ataque

			roll = rand() % 100;
			if (roll <= mJugador->ChanceCritico() * 100 + 10) {
				critico = true;
			}

			if (critico) {
				danio = mJugador->AtaqueFisico() * 2;
				printf("CRITICO!\n");
				critico = false;
			}
			else {
				danio = mJugador->AtaqueFisico();
			}

			if (mJugador->GetSFX()) {
				mAudio->PlaySFX("SFX/espada.mp3", 0, 0);
			}
			mEnemigo->ReducirVida(danio);
			printf("HAS ATACADO POR %i!\n", danio);
			if (mEnemigo->Vida() > 0) {
				if (mJugador->Turno() % 3 == 0 && mJugador->Turno() != 0) {
					danio = mEnemigo->Atacar() * 5;
				}
				else {
					danio = mEnemigo->Atacar();
				}
				printf("HAS SIDO ATACADO POR %i\n", danio);
				mJugador->ReducirVida(danio);
				NotificarAtaque = false;
			}
			break;

		case 1: // Defensa
			if (mJugador->Turno() % 3 == 0 && mJugador->Turno() != 0) {
				danio = mEnemigo->Atacar() * 5;
			}
			else {
				danio = mEnemigo->Atacar();
			}
			
			printf("TE HAS DEFENDIDO POR %i!\n", danio);
			NotificarAtaque = false;
			break;

		case 2: // Magia
			if (mJugador->Mana() > 0) {
				mAudio->PlaySFX("SFX/magia.wav", 0, 0);
				danio = rand() % mJugador->AtaqueFisico() + mJugador->AtaqueMagico();
				mEnemigo->ReducirVida(danio);
				mJugador->ReducirMana(10);
				printf("HAS ATACADO POR %i!\n", danio);
				if (mEnemigo->Vida() > 0) {
					if (mJugador->Turno() % 3 == 0 && mJugador->Turno() != 0) {
						danio = mEnemigo->Atacar() * 5;
					}
					else {
						danio = mEnemigo->Atacar();
					}
					printf("HAS SIDO ATACADO POR %i!\n", danio);
					mJugador->ReducirVida(danio);
					NotificarAtaque = false;
				}
			}
			else {
				printf("NO TIENE SUFICIENTE MANA!");
			}

			break;

		case 3: // Parry
			danio = mJugador->AtaqueFisico() / 2;
			mEnemigo->ReducirVida(danio);

			if (mJugador->GetSFX()) {
				mAudio->PlaySFX("SFX/espada.mp3", 0, 0);
			}

			printf("HAS ATACADO POR %i!\n", danio);
			if (mEnemigo->Vida() > 0) {
				if (mJugador->Turno() % 3 == 0 && mJugador->Turno() != 0) {
					danio = (mEnemigo->Atacar() * 5) / 3;
				}
				else {
					danio = mEnemigo->Atacar();
				}
				printf("HAS SIDO ATACADO POR %i\n", danio);
				mJugador->ReducirVida(danio);
				NotificarAtaque = false;
			}
			
			break;
		}
		mJugador->SiguienteTurno();
	}
}

void PantallaJefe::Renderizar() {

	mFondo->Renderizar();
	mLayout->Renderizar();
	mEnemigo->Renderizar();
	mJugador->Renderizar();
}