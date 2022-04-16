#include "AdminJuego.h"

AdminJuego* AdminJuego::sInstancia = NULL;

AdminJuego* AdminJuego::Instancia() {
	
	if (sInstancia == NULL) {
		sInstancia = new AdminJuego();
	}

	return sInstancia;
}

void AdminJuego::Liberar() {
	
	delete sInstancia;
	sInstancia = NULL;
}

AdminJuego::AdminJuego() {
	mSalir = false;

	mGraficos = Graficos::Instancia();

	if (!Graficos::Inicializado()) {
		mSalir = true;
	}

	mAdminBienes = AdminBienes::Instancia();

	mAdminEntradas = AdminEntradas::Instancia();

	mAdminAudio = AdminAudio::Instancia();

	mTemporizador = Temporizador::Instancia();

	mAdminPantalla = AdminPantalla::Instancia();
}

AdminJuego::~AdminJuego() {
	

	AdminPantalla::Liberar();
	mAdminPantalla = NULL;

	AdminAudio::Liberar();
	mAdminAudio = NULL;

	AdminBienes::Liberar();
	mAdminBienes = NULL;

	Graficos::Liberar();
	mGraficos = NULL;

	Temporizador::Liberar;
	mTemporizador = NULL;

	AdminEntradas::Liberar();
	mAdminEntradas = NULL;
}

void AdminJuego::ActualizacionTemprana() {

	mAdminEntradas->Actualizar();

}

void AdminJuego::Actualizacion() {
	mAdminPantalla->Actualizar();
}

void AdminJuego::ActualizacionTardia() {

	mAdminEntradas->ActualizarInputPrevio();
	mTemporizador->Resetear();
}

void AdminJuego::Renderizar() {

	mGraficos->LimpiarBuffer();

	mAdminPantalla->Renderizar();

	mGraficos->Renderizar();
}

void AdminJuego::Correr() {
	
	while (!mSalir) {

		mTemporizador->Actualizar();

		while (SDL_PollEvent(&mEventos) != 0) {

			if (mEventos.type == SDL_QUIT) {
				mSalir = true;
			}
		}
		if (mTemporizador->TiempoDelta() >= 1.0f / FRAME_RATE) {

			ActualizacionTemprana();

			Actualizacion();

			ActualizacionTardia();

			Renderizar();
		}
	}
}