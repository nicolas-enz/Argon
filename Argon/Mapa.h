#ifndef _MAPA_H
#define _MAPA_H
#include "Textura.h"
#include "EntidadJuego.h"
#include "AdminEntradas.h"
#include "AdminAudio.h"
#include "Piso.h"
#include "AyudaString.h"

class Mapa : public EntidadJuego {

	private:

		Piso* mPiso;
		
		AdminEntradas* mEntradas;

		Textura* pi;

		Textura* mFondo;
		Textura* mNivel[10];
		Textura* mCursor;
		Vector2 mCursorPosInicio;
		Vector2 mCursorOffset;
		int mNivelSeleccionado;

	public:

		Mapa(int p);
		~Mapa();

		bool Accesible();
		void TrueNivelSeleccionado(int x);
		void FalseNivelSeleccionado(int x);
		int TipoNivelSeleccionado();
		void CambiarNivel(int cambio);

		void Actualizar();
		void Renderizar();
};

#endif