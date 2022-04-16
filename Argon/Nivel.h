#ifndef _NIVEL_H
#define _NIVEL_H
#include "EntidadJuego.h"

class Nivel : public EntidadJuego{
	private:
		int mTipoNivel;
		bool mAccesible;
	public:
		
		Nivel();

		int getTipoNivel();
		bool Accesible();
		void CambiarAccesibilidadTrue();
		void CambiarAccesibilidadFalse();
		void setTipoNivel(int x);
};


#endif