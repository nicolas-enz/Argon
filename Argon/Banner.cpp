#include "Banner.h"

Banner::Banner() {

	mFondo = new Textura("background/banner.png");
	mFondo->Padre(this);
	mFondo->Pos(VEC2_ZERO);

	mBanner = new Textura("ARGON", "fonts/emulogic.ttf", 80, { 25,25,112 });
	mBanner->Padre(this);
	mBanner->Pos(Vector2(0.0f, 0.0f));
}

Banner::~Banner() {

	delete mFondo;
	mFondo = NULL;

	delete mBanner;
	mBanner = NULL;
}


void Banner::Actualizar() {


}

void Banner::Renderizar() {

	mFondo->Renderizar();
	mBanner->Renderizar();
}