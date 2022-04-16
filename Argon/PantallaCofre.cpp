#include "PantallaCofre.h"


PantallaCofre::PantallaCofre(Jugador* &jugador) {
	cofreAbierto = false;
	mJugador = jugador;

	mOro = rand() % 20 + 70;

	mLayout = new Layout(mJugador);

	mEntradas = AdminEntradas::Instancia();

	mFondo = new Textura("background/mapa.png");
	mFondo->Padre(this);
	mFondo->Pos(Vector2(400.0f, 300.0f));

	mCofreCerrado = new Textura("sprites/cofre_cerrado.png");
	mCofreCerrado->Padre(mFondo);
	mCofreCerrado->Pos(VEC2_ZERO);

	mAbrirCofre = new Textura("ABRIR COFRE (ENTER)","fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
	mAbrirCofre->Padre(mCofreCerrado);
	mAbrirCofre->Pos(Vector2(0.0f, 100.0f));

	mCofreAbierto = new Textura("sprites/cofre_abierto.png");
	mCofreAbierto->Padre(mFondo);
	mCofreAbierto->Pos(Vector2(1.0f,-20.0f));

	mSalir = new Textura("SALIR (S)", "fonts/OpenSans-ExtraBold.ttf", 25, { 50, 50, 180 });
	mSalir->Padre(mCofreAbierto);
	mSalir->Pos(Vector2(-1.0f, 120.0f));
}

PantallaCofre::~PantallaCofre() {

	delete mFondo;
	mFondo = NULL;

	delete mCofreCerrado;
	mCofreCerrado = NULL;

	delete mAbrirCofre;
	mAbrirCofre = NULL;

	delete mSalir;
	mSalir = NULL;
}

void PantallaCofre::Actualizar() {
	delete mLayout;
	mLayout = NULL;
	mLayout = new Layout(mJugador);

	if (mEntradas->TeclaPresionada(SDL_SCANCODE_RETURN) && cofreAbierto == false) {

		cofreAbierto = true;
		printf("-------------------------------------\nHAS OBTENIDO %i ORO\n-------------------------------------\n", mOro);
		mJugador->Recompensa(mOro);
	}
}

void PantallaCofre::Renderizar() {

	mFondo->Renderizar();
	mLayout->Renderizar();
	
	if (!cofreAbierto) {
		mCofreCerrado->Renderizar();
		mAbrirCofre->Renderizar();
	}
	else {
		mCofreAbierto->Renderizar();
		mSalir->Renderizar();
	}
}