#include "AdminEntradas.h"

AdminEntradas* AdminEntradas::sInstancia = NULL;

AdminEntradas* AdminEntradas::Instancia() {

	if (sInstancia == NULL)
		sInstancia = new AdminEntradas();

	return sInstancia;
}

void AdminEntradas::Liberar() {

	delete sInstancia;
	sInstancia = NULL;
}

AdminEntradas::AdminEntradas() {

	mEstadoTeclado = SDL_GetKeyboardState(&mCantidadTeclas);
	mEstadoTecladoPrevio = new Uint8[mCantidadTeclas];
	memcpy(mEstadoTecladoPrevio, mEstadoTeclado, mCantidadTeclas);
}

AdminEntradas::~AdminEntradas() {

	delete[] mEstadoTecladoPrevio;
	mEstadoTecladoPrevio = NULL;

}

bool AdminEntradas::TeclaApretada(SDL_Scancode scanCode) {

	return mEstadoTeclado[scanCode];
}

bool AdminEntradas::TeclaPresionada(SDL_Scancode scanCode) {
	
	return !mEstadoTecladoPrevio[scanCode] && mEstadoTeclado[scanCode];
}

bool AdminEntradas::TeclaLiberada(SDL_Scancode scanCode) {

	return mEstadoTecladoPrevio[scanCode] && mEstadoTeclado[scanCode];
}

void AdminEntradas::Actualizar() {

}

void AdminEntradas::ActualizarInputPrevio() {

	memcpy(mEstadoTecladoPrevio, mEstadoTeclado, mCantidadTeclas);
}