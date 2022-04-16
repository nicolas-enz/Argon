#ifndef _PANTALLAINICIO_H
#define _PANTALLAINICIO_H
#include "TexturaAnimada.h"
#include "AdminAudio.h"
#include "AdminEntradas.h"

class PantallaInicio : public EntidadJuego {

private:

	Temporizador* mTemporizador;
	AdminEntradas* mEntrada;

	EntidadJuego* mTopBar;
	Textura* mTitulo;

	EntidadJuego* mModoJuego;
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

	Vector2 mAnimacionStartPos;
	Vector2 mAnimacionEndPos;
	float mAnimacionTotalTime;
	float mAnimacionTemporizador;
	bool mAnimacionDone;

public:

	PantallaInicio();
	~PantallaInicio();

	void ResetearAnimacion();

	int ModoSeleccionado();

	void CambiarModoSeleccionado(int cambio);

	void Actualizar();

	void Renderizar();
};


#endif