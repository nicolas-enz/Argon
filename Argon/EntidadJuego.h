#ifndef _ENTIDADJUEGO_H
#define _ENTIDADJUEGO_H
#include "AyudaMatematica.h"

class EntidadJuego {

	public:

		enum SPACE { local = 0, world = 1 };

	private:
		
		Vector2 mPos;
		float mRotacion;
		Vector2 mEscala;

		bool mActivo;
		EntidadJuego* mPadre;

	public:
		
		EntidadJuego(float x = 0.0f, float y = 0.0f);
		~EntidadJuego();

		void Pos(Vector2 pos);
		Vector2 Pos(SPACE space = world);

		void Rotacion(float rotacion);
		float Rotacion(SPACE space = world);

		void Escala(Vector2 escala);
		Vector2 Escala(SPACE space = world);

		void Activo(bool activo);
		bool Activo();

		void Padre(EntidadJuego* padre);
		EntidadJuego* Padre();

		void Mover(Vector2 vec);
		void Rotar(float cantidad);

		virtual void Actualizar();
		virtual void Renderizar();
};

#endif