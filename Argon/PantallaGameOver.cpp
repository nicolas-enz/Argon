#include "PantallaGameOver.h"

PantallaGameOver::PantallaGameOver() {

	mTexto = new Textura("GAME OVER", "fonts/emulogic.ttf", 50, {255, 0, 0});
	mTexto->Pos(Vector2(512.0f, 384.0f));
}

PantallaGameOver::~PantallaGameOver() {

	delete mTexto;
	mTexto = NULL;
}

void PantallaGameOver::Actualizar() {


}

void PantallaGameOver::Renderizar() {

	mTexto->Renderizar();
}