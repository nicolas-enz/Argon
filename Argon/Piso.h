#ifndef _PISO_H
#define _PISO_H
#include "Nivel.h"
#include <ctime>
#include <iostream>
using namespace std;

class Piso {

	private:
		Nivel mPiso[10];
		
	public:

		void InicializarPiso(); // Inicializa el piso con valores aleatorios entre 1 y 5

		bool Accesible(int x);
		void CambiarAccesibilidadTrue(int x);
		void CambiarAccesibilidadFalse(int x);
		Nivel GetNivel(int x); // Devuelve un nivel de la posición x
};


#endif