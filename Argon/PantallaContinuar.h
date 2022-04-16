#ifndef _PANTALLACONTINUAR_H
#define _PANTALLACONTINUAR_H
#include "Textura.h"
#include "EntidadJuego.h"
#include "AdminEntradas.h"

class PantallaContinuar : public EntidadJuego {

	private:
		AdminEntradas* mEntrada;

		EntidadJuego* mTopBar;
		Textura* mTitulo;

		EntidadJuego* mModoJuego;
		Textura* mContinuar;
		Textura* mNuevoJuego;
		Textura* mOpciones;
		Textura* mSalir;
		Textura* mCursor;
		Vector2 mCursorPosInicio;
		Vector2 mCursorOffset;
		int mModoSeleccionado;

		EntidadJuego* mBottom;
		Textura* mFecha;
		Textura* mParticipantes;

	public:
		PantallaContinuar();
		~PantallaContinuar();

		int ModoSeleccionado();

		void CambiarModoSeleccionado(int cambio);

		void Actualizar();

		void Renderizar();

};

#endif