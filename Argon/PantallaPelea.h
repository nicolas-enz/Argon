#ifndef _PANTALLAPELEA_H
#define _PANTALLAPELEA_H
#include <cstdlib>
#include <ctime>
#include "EntidadJuego.h"
#include "AdminAudio.h"
#include "AdminEntradas.h"
#include "Enemigo.h"
#include "Jugador.h"
#include "Layout.h"

class PantallaPelea : public EntidadJuego {

	private:

		AdminEntradas* mEntradas;
		AdminAudio* mAudio;

		Enemigo* mEnemigo;
		Jugador* mJugador;
		bool mPeleaTerminada;
		int mAccionSeleccionada;

		bool NotificarAtaque;
		int danio;
		bool critico;
		float roll;
		
		Textura* mFondo;

		Layout* mLayout;

	public:

		PantallaPelea(Jugador* &jugador);
		~PantallaPelea();

		bool Terminada();

		void CambiarAccion(int cambio);

		void Actualizar();
		void Renderizar();
};

#endif