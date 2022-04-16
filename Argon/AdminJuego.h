#ifndef _ADMINJUEGO_H
#define _ADMINJUEGO_H
#include "AdminAudio.h"
#include "Temporizador.h"
#include "AdminPantalla.h"

class AdminJuego {
	
	private:

		static AdminJuego* sInstancia;

		const int FRAME_RATE = 60;

		bool mSalir;
		Graficos* mGraficos;
		AdminBienes* mAdminBienes;
		AdminEntradas* mAdminEntradas;
		AdminAudio* mAdminAudio;

		Temporizador* mTemporizador;

		SDL_Event mEventos;

		AdminPantalla* mAdminPantalla;

	public:

		static AdminJuego* Instancia();
		static void Liberar();

		void Correr();
	
	private:

		AdminJuego();
		~AdminJuego();

		void ActualizacionTemprana();
		void Actualizacion();
		void ActualizacionTardia();

		void Renderizar();
};

#endif