#ifndef _PANTALLAOPCIONES_H
#define _PANTALLAOPCIONES_H
#include "Temporizador.h"
#include "EntidadJuego.h"
#include "AdminEntradas.h"
#include "AdminAudio.h"
#include "Textura.h"
#include "Jugador.h"

class PantallaOpciones : public EntidadJuego {

	private:

		Jugador* mJugador;

		Temporizador* mTimer;
		AdminEntradas* mEntradas;
		AdminAudio* mAudio;
		AdminAudio* mAudioMusica;

		EntidadJuego* mOpciones;
		Textura* mTitulo;
		Textura* mSFX;
		Textura* mMusica;
		Textura* mCursor;
		Vector2 mCursorPosInicio;
		Vector2 mCursorOffset;
		int mModoSeleccionado;

	public:

		PantallaOpciones(Jugador* &jugador);
		PantallaOpciones(Jugador* &jugador, AdminAudio* &musica);
		~PantallaOpciones();

		void MoverCursor(int cambio);
		void CambiarAudio(int cambio);

		void Actualizar();
		void Renderizar();
};

#endif