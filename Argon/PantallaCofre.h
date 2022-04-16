#ifndef _PANTALLACOFRE_H
#define _PANTALLACOFRE_H
#include "AdminEntradas.h"
#include "EntidadJuego.h"
#include "Textura.h"
#include "Layout.h"
#include "Jugador.h"

class PantallaCofre : public EntidadJuego {

	private: 
		Layout * mLayout;

		AdminEntradas* mEntradas;

		Textura* mFondo;
		Textura* mCofreCerrado;
		Textura* mCofreAbierto;
		Textura* mAbrirCofre;
		Textura* mSalir;

		int mOro;
		bool cofreAbierto;

		Jugador* mJugador;

public:

	PantallaCofre(Jugador* &jugador);
	~PantallaCofre();

	void Actualizar();

	void Renderizar();






};




#endif

