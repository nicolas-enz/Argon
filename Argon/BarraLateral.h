#ifndef _BARRALATERAL_H	
#define _BARRALATERAL_H
#include "EntidadJuego.h"
#include "Textura.h"
#include "Jugador.h"
#include "AyudaString.h"

class BarraLateral : public EntidadJuego {

	private:

		Jugador* mJugador;

		Textura* mFondo;
		Textura* mEstadisticas;

		Textura* mVida;
		Textura* mMana;
		Textura* mAtaque;
		Textura* mMagia;
		Textura* mChanceCrit;
		Textura* mVigor;
		Textura* mFuerza;
		Textura* mInteligencia;
		Textura* mDestreza;
		Textura* mOro;

	public:

		BarraLateral(Jugador* &jugador);
		~BarraLateral();

		void Actualizar();

		void Renderizar();

};

#endif
