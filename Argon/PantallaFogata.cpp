#include "PantallaFogata.h"

PantallaFogata::PantallaFogata(Jugador* &jugador) {
	mJugador = jugador;

	mSeleccion = 0;
	AccionRealizada = false;

	mLayout = new Layout(mJugador);

	mEntradas = AdminEntradas::Instancia();
	mAudio = AdminAudio::Instancia();
	mAudio->Volumen();

	mFondo = new Textura("background/fogata_fondo.png");
	mFondo->Padre(this);
	mFondo->Pos(Vector2(400.0f, 300.0f));

	mFuerza = new Textura("AUMENTAR FUERZA +3", "fonts/OpenSans-ExtraBold.ttf", 15, { 50, 50, 180 });
	mFuerza->Padre(mFondo);
	mFuerza->Pos(Vector2(-210.0f, -150.0f));

	mVigor = new Textura("AUMENTAR VIGOR +3", "fonts/OpenSans-ExtraBold.ttf", 15, { 50,50,180 });
	mVigor->Padre(mFondo);
	mVigor->Pos(Vector2(-214.0f, -100.0f));

	mInteligencia = new Textura("AUMENTAR INTELIGENCIA +3", "fonts/OpenSans-ExtraBold.ttf", 15, { 50, 50, 180 });
	mInteligencia->Padre(mFondo);
	mInteligencia->Pos(Vector2(-185.0f, -50.0f));

	mDestreza = new Textura("AUMENTAR DESTREZA +3", "fonts/OpenSans-ExtraBold.ttf", 15, { 50, 50, 180 });
	mDestreza->Padre(mFondo);
	mDestreza->Pos(Vector2(-200.0f, 0.0f));

	mVida = new Textura("CURARSE 50%", "fonts/OpenSans-ExtraBold.ttf", 15, { 50, 50, 180 });
	mVida->Padre(mFondo);
	mVida->Pos(Vector2(-240.0f, 50.0f));

	mSalir = new Textura("SALIR (S)", "fonts/OpenSans-ExtraBold.ttf", 15, { 50, 50, 180 });
	mSalir->Padre(mFondo);
	mSalir->Pos(Vector2(-200.0f, 150.0f));

	mCursor = new Textura("cursor/cursor.png");
	mCursor->Padre(mFondo);
	mCursor->Pos(Vector2(-320.0f, -150.0f));

	mCursorOffset = Vector2(0.0f, 50.0f);
	mCursorPosInicial = mCursor->Pos(local);
}

PantallaFogata::~PantallaFogata() {

	mEntradas = NULL;
	mAudio = NULL;

	delete mLayout;
	mLayout = NULL;

	delete mFondo;
	mFondo = NULL;

	delete mFuerza;
	mFuerza = NULL;

	delete mVigor;
	mVigor = NULL;

	delete mInteligencia;
	mInteligencia = NULL;

	delete mDestreza;
	mDestreza = NULL;

	delete mVida;
	mVida = NULL;

	delete mSalir;
	mSalir = NULL;

	delete mCursor;
	mCursor = NULL;
}

void PantallaFogata::CambioSeleccion(int cambio) {
	mSeleccion += cambio;

	if (mSeleccion < 0) {
		mSeleccion = 4;
	}
	else if (mSeleccion > 4) {
		mSeleccion = 0;
	}
	mCursor->Pos(mCursorOffset * mSeleccion + mCursorPosInicial);
}

void PantallaFogata::Actualizar() {

	delete mLayout;
	mLayout = NULL;
	mLayout = new Layout(mJugador);

	if (mEntradas->TeclaPresionada(SDL_SCANCODE_DOWN)) {
		if (mJugador->GetSFX()) {
			mAudio->PlaySFX("SFX/normal.wav", 0, 0);
		}
		CambioSeleccion(1);
	}
	else if (mEntradas->TeclaPresionada(SDL_SCANCODE_UP)) {
		if (mJugador->GetSFX()) {
			mAudio->PlaySFX("SFX/normal.wav", 0, 0);
		}
		CambioSeleccion(-1);
	}

	if (mEntradas->TeclaPresionada(SDL_SCANCODE_RETURN)) {
		if (mJugador->GetSFX()) {
			mAudio->PlaySFX("SFX/normal.wav", 0, 0);
		}
		switch (mSeleccion) {
		case 0:
			if (!AccionRealizada) {
				AccionRealizada = true;
				for (int i = 0; i < 3; i++) {
					mJugador->AumentarFuerza();
				}
			}
			else {
				printf("YA REALIZO UNA ACCION.\n");
			}
			break;
		case 1:
			if (!AccionRealizada) {
				AccionRealizada = true;
				for (int i = 0; i < 3; i++) {
					mJugador->AumentarVigor();
				}
			}
			else {
				printf("YA REALIZO UNA ACCION.\n");
			}
			break;
		case 2:
			if (!AccionRealizada) {
				AccionRealizada = true;
				for (int i = 0; i < 3; i++) {
					mJugador->AumentarInteligencia();
				}
			}
			else {
				printf("YA REALIZO UNA ACCION.\n");
			}
			break;
		case 3:
			if (!AccionRealizada) {
				AccionRealizada = true;
				for (int i = 0; i < 3; i++) {
					mJugador->AumentarDestreza();
				}
			}
			else {
				printf("YA REALIZO UNA ACCION.\n");
			}
			break;
		case 4:
			if (!AccionRealizada) {
				AccionRealizada = true;
				mJugador->RecuperarVida50();
			}
			else {
				printf("YA REALIZO UNA ACCION.\n");
			}
			break;
		}
	}
}

void PantallaFogata::Renderizar() {

	mLayout->Renderizar();
	mFondo->Renderizar();

	mFuerza->Renderizar();
	mVigor->Renderizar();
	mInteligencia->Renderizar();
	mDestreza->Renderizar();
	mVida->Renderizar();

	mSalir->Renderizar();

	mCursor->Renderizar();
}