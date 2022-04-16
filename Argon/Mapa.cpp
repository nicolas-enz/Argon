#include "Mapa.h"

Mapa::Mapa(int p) {

	int i = 0;

	mEntradas = AdminEntradas::Instancia();

	mFondo = new Textura("background/mapa.png");
	mFondo->Padre(this);
	mFondo->Pos(VEC2_ZERO);

	mPiso = new Piso();
	mPiso->InicializarPiso();
	mPiso->CambiarAccesibilidadTrue(0);

	for (int j = 0; j < 500; j += 50) {

		if (mPiso->GetNivel(i).getTipoNivel() == 1) {
			mNivel[i] = new Textura("sprites/enemigo.png");
		}
		else if (mPiso->GetNivel(i).getTipoNivel() == 2) {
			mNivel[i] = new Textura("sprites/tienda.png");
		}
		else if (mPiso->GetNivel(i).getTipoNivel() == 3) {
			mNivel[i] = new Textura("sprites/fogata.png");
		}
		else if (mPiso->GetNivel(i).getTipoNivel() == 4) {
			mNivel[i] = new Textura("sprites/cofre.png");
		}
		else if (mPiso->GetNivel(i).getTipoNivel() == 5) {
			mNivel[i] = new Textura("sprites/jefe.png");
		}
		mNivel[i]->Padre(this);
		mNivel[i]->Pos(Vector2(j - 250.0f, 0.0f));
		i++;
	}

	mCursor = new Textura("cursor/cursor.png");
	mCursor->Padre(this);
	mCursor->Pos(Vector2(-250.0f, -75.0f));
	mCursor->Rotar(90.0f);
	
	pi = new Textura("PISO #" + NumeroIntACadena(p+1), "fonts/OpenSans-ExtraBold.ttf", 30, { 0, 0, 0 });
	pi->Padre(this);
	pi->Pos(Vector2(0.0f, -200.0f));

	mCursorPosInicio = mCursor->Pos(local);
	mCursorOffset = Vector2(50.0f, 0.0f);
	mNivelSeleccionado = 0;
}

Mapa::~Mapa() {

	delete mFondo;
	mFondo = NULL;

	for (int i = 0; i < 10; i++) {
		delete mNivel[i];
		mNivel[i] = NULL;
	}

	delete mCursor;
	mCursor = NULL;
}

bool Mapa::Accesible() {

	return mPiso->Accesible(mNivelSeleccionado);
}

void Mapa::TrueNivelSeleccionado(int x) {

	mPiso->CambiarAccesibilidadTrue(mNivelSeleccionado+x);
}

void Mapa::FalseNivelSeleccionado(int x) {

	mPiso->CambiarAccesibilidadFalse(mNivelSeleccionado+x);
}

int Mapa::TipoNivelSeleccionado() {

	return mPiso->GetNivel(mNivelSeleccionado).getTipoNivel();
}

void Mapa::CambiarNivel(int cambio) {
	
	mNivelSeleccionado += cambio;

	if (mNivelSeleccionado < 0) {
		mNivelSeleccionado = 9;
	}
	else if (mNivelSeleccionado > 9) {
		mNivelSeleccionado = 0;
	}

	mCursor->Pos(mCursorPosInicio + mCursorOffset * mNivelSeleccionado);
}

void Mapa::Actualizar() {

	if (mEntradas->TeclaPresionada(SDL_SCANCODE_RIGHT)) {

		CambiarNivel(1);
	}
	else if (mEntradas->TeclaPresionada(SDL_SCANCODE_LEFT)) {

		CambiarNivel(-1);
	}
}

void Mapa::Renderizar() {

	int i = 0;
	mFondo->Renderizar();
	for (i = 0; i < 10; i++) {
		mNivel[i]->Renderizar();
	}
	pi->Renderizar();
	mCursor->Renderizar();
}