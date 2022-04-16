#ifndef _OPCIONES_H
#define _OPCIONES_H
#include "EntidadJuego.h"
#include "Textura.h"

class Opciones : public EntidadJuego {

private:

		Textura* mFondo;
		Textura* mOpciones;
		Textura* mSalir;
		Textura* mAyuda;

public:

	Opciones();
	~Opciones();

	void Actualizar();

	void Renderizar();

};



#endif
