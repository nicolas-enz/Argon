#ifndef _ENEMIGO_H
#define _ENEMIGO_H
#include "Textura.h"
#include "AyudaString.h"
#include <stdio.h>
#include <string>

class Enemigo {

	private:

		int mVida;
		int mVidaRestante;
		int mAtaque;
		int mRecompensa;

		Textura* mEnemigo;
		Textura* mTextoVida;

	public:

		Enemigo(int vida, int ataque, int recompensa, std::string cadena);
		~Enemigo();

		int VidaRestante();
		int Vida();

		int Recompensa();

		void ReducirVida(int danio);

		int Atacar();

		void Actualizar();

		void Renderizar();

};


#endif