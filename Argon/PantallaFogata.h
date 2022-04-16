#ifndef _PANTALLAFOGATA_H
#define _PANTALLAFOGATA_H
#include "Layout.h"
#include "Textura.h"
#include "EntidadJuego.h"
#include "AdminEntradas.h"
#include "AdminAudio.h"
#include "Jugador.h"

class PantallaFogata : public EntidadJuego {
	private:
		AdminEntradas* mEntradas;
		AdminAudio* mAudio;

		Jugador* mJugador;

		int mSeleccion;

		Layout* mLayout;
		Textura* mFondo;

		Textura* mVida;
		Textura* mFuerza;
		Textura* mVigor;
		Textura* mInteligencia;
		Textura* mDestreza;

		Textura* mSalir;

		bool AccionRealizada;

		Textura* mCursor;
		Vector2 mCursorPosInicial;
		Vector2 mCursorOffset;

	public:
		PantallaFogata(Jugador* &jugador);
		~PantallaFogata();

		void CambioSeleccion(int cambio);

		void Actualizar();

		void Renderizar();
};

#endif