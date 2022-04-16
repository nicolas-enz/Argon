#include "Textura.h"

Textura::Textura(std::string nombreArchivo) {

	mGraficos = Graficos::Instancia();

	mTex = AdminBienes::Instancia()->GetTextura(nombreArchivo);

	SDL_QueryTexture(mTex, NULL, NULL, &mAncho, &mAlto);

	mCortado = false;

	mRenderizadorRect.w = mAncho;
	mRenderizadorRect.h = mAlto;
}

Textura::Textura(std::string nombreArchivo, int x, int y, int w, int h) {

	mGraficos = Graficos::Instancia();

	mTex = AdminBienes::Instancia()->GetTextura(nombreArchivo);

	mCortado = true;

	mAncho = w;
	mAlto = h;

	mRenderizadorRect.w = mAncho;
	mRenderizadorRect.h = mAlto;

	mRectCortado.x = x;
	mRectCortado.y = y;
	mRectCortado.w = mAncho;
	mRectCortado.h = mAlto;
}

Textura::Textura(std::string texto, std::string rutaFuente, int tam, SDL_Color color) {

	mGraficos = Graficos::Instancia();
	mTex = AdminBienes::Instancia()->GetTexto(texto, rutaFuente, tam, color);

	mCortado = false;

	SDL_QueryTexture(mTex, NULL, NULL, &mAncho, &mAlto);

	mRenderizadorRect.w = mAncho;
	mRenderizadorRect.h = mAlto;
}

Textura::~Textura() {

	mTex = NULL;
	mGraficos = NULL;
}

void Textura::Renderizar() {

	Vector2 pos = Pos(world);
	Vector2 escala = Escala(world);

	mRenderizadorRect.x = (int)(pos.x - mAncho * escala.x * 0.5f);
	mRenderizadorRect.y = (int)(pos.y - mAlto * escala.y * 0.5f);
	mRenderizadorRect.w = (int)(mAncho * escala.x);
	mRenderizadorRect.h = (int)(mAlto * escala.y);

	mGraficos->DibujarTextura(mTex, NULL, &mRenderizadorRect, Rotacion(world));
}