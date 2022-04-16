#ifndef _PANTALLAVICTORIA_H
#define _PANTALLAVICTORIA_H
#include "Textura.h"

class PantallaVictoria {

private:

	Textura * mTexto;

public:

	PantallaVictoria();
	~PantallaVictoria();

	void Actualizar();

	void Renderizar();
};

#endif