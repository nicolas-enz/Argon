#include "Opciones.h"

Opciones::Opciones(){

	mFondo = new Textura("background/opciones.png");
	mFondo->Padre(this);
	mFondo->Pos(VEC2_ZERO);

	mOpciones = new Textura("Opciones (O)", "fonts/emulogic.ttf", 22, { 25,25,112 });
	mOpciones->Padre(this);
	mOpciones->Pos(Vector2(0.0f, -60.0f));

	mAyuda = new Textura("Ayuda (H)", "fonts/emulogic.ttf", 22, { 25, 25, 112 });
	mAyuda->Padre(this);
	mAyuda->Pos(VEC2_ZERO);

	mSalir = new Textura("Salir (esc)", "fonts/emulogic.ttf", 22, { 25,25,112 });
	mSalir->Padre(this);
	mSalir->Pos(Vector2(0.0f, 60.0f));
}

Opciones::~Opciones() {

	delete mFondo;
	mFondo = NULL;

	delete mOpciones;
	mOpciones = NULL;

	delete mSalir;
	mSalir = NULL;

	delete mAyuda;
	mAyuda = NULL;
}

void Opciones::Actualizar() {


}

void Opciones::Renderizar() {

	mFondo->Renderizar();
	mOpciones->Renderizar();
	mSalir->Renderizar();
	mAyuda->Renderizar();
}