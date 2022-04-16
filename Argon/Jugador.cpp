#include "Jugador.h"

Jugador::Jugador() {
	mVigor = 10;
	mInteligencia = 7;
	mFuerza = 10;
	mDestreza = 10;

	Musica = true;
	SFX = true;

	mAtaqueFisico = mFuerza * 3;
	mAtaqueMagico = mInteligencia * 5;
	mChanceCritico = mDestreza * 0.005f;
	mVida = mVigor * 20;
	mVidaRestante = mVida;
	mMana = mInteligencia * 5;
	mManaRestante = mMana;

	mOro = 100;

	mTurno = 1;
	mPiso = 0;

	mTex = new Textura("sprites/jugador.png");
	mTex->Pos(Vector2(150.0f, 300.0f));
}

Jugador::~Jugador() {
	delete mTex;
	mTex = NULL;
}

int Jugador::Vigor() {

	return mVigor;
}

int Jugador::Fuerza() {

	return mFuerza;
}

int Jugador::Inteligencia() {

	return mInteligencia;
}

int Jugador::Destreza() {

	return mDestreza;
}

float Jugador::ChanceCritico() {

	return mChanceCritico;
}

int Jugador::AtaqueFisico() {

	return mAtaqueFisico;
}

int Jugador::AtaqueMagico() {

	return mAtaqueMagico;
}

int Jugador::VidaRestante() {

	return mVidaRestante;
}

int Jugador::Vida() {

	return mVida;
}

int Jugador::ManaRestante() {

	return mManaRestante;
}

int Jugador::Mana() {

	return mMana;
}

int Jugador::Oro() {

	return mOro;
}

int Jugador::Piso() {

	return mPiso;
}

void Jugador::AumentarFuerza() {
	mFuerza++;
	mAtaqueFisico = mFuerza * 4;
}

void Jugador::AumentarVigor() {
	mVigor++;
	mVida += 15;
	mVidaRestante += 15;
}

void Jugador::AumentarInteligencia() {
	mInteligencia++;
	mAtaqueMagico = mInteligencia * 5;
	mMana = mInteligencia * 5;
}

void Jugador::AumentarDestreza() {
	mDestreza++;
	mChanceCritico = mDestreza * 0.01f;
}

void Jugador::RecuperarVida100() {
	mVidaRestante = mVida;
}

void Jugador::RecuperarVida50() {

	mVidaRestante += mVida * 0.5;
	if (mVidaRestante > mVida) {
		mVidaRestante = mVida;
	}
}

void Jugador::RecuperarVida30() {

	mVidaRestante += mVida * 0.3;
	if (mVidaRestante > mVida) {
		mVidaRestante = mVida;
	}
}

void Jugador::RecuperarVida10() {

	mVidaRestante += mVida * 0.1;
	if (mVidaRestante > mVida) {
		mVidaRestante = mVida;
	}
}

void Jugador::RecuperarMana() {

	mManaRestante = mMana;
}

void Jugador::Recompensa(int recompensa) {

	mOro += recompensa;
}

void Jugador::SubirPiso() {

	mPiso++;
}

void Jugador::ReducirOro(int costo) {
	mOro -= costo;
}

void Jugador::ReducirMana(int reduccion) {

	mManaRestante -= reduccion;
}

void Jugador::ReducirVida(int danio) {

	mVidaRestante -= danio;
}

bool Jugador::GetSFX() {
	return SFX;
}

bool Jugador::GetMusica() {
	return Musica;
}

void Jugador::SFXON() {
	SFX = true;
}

void Jugador::MusicaON() {
	Musica = true;
}

void Jugador::MusicaOFF() {
	Musica = false;
}

void Jugador::SFXOFF() {
	SFX = false;
}

int Jugador::Turno() {
	return mTurno;
}

void Jugador::SiguienteTurno() {
	mTurno++;
}

void Jugador::ResetiarTurno() {
	mTurno = 1;
}

void Jugador::Renderizar() {

	mTex->Renderizar();
}