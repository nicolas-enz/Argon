#ifndef _PANTALLAJEFE_H
#define _PANTALLAJEFE_H
#include "Layout.h"
#include "Textura.h"
#include "EntidadJuego.h"
#include "AdminEntradas.h"
#include "AdminAudio.h"
#include "Enemigo.h"
#include "Jugador.h"

class PantallaJefe : public EntidadJuego {
	private:
		AdminEntradas* mEntradas;
		AdminAudio* mAudio;

		Layout* mLayout;
		Textura* mFondo;

		Enemigo* mEnemigo;
		Jugador* mJugador;
		bool mPeleaTerminada;
		int mAccionSeleccionada;

		bool NotificarAtaque;
		int danio;
		bool critico;
		float roll;

	public:

		PantallaJefe(Jugador* &jugador);
		~PantallaJefe();

		bool Terminada();

		void CambiarAccion(int cambio);

		void Actualizar();

		void Renderizar();
};
#endif