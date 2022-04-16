#include "EntidadJuego.h"

EntidadJuego::EntidadJuego(float x, float y) {
	mPos.x = x;
	mPos.y = y;

	mRotacion = 0.0f;

	mActivo = true;

	mPadre = NULL;

	mEscala = VEC2_ONE;
}

EntidadJuego::~EntidadJuego() {

	mPadre = NULL;
}

void EntidadJuego::Pos(Vector2 pos) {

	mPos = pos;
}

Vector2 EntidadJuego::Pos(SPACE space) {

	if (space == local || mPadre == NULL) {
		return mPos;
	}

	Vector2 padreEscala = mPadre->Escala(world);
	Vector2 rotPos = RotarVector(Vector2(mPos.x * padreEscala.x, mPos.y * padreEscala.y), mPadre->Rotacion(local));
	
	return mPadre->Pos(world) + rotPos;
}

void EntidadJuego::Rotacion(float r) {
	
	mRotacion = r;

	if (mRotacion > 360.0f)
		mRotacion -= 360.0f;

	if (mRotacion < 0.0f)
		mRotacion += 360.0f;
}

float EntidadJuego::Rotacion(SPACE space) {
	
	if (space == local || mPadre == NULL)
		return mRotacion;

	return mPadre->Rotacion(world) + mRotacion;
}

void EntidadJuego::Escala(Vector2 escala) {

	mEscala = escala;
}

Vector2 EntidadJuego::Escala(SPACE space) {

	if (space == local || mPadre == NULL) {

		return mEscala;
	}

	Vector2 escala = mPadre->Escala(world);
	escala.x *= mEscala.x;
	escala.y *= mEscala.y;

	return escala;
}

void EntidadJuego::Activo(bool activo) {
	
	mActivo = activo;
}

bool EntidadJuego::Activo() {

	return mActivo;
}

void EntidadJuego::Padre(EntidadJuego* padre) {

	if (padre == NULL) {

		mPos = Pos(world);
		mRotacion = Rotacion(world);
		mEscala = Escala(world);
	}
	else {

		if (mPadre != NULL) {
			
			Padre(NULL);
		}

		Vector2 escalaPadre = padre->Escala(world);

		mPos = RotarVector(Pos(world) - padre->Pos(world), -padre->Rotacion(world));
		mPos.x /= escalaPadre.x;
		mPos.y /= escalaPadre.y;

		mRotacion -= padre->Rotacion(world);

		mEscala = Vector2(mEscala.x / escalaPadre.x, mEscala.y / escalaPadre.y);
	}

	mPadre = padre;
}

EntidadJuego* EntidadJuego::Padre() {

	return mPadre;
}

void EntidadJuego::Mover(Vector2 vec) {

	mPos += vec;
}

void EntidadJuego::Rotar(float cantidad) {

	mRotacion += cantidad;
}

void EntidadJuego::Actualizar() {


}

void EntidadJuego::Renderizar() {

}