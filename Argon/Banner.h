#ifndef _BANNER_H
#define _BANNER_H
#include "EntidadJuego.h"
#include "Textura.h"

class Banner : public EntidadJuego {

private:

	Textura* mFondo;

	Textura* mBanner;

public:

	Banner();
	~Banner();

	void Actualizar();

	void Renderizar();

};

#endif