#include "Nivel.h"

Nivel::Nivel() {

	mAccesible = false;
	mTipoNivel = 0;
}

int Nivel::getTipoNivel() {
	return mTipoNivel;
}

bool Nivel::Accesible() {
	return mAccesible;
}

void Nivel::CambiarAccesibilidadTrue() {
	mAccesible = true;
}

void Nivel::CambiarAccesibilidadFalse() {
	mAccesible = false;
}

void Nivel::setTipoNivel(int x) {
	mTipoNivel = x;
}