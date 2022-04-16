#include "BarraLateral.h"


BarraLateral::BarraLateral(Jugador* &jugador) {

	mJugador = jugador;

	mFondo = new Textura("background/stats.png");
	mFondo->Padre(this);
	mFondo->Pos(VEC2_ZERO);
	
	mEstadisticas = new Textura("ESTADISTICAS", "fonts/emulogic.ttf", 17, { 25,25,112 });
	mEstadisticas->Padre(this);
	mEstadisticas->Pos(Vector2(0.0f, -220.0f));

	mVida = new Textura("VIDA: " + NumeroIntACadena(mJugador->VidaRestante()) + "/"+ NumeroIntACadena(mJugador->Vida()), "fonts/OpenSans-ExtraBold.ttf", 17, { 0,0,255 });
	mVida->Padre(this);
	mVida->Pos(Vector2(0.0f, -170.0f));

	mMana = new Textura("MANA: " + NumeroIntACadena(mJugador->ManaRestante()) + "/" + NumeroIntACadena(mJugador->Mana()), "fonts/OpenSans-ExtraBold.ttf", 17, { 0,0,255 });
	mMana->Padre(this);
	mMana->Pos(Vector2(0.0f, -140.0f));

	mAtaque = new Textura("ATAQUE FISICO: " + NumeroFloatACadena(mJugador->AtaqueFisico()), "fonts/OpenSans-ExtraBold.ttf", 17, { 0,0,255 });
	mAtaque->Padre(this);
	mAtaque->Pos(Vector2(0.0f, -110.0f));

	mMagia = new Textura("ATAQUE MAGICO: " + NumeroFloatACadena(mJugador->AtaqueMagico()), "fonts/OpenSans-ExtraBold.ttf", 17, { 0,0,255 });
	mMagia->Padre(this);
	mMagia->Pos(Vector2(0.0f, -80.0f));

	mChanceCrit = new Textura("C. CRITICO: " + NumeroFloatACadena(mJugador->ChanceCritico() * 100) + "%", "fonts/OpenSans-ExtraBold.ttf", 17, { 0,0,255 });
	mChanceCrit->Padre(this);
	mChanceCrit->Pos(Vector2(0.0f, -50.0f));

	mVigor = new Textura("VIGOR: " + NumeroIntACadena(mJugador->Vigor()), "fonts/OpenSans-ExtraBold.ttf", 17, { 0,0,255 });
	mVigor->Padre(this);
	mVigor->Pos(Vector2(0.0f, 20.0f));

	mFuerza = new Textura("FUERZA: " + NumeroIntACadena(mJugador->Fuerza()), "fonts/OpenSans-ExtraBold.ttf", 17, { 0,0,255 });
	mFuerza->Padre(this);
	mFuerza->Pos(Vector2(0.0f, 50.0f));

	mInteligencia = new Textura("INTELIGENCIA: " + NumeroIntACadena(mJugador->Inteligencia()), "fonts/OpenSans-ExtraBold.ttf", 17, { 0,0,255 });
	mInteligencia->Padre(this);
	mInteligencia->Pos(Vector2(0.0f, 80.0f));

	mDestreza = new Textura("DESTREZA: " + NumeroIntACadena(mJugador->Destreza()), "fonts/OpenSans-ExtraBold.ttf", 17, { 0,0,255 });
	mDestreza->Padre(this);
	mDestreza->Pos(Vector2(0.0f, 110.0f));

	mOro = new Textura("ORO: " + NumeroIntACadena(mJugador->Oro()), "fonts/OpenSans-ExtraBold.ttf", 17, { 0,0,255 });
	mOro->Padre(this);
	mOro->Pos(Vector2(0.0f, 140.0f));
}

BarraLateral::~BarraLateral() {

	delete mFondo;
	mFondo = NULL;

	delete mEstadisticas;
	mEstadisticas = NULL;

	delete mAtaque;
	mAtaque = NULL;

	delete mMagia;
	mMagia = NULL;

	delete mVida;
	mVida = NULL;

	delete mMana;
	mMana = NULL;

	delete mChanceCrit;
	mChanceCrit = NULL;

	delete mVigor;
	mVigor = NULL;

	delete mFuerza;
	mFuerza = NULL;

	delete mInteligencia;
	mInteligencia = NULL;

	delete mDestreza;
	mDestreza = NULL;

	delete mOro;
	mOro = NULL;
}


void BarraLateral::Actualizar() {


}

void BarraLateral::Renderizar() {

	mFondo->Renderizar();
	mEstadisticas->Renderizar();

	mVida->Renderizar();
	mMana->Renderizar();
	mAtaque->Renderizar();
	mMagia->Renderizar();
	mChanceCrit->Renderizar();
	mVigor->Renderizar();
	mFuerza->Renderizar();
	mInteligencia->Renderizar();
	mDestreza->Renderizar();
	mOro->Renderizar();

}