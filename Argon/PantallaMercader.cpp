#include "PantallaMercader.h"

PantallaMercader::PantallaMercader(Jugador* &jugador) {

	CostoFuerza = 50;
	CostoVigor = 50;
	CostoInteligencia = 50;
	CostoDestreza = 50;
	CostoVida = 30;
	mStatSeleccionada = 0;

	mJugador = jugador;

	mLayout = new Layout(mJugador);

	mEntradas = AdminEntradas::Instancia();
	mAudio = AdminAudio::Instancia();
	mAudio->Volumen();

	mFondo = new Textura("background/mapa.png");
	mFondo->Padre(this);
	mFondo->Pos(Vector2(400.0f, 300.0f));
	
	mFuerza = new Textura("AUMENTAR FUERZA", "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
	mFuerza->Padre(mFondo);
	mFuerza->Pos(Vector2(-142.0f, -150.0f));

	mCostoFuerza = new Textura(NumeroIntACadena(CostoFuerza), "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
	mCostoFuerza->Padre(mFondo);
	mCostoFuerza->Pos(Vector2(300.0f, -150.0f));

	mVigor = new Textura("AUMENTAR VIGOR", "fonts/OpenSans-ExtraBold.ttf", 25, { 50,50,180 });
	mVigor->Padre(mFondo);
	mVigor->Pos(Vector2(-149.0f,-100.0f));

	mCostoVigor = new Textura(NumeroIntACadena(CostoVigor), "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
	mCostoVigor->Padre(mFondo);
	mCostoVigor->Pos(Vector2(300.0f, -100.0f));

	mInteligencia = new Textura("AUMENTAR INTELIGENCIA", "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
	mInteligencia->Padre(mFondo);
	mInteligencia->Pos(Vector2(-100.0f, -50.0f));

	mCostoInteligencia = new Textura(NumeroIntACadena(CostoInteligencia), "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
	mCostoInteligencia->Padre(mFondo);
	mCostoInteligencia->Pos(Vector2(300.0f, -50.0f));

	mDestreza = new Textura("AUMENTAR DESTREZA", "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
	mDestreza->Padre(mFondo);
	mDestreza->Pos(Vector2(-128.0f, 0.0f));

	mCostoDestreza = new Textura(NumeroIntACadena(CostoDestreza), "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
	mCostoDestreza->Padre(mFondo);
	mCostoDestreza->Pos(Vector2(300.0f, 0.0f));

	mVida = new Textura("CURARSE 30% DE LA VIDA MAXIMA", "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
	mVida->Padre(mFondo);
	mVida->Pos(Vector2(-45.0f, 50.0f));

	mCostoVida = new Textura(NumeroIntACadena(CostoVida), "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
	mCostoVida->Padre(mFondo);
	mCostoVida->Pos(Vector2(300.0f, 50.0f));

	mCosto = new Textura("COSTO", "fonts/OpenSans-ExtraBold.ttf", 25, { 50,50,180 });
	mCosto->Padre(mFondo);
	mCosto->Pos(Vector2(300.f, -200.0f));

	mSalir = new Textura("SALIR (S)", "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
	mSalir->Padre(mFondo);
	mSalir->Pos(Vector2(0.0f, 150.0f));

	mCursor = new Textura("cursor/cursor.png");
	mCursor->Padre(mFondo);
	mCursor->Pos(Vector2(-300.0f, -150.0f));

	mCursorOffset = Vector2(0.0f, 50.0f);
	mCursorPosInicial = mCursor->Pos(local);
}

PantallaMercader::~PantallaMercader() {

	delete mFondo;
	mFondo = NULL;

	delete mFuerza;
	mFuerza = NULL;

	delete mCostoFuerza;
	mCostoFuerza = NULL;

	delete mVigor;
	mVigor = NULL;

	delete mCostoVigor;
	mCostoVigor = NULL;

	delete mInteligencia;
	mInteligencia = NULL;

	delete mCostoInteligencia;
	mCostoInteligencia = NULL;

	delete mDestreza;
	mDestreza = NULL;

	delete mCostoDestreza;
	mCostoDestreza = NULL;

	delete mVida;
	mVida = NULL;

	delete mCostoVida;
	mCostoVida = NULL;

	delete mCosto;
	mCosto = NULL;

	delete mSalir;
	mSalir = NULL;

	delete mCursor;
	mCursor = NULL;
}


void PantallaMercader::CambioStat(int cambio) {

	mStatSeleccionada += cambio;

	if (mStatSeleccionada < 0) {
		mStatSeleccionada = 4;
	}
	else if (mStatSeleccionada > 4) {
		mStatSeleccionada = 0;
	}
	mCursor->Pos(mCursorOffset * mStatSeleccionada + mCursorPosInicial);
}

void PantallaMercader::MoverCursor() {

	if (mEntradas->TeclaPresionada(SDL_SCANCODE_DOWN)) {
		if (mJugador->GetSFX()) {
			mAudio->PlaySFX("SFX/normal.wav", 0, 0);
		}
		CambioStat(1);
	}
	else if (mEntradas->TeclaPresionada(SDL_SCANCODE_UP)) {
		if (mJugador->GetSFX()) {
			mAudio->PlaySFX("SFX/normal.wav", 0, 0);
		}
		CambioStat(-1);
	}

	if (mEntradas->TeclaPresionada(SDL_SCANCODE_RETURN)) {
		if (mJugador->GetSFX()) {
			mAudio->PlaySFX("SFX/normal.wav", 0, 0);
		}
		switch (mStatSeleccionada) {
		case 0:
				if (mJugador->Oro() - CostoFuerza >= 0) {
					mJugador->AumentarFuerza();
					mJugador->ReducirOro(CostoFuerza);
					CostoFuerza += 5;

					delete mCostoFuerza;
					mCostoFuerza = NULL;
					mCostoFuerza = new Textura(NumeroIntACadena(CostoFuerza), "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
					mCostoFuerza->Padre(mFondo);
					mCostoFuerza->Pos(Vector2(300.0f, -150.0f));
				}
				else {
					printf("NO TIENE SUFICIENTE ORO!\n");
				}
				break;
			case 1:
				if (mJugador->Oro() - CostoVigor >= 0) {
					mJugador->AumentarVigor();
					mJugador->ReducirOro(CostoVigor);
					CostoVigor += 5;

					delete mCostoVigor;
					mCostoVigor = NULL;
					mCostoVigor = new Textura(NumeroIntACadena(CostoVigor), "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
					mCostoVigor->Padre(mFondo);
					mCostoVigor->Pos(Vector2(300.0f, -100.0f));
				}
				else {
					printf("NO TIENE SUFICIENTE ORO!\n");
				}
				break;
			case 2:
				if(mJugador->Oro() - CostoInteligencia >= 0){
					mJugador->AumentarInteligencia();
					mJugador->ReducirOro(CostoInteligencia);
					CostoInteligencia += 5;

					delete mCostoInteligencia;
					mCostoInteligencia = NULL;
					mCostoInteligencia = new Textura(NumeroIntACadena(CostoInteligencia), "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
					mCostoInteligencia->Padre(mFondo);
					mCostoInteligencia->Pos(Vector2(300.0f, -50.0f));
				}
				else {
					printf("NO TIENE SUFICIENTE ORO!\n");
				}
				break;
			case 3:
				if(mJugador->Oro() - CostoDestreza >= 0){
					mJugador->AumentarDestreza();
					mJugador->ReducirOro(CostoDestreza);
					CostoDestreza += 5;

					delete mCostoDestreza;
					mCostoDestreza = NULL;
					mCostoDestreza = new Textura(NumeroIntACadena(CostoDestreza), "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
					mCostoDestreza->Padre(mFondo);
					mCostoDestreza->Pos(Vector2(300.0f, 0.0f));
				}
				else {
					printf("NO TIENE SUFICIENTE ORO!\n");
				}
				break;
			case 4:
				if (mJugador->VidaRestante() == mJugador->Vida()) {
					printf("VIDA AL MAXIMO.\n");
				}
				else if (mJugador->Oro() - CostoVida >= 0) {
					mJugador->RecuperarVida30();
					mJugador->ReducirOro(CostoVida);
					CostoVida += 5;

					delete mCostoVida;
					mCostoVida = NULL;
					mCostoVida = new Textura(NumeroIntACadena(CostoVida), "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
					mCostoVida->Padre(mFondo);
					mCostoVida->Pos(Vector2(300.0f, 50.0f));
				}
				else{
					printf("NO TIENE SUFICIENTE ORO!\n");
				}
				break;
		}
	}
}


void PantallaMercader::Actualizar() {

	delete mLayout;
	mLayout = NULL;
	mLayout = new Layout(mJugador);

	MoverCursor();
}

void PantallaMercader::Renderizar() {

	mFondo->Renderizar();
	mLayout->Renderizar();
	mFuerza->Renderizar();
	mCostoFuerza->Renderizar();
	mVigor->Renderizar();
	mCostoVigor->Renderizar();
	mInteligencia->Renderizar();
	mCostoInteligencia->Renderizar();
	mDestreza->Renderizar();
	mCostoDestreza->Renderizar();
	mVida->Renderizar();
	mCostoVida->Renderizar();
	mCosto->Renderizar();
	mCursor->Renderizar();
	mSalir->Renderizar();
}