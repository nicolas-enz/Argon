#include "PantallaPelea.h"

PantallaPelea::PantallaPelea(Jugador* &jugador) {
	int x;
	mEntradas = AdminEntradas::Instancia();
	mAudio = AdminAudio::Instancia();
	mAudio->Volumen();
	mJugador = jugador;

	mAccionSeleccionada = 0;

	NotificarAtaque = false;
	mPeleaTerminada = false;

	mLayout = new Layout(mJugador);

	mFondo = new Textura("background/pelea.png");
	mFondo->Padre(this);
	mFondo->Pos(Vector2(400.0f, 300.0f));

	x = rand() % 7;
	if (mJugador->Piso() == 0) {
		switch (x) {
			case 0:
				x = rand() % 50 + 30;
				mEnemigo = new Enemigo(50, 10, x, "sprites/0.png");
				break;
			case 1:
				x = rand() % 50 + 70;
				mEnemigo = new Enemigo(72, 12, x, "sprites/1.png");
				break;
			case 2:
				x = rand() % 50 + 50;
				mEnemigo = new Enemigo(65, 11, x, "sprites/2.png");
				break;
			case 3:
				x = rand() % 50 + 50;
				mEnemigo = new Enemigo(83, 12, x, "sprites/3.png");
				break;
			case 4:
				x = rand() % 50 + 60;
				mEnemigo = new Enemigo(91, 13, x, "sprites/4.png");
				break;
			case 5:
				x = rand() % 50 + 60;
				mEnemigo = new Enemigo(85, 10, x, "sprites/5.png");
				break;
			case 6:
				x = rand() % 50 + 75;
				mEnemigo = new Enemigo(110, 14, x, "sprites/6.png");
				break;
		}
	}
	else if (mJugador->Piso() == 1) {
		switch (x) {
			case 0:
				x = rand() % 50 + 30;
				mEnemigo = new Enemigo(50*2, 7*2, x, "sprites/0.png");
				break;
			case 1:
				x = rand() % 50 + 70;
				mEnemigo = new Enemigo(72*2, 9*2, x, "sprites/1.png");
				break;
			case 2:
				x = rand() % 50 + 50;
				mEnemigo = new Enemigo(65*2, 8*2, x, "sprites/2.png");
				break;
			case 3:
				x = rand() % 50 + 50;
				mEnemigo = new Enemigo(83*2, 9*2, x, "sprites/3.png");
				break;
			case 4:
				x = rand() % 50 + 60;
				mEnemigo = new Enemigo(91*2, 10*2, x, "sprites/4.png");
				break;
			case 5:
				x = rand() % 50 + 60;
				mEnemigo = new Enemigo(85*2, 7*2, x, "sprites/5.png");
				break;
			case 6:
				x = rand() % 50 + 75;
				mEnemigo = new Enemigo(110*2, 8*2, x, "sprites/6.png");
				break;
		}
	}
	else if (mJugador->Piso() == 2) {
		switch (x) {
			case 0:
				x = rand() % 50 + 30;
				mEnemigo = new Enemigo(50 * 4, 7 * 3, x, "sprites/0.png");
				break;
			case 1:
				x = rand() % 50 + 70;
				mEnemigo = new Enemigo(72 * 4, 9 * 3, x, "sprites/1.png");
				break;
			case 2:
				x = rand() % 50 + 50;
				mEnemigo = new Enemigo(65 * 4, 8 * 3, x, "sprites/2.png");
				break;
			case 3:
				x = rand() % 50 + 50;
				mEnemigo = new Enemigo(83 * 4, 9 * 3, x, "sprites/3.png");
				break;
			case 4:
				x = rand() % 50 + 60;
				mEnemigo = new Enemigo(91 * 4, 10 * 3, x, "sprites/4.png");
				break;
			case 5:
				x = rand() % 50 + 60;
				mEnemigo = new Enemigo(85 * 4, 7 * 3, x, "sprites/5.png");
				break;
			case 6:
				x = rand() % 50 + 75;
				mEnemigo = new Enemigo(110 * 4, 8 * 3, x, "sprites/6.png");
				break;
		}
	}
	
}

PantallaPelea::~PantallaPelea() {

	mEntradas = NULL;
	mAudio = NULL;

	delete mLayout;
	mLayout = NULL;
	
	delete mFondo;
	mFondo = NULL;

	delete mEnemigo;
	mEnemigo = NULL;
}

bool PantallaPelea::Terminada() {

	return mPeleaTerminada;
}

void PantallaPelea::CambiarAccion(int cambio) {

	mAccionSeleccionada += cambio;

	if (mAccionSeleccionada < 0) {
		mAccionSeleccionada = 3;
	}
	else if (mAccionSeleccionada > 3) {
		mAccionSeleccionada = 0;
	}

	mLayout->CambiarColor(mAccionSeleccionada);
}

void PantallaPelea::Actualizar() {
	
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
		mPeleaTerminada = true;
	}
	else if (mJugador->VidaRestante() <= 0) {
		mPeleaTerminada = true;
		printf("HAS SIDO DERROTADO\n");
	}

	if (!NotificarAtaque && !mPeleaTerminada) {
		NotificarAtaque = true;
		printf("-------------------------------------\nTURNO #%i\n-------------------------------------\n", mJugador->Turno());
		printf("-------------------------------------\nVA A SER ATACADO POR %i EN ESTE TURNO\n-------------------------------------\n", mEnemigo->Atacar());
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
		mJugador->SiguienteTurno();
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
					danio = mEnemigo->Atacar();
					printf("HAS SIDO ATACADO POR %i\n", danio);
					mJugador->ReducirVida(danio);
					NotificarAtaque = false;
				}
				break;

			case 1: // Defensa
				danio = mEnemigo->Atacar() *0.1;
				printf("TE HAS DEFENDIDO POR %i!\n", mEnemigo->Atacar() * 8 / 10);
				printf("HAS SIDO ATACADO POR %i!\n", mEnemigo->Atacar() * 2 / 10);
				mJugador->ReducirVida(danio);
				NotificarAtaque = false;
				break;

			case 2: // Magia
				if (mJugador->Mana() - 10 >= 0) {
					if (mJugador->GetSFX()) {
						mAudio->PlaySFX("SFX/magia.wav", 0, 0);
					}
					danio = rand() % mJugador->AtaqueMagico() + (mJugador->AtaqueFisico() / 2);
					mEnemigo->ReducirVida(danio);
					mJugador->ReducirMana(10);
					printf("HAS ATACADO POR %i!\n", danio);
					if (mEnemigo->Vida() > 0) {
						danio = mEnemigo->Atacar();
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
					danio = mEnemigo->Atacar()/3;
					printf("HAS SIDO ATACADO POR %i\n", danio);
					mJugador->ReducirVida(danio);
					NotificarAtaque = false;
				}
				break;
		}
	}
}

void PantallaPelea::Renderizar() {

	mFondo->Renderizar();
	mLayout->Renderizar();
	mEnemigo->Renderizar();
	mJugador->Renderizar();
}