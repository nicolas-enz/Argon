#ifndef _Temporizador_H
#define _Temporizador_H
#include <SDL.h>

class Temporizador {

	private:

		static Temporizador* sInstancia;

		unsigned int mStartTicks;
		unsigned int mTicksTranscurridos;
		float mTiempoDelta;
		float mEscalaTiempo;

	public:

		static Temporizador* Instancia();
		static void Liberar();

		void Resetear();
		float TiempoDelta();

		void EscalaTiempo(float t);
		float EscalaTiempo();

		void Actualizar();

	private:

		Temporizador();
		~Temporizador();
};

#endif