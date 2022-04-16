#include "PantallaOpciones.h"

PantallaOpciones::PantallaOpciones(Jugador* &jugador) {

	mJugador = jugador;

	mTimer = Temporizador::Instancia();
	mEntradas = AdminEntradas::Instancia();
	mAudio = AdminAudio::Instancia();
	mAudio->Volumen();

	mOpciones = new EntidadJuego(Graficos::Instancia()->ANCHO_PANTALLA*0.5f, Graficos::Instancia()->ALTO_PANTALLA*0.25f);
	mTitulo = new Textura("Opciones", "fonts/emulogic.ttf", 50, { 200, 50, 100 });
	mSFX = new Textura("SFX:    ON", "fonts/emulogic.ttf", 30, { 230, 230, 230 });
	mMusica = new Textura("Musica:  ON", "fonts/emulogic.ttf", 30, { 230, 230, 230 });
	mCursor = new Textura("cursor/cursor.png");

	mTitulo->Padre(mOpciones);
	mSFX->Padre(mOpciones);
	mMusica->Padre(mOpciones);
	mCursor->Padre(mOpciones);

	mTitulo->Pos(VEC2_ZERO);
	mSFX->Pos(Vector2(0.0f, 170.0f));
	mMusica->Pos(Vector2(0.0f, 250.0f));
	mCursor->Pos(Vector2(-180.0f, 170.0f));

	mCursorPosInicio = mCursor->Pos(local);
	mCursorOffset = Vector2(0.0f, 80.0f);

	mOpciones->Padre(this);
}

PantallaOpciones::PantallaOpciones(Jugador* &jugador, AdminAudio* &musica) {

	mJugador = jugador;

	mTimer = Temporizador::Instancia();
	mEntradas = AdminEntradas::Instancia();
	mAudio = AdminAudio::Instancia();
	mAudio->Volumen();
	mAudioMusica = musica;

	mOpciones = new EntidadJuego(Graficos::Instancia()->ANCHO_PANTALLA*0.5f, Graficos::Instancia()->ALTO_PANTALLA*0.25f);
	mTitulo = new Textura("Opciones", "fonts/emulogic.ttf", 50, { 200, 50, 100 });
	mSFX = new Textura("SFX:    ON", "fonts/emulogic.ttf", 30, { 230, 230, 230 });
	mMusica = new Textura("Musica:  ON", "fonts/emulogic.ttf", 30, { 230, 230, 230 });
	mCursor = new Textura("cursor/cursor.png");

	mTitulo->Padre(mOpciones);
	mSFX->Padre(mOpciones);
	mMusica->Padre(mOpciones);
	mCursor->Padre(mOpciones);

	mTitulo->Pos(VEC2_ZERO);
	mSFX->Pos(Vector2(0.0f, 170.0f));
	mMusica->Pos(Vector2(0.0f, 250.0f));
	mCursor->Pos(Vector2(-180.0f, 170.0f));

	mCursorPosInicio = mCursor->Pos(local);
	mCursorOffset = Vector2(0.0f, 80.0f);

	mOpciones->Padre(this);
}

PantallaOpciones::~PantallaOpciones() {

	mTimer = NULL;
	mEntradas = NULL;
	mAudio = NULL;
}

void PantallaOpciones::MoverCursor(int cambio) {
	
	mModoSeleccionado += cambio;

	if (mModoSeleccionado < 0) {
		mModoSeleccionado = 1;
	}
	else if (mModoSeleccionado > 1) {
		mModoSeleccionado = 0;
	}

	mCursor->Pos(mCursorPosInicio + mCursorOffset * mModoSeleccionado);
}

void PantallaOpciones::CambiarAudio(int cambio) {

	if (mModoSeleccionado == 0) {
		if (cambio == 0) {
			mJugador->SFXOFF();
			delete mSFX;
			mSFX = NULL;
			mSFX = new Textura("SFX:   OFF", "fonts/emulogic.ttf", 30, { 230, 230, 230 });
			mSFX->Padre(mOpciones);
			mSFX->Pos(Vector2(0.0f, 170.0f));
		}
		else if (cambio == 1) {
			mJugador->SFXON();
			delete mSFX;
			mSFX = NULL;
			mSFX = new Textura("SFX:    ON", "fonts/emulogic.ttf", 30, { 230, 230, 230 });
			mSFX->Padre(mOpciones);
			mSFX->Pos(Vector2(0.0f, 170.0f));
		}
	}
	else if (mModoSeleccionado == 1) {
		if (cambio == 0) {
			mJugador->MusicaOFF();
			mAudioMusica->PausarMusica();
			delete mMusica;
			mMusica = NULL;
			mMusica = new Textura("Musica: OFF", "fonts/emulogic.ttf", 30, { 230, 230, 230 });
			mMusica->Padre(mOpciones);
			mMusica->Pos(Vector2(0.0f, 250.0f));
		}
		else if (cambio == 1) {
			mJugador->MusicaON();
			mAudio->ResumirMusica();
			delete mMusica;
			mMusica = NULL;
			mMusica = new Textura("Musica:  ON", "fonts/emulogic.ttf", 30, { 230, 230, 230 });
			mMusica->Padre(mOpciones);
			mMusica->Pos(Vector2(0.0f, 250.0f));
		}
	}
}

void PantallaOpciones::Actualizar() {

	if (mEntradas->TeclaPresionada(SDL_SCANCODE_DOWN)) {

		MoverCursor(1);
	}
	else if (mEntradas->TeclaPresionada(SDL_SCANCODE_UP)) {

		MoverCursor(-1);
	}
	else if (mEntradas->TeclaPresionada(SDL_SCANCODE_RIGHT)) {

		CambiarAudio(0);
	}
	else if (mEntradas->TeclaPresionada(SDL_SCANCODE_LEFT)) {
		CambiarAudio(1);
	}
}

void PantallaOpciones::Renderizar() {

	mTitulo->Renderizar();
	mSFX->Renderizar();
	mMusica->Renderizar();
	mCursor->Renderizar();
}