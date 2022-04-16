#ifndef _BOTONES_H
#define _BOTONES_H
#include "EntidadJuego.h"
#include "Textura.h"

class Botones : public EntidadJuego {

private:

	Textura* mBotones[4];
	Textura* mAtacar;
	Textura* mDefender;
	Textura* mMagia;
	Textura* mCAtacar;

public:

	Botones();
	~Botones();

	void CambiarColor(int cod);

	void Actualizar();
	void Renderizar();
};


#endif 

