#include "Layout.h"

Layout::Layout(Jugador* &jugador) {

	mJugador = jugador;

	mBarraLateral = new BarraLateral(mJugador);
	mBarraLateral->Padre(this);
	mBarraLateral->Pos(Vector2(Graficos::Instancia()->ANCHO_PANTALLA*0.891f, Graficos::Instancia()->ALTO_PANTALLA*0.392f));

	mOpciones = new Opciones();
	mOpciones->Padre(this);
	mOpciones->Pos(Vector2(Graficos::Instancia()->ANCHO_PANTALLA*0.891f, Graficos::Instancia()->ALTO_PANTALLA*0.891f));

	mBanner = new Banner();
	mBanner->Padre(this);
	mBanner->Pos(Vector2(Graficos::Instancia()->ANCHO_PANTALLA*0.528f, Graficos::Instancia()->ALTO_PANTALLA*0.891f));

	mBotones = new Botones();
	mBotones->Padre(this);
	mBotones->Pos(Vector2(Graficos::Instancia()->ANCHO_PANTALLA*0.1665f, Graficos::Instancia()->ALTO_PANTALLA*1.18f));

}

Layout::~Layout() {
	
	delete mBarraLateral;
	mBarraLateral = NULL;

	delete mOpciones;
	mOpciones = NULL;

	delete mBanner;
	mBanner = NULL;

	delete mBotones;
	mBotones = NULL;
}

void Layout::CambiarColor(int x) {
	mBotones->CambiarColor(x);
}

void Layout::Renderizar() {

	mBarraLateral->Renderizar();
	mOpciones->Renderizar();
	mBanner->Renderizar();
	mBotones->Renderizar();
}