#include "PantallaInicio.h"

PantallaInicio::PantallaInicio() {

	mTemporizador = Temporizador::Instancia();
	mEntrada = AdminEntradas::Instancia();

	//Top Bar Entidades
	mTopBar = new EntidadJuego(Graficos::Instancia()->ANCHO_PANTALLA*0.5f, 80.0f);
	mTitulo = new Textura("ARGON", "fonts/emulogic.ttf", 100, { 200, 50, 100 });

	mTitulo->Padre(mTopBar);

	mTitulo->Pos(VEC2_ZERO);

	mTopBar->Padre(this);
	
	//Middle Bar Entidades
	mModoJuego = new EntidadJuego(Graficos::Instancia()->ANCHO_PANTALLA*0.5f, Graficos::Instancia()->ALTO_PANTALLA*0.50f);
	mNuevoJuego = new Textura("Nuevo Juego", "fonts/emulogic.ttf", 25, { 230, 230, 230 });
	mOpciones = new Textura("Opciones", "fonts/emulogic.ttf", 25, { 230, 230, 230 });
	mSalir = new Textura("Salir", "fonts/emulogic.ttf", 25, { 230, 230, 230 });
	mCursor = new Textura("cursor/cursor.png");

	mNuevoJuego->Padre(mModoJuego);
	mOpciones->Padre(mModoJuego);
	mSalir->Padre(mModoJuego);
	mCursor->Padre(mModoJuego);

	mNuevoJuego->Pos(Vector2(0.0f, -60.0f));
	mOpciones->Pos(VEC2_ZERO);
	mSalir->Pos(Vector2(0.0f, 60.0f));
	mCursor->Pos(Vector2(-175.0f, -60.0f));

	mModoJuego->Padre(this);

	mCursorPosInicio = mCursor->Pos(local);
	mCursorOffset = Vector2(0.0f, 60.0f);
	mModoSeleccionado = 0;

	//Bottom Bar Entidades
	mBottom = new EntidadJuego(Graficos::Instancia()->ANCHO_PANTALLA*0.5f, Graficos::Instancia()->ALTO_PANTALLA*0.90f);
	mFecha = new Textura("JULIO 2018", "fonts/emulogic.ttf", 15, { 230, 230, 230 });
	mParticipantes = new Textura("Estrada - Gaddi", "fonts/emulogic.ttf", 15, { 230, 230, 230 });

	mFecha->Padre(mBottom);
	mParticipantes->Padre(mBottom);

	mFecha->Pos(Vector2(-350.0f, 0.0f));
	mParticipantes->Pos(Vector2(350.0f, 0.0f));

	mBottom->Padre(this);

	// Screen Animation Variables
	ResetearAnimacion();
}

PantallaInicio::~PantallaInicio() {

	//Freeing Top Bar Entidades
	delete mTopBar;
	mTopBar = NULL;
	delete mTitulo;
	mTitulo = NULL;

	//Freeing Middle Bar Entidades
	delete mModoJuego;
	mModoJuego = NULL;
	delete mNuevoJuego;
	mNuevoJuego = NULL;
	delete mOpciones;
	mOpciones = NULL;
	delete mSalir;
	mSalir = NULL;
	delete mCursor;
	mCursor = NULL;

	//Freeing Bottom Bar Entidades
	delete mBottom;
	mBottom = NULL;
	delete mFecha;
	mFecha = NULL;
	delete mParticipantes;
	mParticipantes = NULL;
}

void PantallaInicio::ResetearAnimacion() {

	mAnimacionStartPos = Vector2(0.0f, Graficos::Instancia()->ALTO_PANTALLA*1.0f);
	mAnimacionEndPos = VEC2_ZERO;
	mAnimacionTotalTime = 2.5f;
	mAnimacionTemporizador = 0.0f;
	mAnimacionDone = false;

	Pos(mAnimacionStartPos);
}

int PantallaInicio::ModoSeleccionado() {

	return mModoSeleccionado;
}

void PantallaInicio::CambiarModoSeleccionado(int cambio) {
	
	mModoSeleccionado += cambio;
	
	if (mModoSeleccionado < 0) {
		mModoSeleccionado = 2;
	}
	else if (mModoSeleccionado > 2) {
		mModoSeleccionado = 0;
	}

	mCursor->Pos(mCursorPosInicio + mCursorOffset * mModoSeleccionado);
}

void PantallaInicio::Actualizar() {

	if (!mAnimacionDone) {

		mAnimacionTemporizador += mTemporizador->TiempoDelta();
		Pos(Lerp(mAnimacionStartPos, mAnimacionEndPos, mAnimacionTemporizador / mAnimacionTotalTime));

		if (mAnimacionTemporizador >= mAnimacionTotalTime) {
			
			mAnimacionDone = true;
		}

		if (mEntrada->TeclaPresionada(SDL_SCANCODE_DOWN) || mEntrada->TeclaPresionada(SDL_SCANCODE_UP)) {

			mAnimacionTemporizador = mAnimacionTotalTime;
		}
	}
	else {

		if (mEntrada->TeclaPresionada(SDL_SCANCODE_DOWN)) {
			
			CambiarModoSeleccionado(1);
		}
		else if (mEntrada->TeclaPresionada(SDL_SCANCODE_UP)) {
			
			CambiarModoSeleccionado(-1);
		}
	}
}

void PantallaInicio::Renderizar() {

	mTitulo->Renderizar();

	mNuevoJuego->Renderizar();
	mOpciones->Renderizar();
	mSalir->Renderizar();
	mCursor->Renderizar();

	mFecha->Renderizar();
	mParticipantes->Renderizar();
}