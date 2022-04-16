#include "Temporizador.h"

Temporizador* Temporizador::sInstancia = NULL;

Temporizador* Temporizador::Instancia(){

	if (sInstancia == NULL)
		sInstancia = new Temporizador();

	return sInstancia;
}

void Temporizador::Liberar() {
	
	delete sInstancia;
	sInstancia = NULL;
}

Temporizador::Temporizador() {

	Resetear();
	mEscalaTiempo = 1.0f;
}

Temporizador::~Temporizador() {


}

void Temporizador::Resetear() {

	mStartTicks = SDL_GetTicks();
	mTicksTranscurridos = 0;
	mTiempoDelta = 0.0f;
}

float Temporizador::TiempoDelta() {

	return mTiempoDelta;
}

void Temporizador::EscalaTiempo(float t) {

	mEscalaTiempo = t;
}

float Temporizador::EscalaTiempo() {

	return mEscalaTiempo;
}

void Temporizador::Actualizar() {

	mTicksTranscurridos = SDL_GetTicks() - mStartTicks;
	mTiempoDelta = mTicksTranscurridos * 0.001f;
}