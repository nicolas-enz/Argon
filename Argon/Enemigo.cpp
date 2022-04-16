#include "Enemigo.h"

Enemigo::Enemigo(int vida, int ataque, int recompensa, std::string cadena) {
	
	mVida = vida;
	mAtaque = ataque;
	mRecompensa = recompensa;

	mEnemigo = new Textura(cadena);
	mEnemigo->Pos(Vector2(600.0f, 300.0f));

	mTextoVida = new Textura(NumeroIntACadena(mVida), "fonts/OpenSans-ExtraBold.ttf", 40, { 0, 0, 0 });
	mTextoVida->Pos(Vector2(625.0f, 500.0f));
}

Enemigo::~Enemigo() {

	delete mEnemigo;
	mEnemigo = NULL;
}

void Enemigo::ReducirVida(int danio) {

	mVida -= danio;
}

int Enemigo::VidaRestante() {
	return mVidaRestante;
}

int Enemigo::Vida() {

	return mVida;
}

int Enemigo::Recompensa() {
	return mRecompensa;
}

int Enemigo::Atacar() {

	return mAtaque;
}

void Enemigo::Actualizar() {
	delete mTextoVida;
	mTextoVida = NULL;
	mTextoVida = new Textura(NumeroIntACadena(mVida), "fonts/OpenSans-ExtraBold.ttf", 60, { 0, 0, 0 });
	mTextoVida->Pos(Vector2(625.0f, 500.0f));
}

void Enemigo::Renderizar() {

	mTextoVida->Renderizar();
	mEnemigo->Renderizar();
}