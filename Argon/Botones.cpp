#include "Botones.h"

Botones::Botones() {

	for (int i=0; i < 4; i++) {
		switch (i) {
			case 0:
				mBotones[i] = new Textura("background/boton.png"); //arriba izquierda
				mBotones[i]->Padre(this);
				mBotones[i]->Pos(Vector2(-100.0f, -264.0f));

				mAtacar = new Textura("ATAQUE", "fonts/emulogic.ttf", 19, { 25,25,112 });
				mAtacar->Padre(this);
				mAtacar->Pos(Vector2(-100.0f, -264.0f));
				break;
			case 1:
				mBotones[i] = new Textura("background/boton.png"); //arriba derecha
				mBotones[i]->Padre(this);
				mBotones[i]->Pos(Vector2(40.0f, -264.0f));

				mDefender = new Textura("DEFENSA", "fonts/emulogic.ttf", 19, { 25,25,112 });
				mDefender->Padre(this);
				mDefender->Pos(Vector2(40.0f, -264.0f));
				break;
			case 2:
				mBotones[i] = new Textura("background/boton.png"); //abajo izquierda
				mBotones[i]->Padre(this);
				mBotones[i]->Pos(Vector2(-100.0f, -180.0f));

				mMagia = new Textura("MAGIA", "fonts/emulogic.ttf", 19, { 25,25,112 });
				mMagia->Padre(this);
				mMagia->Pos(Vector2(-100.0f, -180.0f));
				break;
			case 3:
				mBotones[i] = new Textura("background/boton.png"); //abajo derecha
				mBotones[i]->Padre(this);
				mBotones[i]->Pos(Vector2(40.0f, -180.0f));

				mCAtacar = new Textura("PARRY", "fonts/emulogic.ttf", 19, { 25,25,112 });
				mCAtacar->Padre(this);
				mCAtacar->Pos(Vector2(40.0f, -180.0f));
				break;
		}
	}



}

Botones::~Botones() {

	for (int i = 0; i < 4; i++) {
		delete mBotones[i];
		mBotones[i] = NULL;
	}

	delete mAtacar;
	mAtacar = NULL;

	delete mDefender;
	mDefender = NULL;

	delete mMagia;
	mMagia = NULL;

	delete mCAtacar;
	mCAtacar = NULL;
}

void Botones::CambiarColor(int cod) {

	for (int i = 0; i < 4; i++) {
		delete mBotones[i];
		mBotones[i] = NULL;
	}

	for (int i = 0; i < 4; i++) {
		switch (i) {
		case 0:
			mBotones[i] = new Textura("background/boton.png"); //arriba izquierda
			mBotones[i]->Padre(this);
			mBotones[i]->Pos(Vector2(-100.0f, -264.0f));

			mAtacar = new Textura("ATAQUE", "fonts/emulogic.ttf", 19, { 25,25,112 });
			mAtacar->Padre(this);
			mAtacar->Pos(Vector2(-100.0f, -264.0f));
			break;
		case 1:
			mBotones[i] = new Textura("background/boton.png"); //arriba derecha
			mBotones[i]->Padre(this);
			mBotones[i]->Pos(Vector2(40.0f, -264.0f));

			mDefender = new Textura("DEFENSA", "fonts/emulogic.ttf", 19, { 25,25,112 });
			mDefender->Padre(this);
			mDefender->Pos(Vector2(40.0f, -264.0f));
			break;
		case 2:
			mBotones[i] = new Textura("background/boton.png"); //abajo izquierda
			mBotones[i]->Padre(this);
			mBotones[i]->Pos(Vector2(-100.0f, -180.0f));

			mMagia = new Textura("MAGIA", "fonts/emulogic.ttf", 19, { 25,25,112 });
			mMagia->Padre(this);
			mMagia->Pos(Vector2(-100.0f, -180.0f));
			break;
		case 3:
			mBotones[i] = new Textura("background/boton.png"); //abajo derecha
			mBotones[i]->Padre(this);
			mBotones[i]->Pos(Vector2(40.0f, -180.0f));

			mCAtacar = new Textura("PARRY", "fonts/emulogic.ttf", 19, { 25,25,112 });
			mCAtacar->Padre(this);
			mCAtacar->Pos(Vector2(40.0f, -180.0f));
			break;
		}
	}

	if (cod == 0) {
		delete mBotones[cod];
		mBotones[cod] = NULL;

		mBotones[cod] = new Textura("background/boton_seleccionado.png"); //arriba izquierda
		mBotones[cod]->Padre(this);
		mBotones[cod]->Pos(Vector2(-100.0f, -264.0f));

		mAtacar = new Textura("ATAQUE", "fonts/emulogic.ttf", 19, { 25,25,112 });
		mAtacar->Padre(this);
		mAtacar->Pos(Vector2(-100.0f, -264.0f));
	}
	else if (cod == 1) {
		delete mBotones[cod];
		mBotones[cod] = NULL;

		mBotones[cod] = new Textura("background/boton_seleccionado.png"); //arriba derecha
		mBotones[cod]->Padre(this);
		mBotones[cod]->Pos(Vector2(40.0f, -264.0f));

		mDefender = new Textura("DEFENSA", "fonts/emulogic.ttf", 19, { 25,25,112 });
		mDefender->Padre(this);
		mDefender->Pos(Vector2(40.0f, -264.0f)); //Vector2(-100.0f, -180.0f)
	}
	else if (cod == 2) {
		delete mBotones[cod];
		mBotones[cod] = NULL;

		mBotones[cod] = new Textura("background/boton_seleccionado.png"); //abajo izquierda
		mBotones[cod]->Padre(this);
		mBotones[cod]->Pos(Vector2(-100.0f, -180.0f));

		mMagia = new Textura("MAGIA", "fonts/emulogic.ttf", 19, { 25,25,112 });
		mMagia->Padre(this);
		mMagia->Pos(Vector2(-100.0f, -180.0f));//Vector2(40.0f, -264.0f)
	}
	else if (cod == 3) {
		delete mBotones[cod];
		mBotones[cod] = NULL;

		mBotones[cod] = new Textura("background/boton_seleccionado.png"); //abajo derecha
		mBotones[cod]->Padre(this);
		mBotones[cod]->Pos(Vector2(40.0f, -180.0f));

		mCAtacar = new Textura("PARRY", "fonts/emulogic.ttf", 19, { 25,25,112 });
		mCAtacar->Padre(this);
		mCAtacar->Pos(Vector2(40.0f, -180.0f));
	}
}

void Botones::Actualizar() {


}

void Botones::Renderizar() {

	for (int i = 0; i < 4; i++) {

		mBotones[i]->Renderizar();
	}

	mAtacar->Renderizar();
	mDefender->Renderizar();
	mMagia->Renderizar();
	mCAtacar->Renderizar();
}