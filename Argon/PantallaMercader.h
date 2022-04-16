#ifndef _PANTALLAMERCADER_H
#define _PANTALLAMERCADER_H
#include "AdminEntradas.h"
#include "AdminAudio.h"
#include "EntidadJuego.h"
#include "Textura.h"
#include "Layout.h"
#include "AyudaString.h"
#include "Jugador.h"

class PantallaMercader : public EntidadJuego {

	private:

		Layout* mLayout;

		AdminEntradas* mEntradas;
		AdminAudio* mAudio;

		Textura* mFondo;
		Textura* mFuerza;
		Textura* mCostoFuerza;
		
		Textura* mVigor;
		Textura* mCostoVigor;
		
		Textura* mInteligencia;
		Textura* mCostoInteligencia;
		
		Textura* mDestreza;
		Textura* mCostoDestreza;

		Textura* mVida;
		Textura* mCostoVida;

		Textura* mSalir;
		Textura* mCosto;
		
		int CostoFuerza;
		int CostoVigor;
		int CostoInteligencia;
		int CostoDestreza;
		int CostoVida;
		int mStatSeleccionada;

		Textura* mCursor;
		Vector2 mCursorOffset;
		Vector2 mCursorPosInicial;

		Jugador* mJugador;

	public:

		PantallaMercader(Jugador* &jugador);
		~PantallaMercader();

		void CambioStat(int cambio);
		void MoverCursor();

		void Actualizar();

		void Renderizar();
};


#endif