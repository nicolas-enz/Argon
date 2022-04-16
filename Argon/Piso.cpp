#include <ctime>
#include <cstdlib>
#include "piso.h"

void vectorEnCero(int v[], int tam) {
	for (int i = 0; i < tam; i++) {
		v[i] = 0;
	}
}

void Piso::InicializarPiso(){
	int x;
	int v[4];
	vectorEnCero(v, 4);

	v[0]++;
	mPiso[0].setTipoNivel(1);
	for (int i = 1; i < 9; i++) {
	tirarNuevamente:
		x = rand() % 100 + 1;
		if (x > 70) {
			x = rand() % 3 + 2;
		}
		else {
			x = 1;
		}
		switch (x) {
		case 1:		//Enemigo
			v[0]++;
			if (v[0] > 6) {
				goto tirarNuevamente;
			}
			else {
				mPiso[i].setTipoNivel(x);
			}
			break;
		case 2:		//Mercader
			v[1]++;
			if (v[1] > 2) {
				goto tirarNuevamente;
			}
			else {

				mPiso[i].setTipoNivel(x);
			}
			break;
		case 3:		//Fogata
			v[2]++;
			if (v[2] > 1) {
				goto tirarNuevamente;
			}
			else {

				mPiso[i].setTipoNivel(x);
			}
			break;
		case 4:		//Cofre
			v[3]++;
			if (v[3] > 1) {
				goto tirarNuevamente;
			}
			else {

				mPiso[i].setTipoNivel(x);
			}
			break;
		}
	}
	mPiso[9].setTipoNivel(5);
	for (int i = 0; i < 10; i++) {
	}
}

bool Piso::Accesible(int x) {

	return mPiso[x].Accesible();
}

void Piso::CambiarAccesibilidadTrue(int x) {

	mPiso[x].CambiarAccesibilidadTrue();
}

void Piso::CambiarAccesibilidadFalse(int x) {

	mPiso[x].CambiarAccesibilidadFalse();
}

Nivel Piso::GetNivel(int x) {
	return mPiso[x];
}
