#include "PantallaMapa.h"

PantallaMapa::PantallaMapa(Jugador* &jugador) {
	
	NivelTerminado = false;

	mJugador = jugador;

	mEntradas = AdminEntradas::Instancia();
	mAudio = AdminAudio::Instancia();

	mLayout = new Layout(mJugador);
	
	mMapa = new Mapa(mJugador->Piso());
	mMapa->Padre(this);
	mMapa->Pos(Vector2(400.0f, 300.0f));

}

PantallaMapa::~PantallaMapa() {

	mEntradas = NULL;
	mAudio = NULL;

	delete mLayout;
	mLayout = NULL;

	delete mMapa;
	mMapa = NULL;
}

bool PantallaMapa::Accesible() {

	return mMapa->Accesible();
}

void PantallaMapa::CambiarAccesibilidad() {

	mMapa->FalseNivelSeleccionado(0);
	mMapa->TrueNivelSeleccionado(1);
}

int PantallaMapa::TipoNivelSeleccionado() {
	
	return mMapa->TipoNivelSeleccionado();
}

void PantallaMapa::CambiarEstadoNivel() {

	NivelTerminado = true;
}

void PantallaMapa::Actualizar() {

	delete mLayout;
	mLayout = NULL;
	mLayout = new Layout(mJugador);

	mMapa->Actualizar();

	if (NivelTerminado) {

		NivelTerminado = false;
	}
}

void PantallaMapa::Renderizar() {

	mLayout->Renderizar();
	mMapa->Renderizar();
}