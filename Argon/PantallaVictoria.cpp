#include "PantallaVictoria.h"

PantallaVictoria::PantallaVictoria() {

	mTexto = new Textura("VICTORIA!", "fonts/emulogic.ttf", 50, { 0, 200, 0 });
	mTexto->Pos(Vector2(512.0f, 384.0f));
}

PantallaVictoria::~PantallaVictoria() {

	delete mTexto;
	mTexto = NULL;
}

void PantallaVictoria::Actualizar() {


}

void PantallaVictoria::Renderizar() {

	mTexto->Renderizar();
}