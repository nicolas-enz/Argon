#ifndef _AdminEntradas_H
#define _AdminEntradas_H
#include <SDL.h>
#include <string.h>
#include "AyudaMatematica.h"

class AdminEntradas {

	private:
		
		static AdminEntradas* sInstancia;

		Uint8* mEstadoTecladoPrevio;
		const Uint8* mEstadoTeclado;
		int mCantidadTeclas;

	public:
		
		static AdminEntradas* Instancia();
		static void Liberar();

		bool TeclaApretada(SDL_Scancode scanCode);
		bool TeclaPresionada(SDL_Scancode scanCode);
		bool TeclaLiberada(SDL_Scancode scanCode);

		void Actualizar();
		void ActualizarInputPrevio();

	private:

		AdminEntradas();
		~AdminEntradas();
};

#endif