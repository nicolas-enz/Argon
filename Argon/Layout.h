#ifndef _LAYOUT_H
#define _LAYOUT_H
#include "Botones.h"
#include "Banner.h"
#include "BarraLateral.h"
#include "Opciones.h"
#include "EntidadJuego.h"

class Layout : public EntidadJuego {

	private:
		Botones* mBotones;
		Banner* mBanner;
		BarraLateral* mBarraLateral;
		Opciones* mOpciones;

		Jugador* mJugador;

	public:
		Layout(Jugador* &jugador);
		~Layout();

		void CambiarColor(int x);
		void Renderizar();
};

#endif