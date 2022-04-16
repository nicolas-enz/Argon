#include "Graficos.h"

Graficos* Graficos::sInstancia = NULL;
bool Graficos::sInicializado = false;

Graficos* Graficos::Instancia() {

	if (sInstancia == NULL) {
		sInstancia = new Graficos();
	}

	return sInstancia;
}

void Graficos::Liberar() {

	delete sInstancia;
	sInstancia = NULL;

	sInicializado = false;
}

bool Graficos::Inicializado() {

	return sInicializado;
}

Graficos::Graficos() {
	
	mBuffer = NULL;

	sInicializado = Init();
}

Graficos::~Graficos() {

	SDL_DestroyWindow(mVentana);
	mVentana = NULL;

	SDL_DestroyRenderer(mRenderizador);
	mRenderizador = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

bool Graficos::Init() {

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {

		printf("SDL INIT ERROR: %s\n", SDL_GetError());
		return false;
	}

	mVentana = SDL_CreateWindow("ARGON", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ANCHO_PANTALLA, ALTO_PANTALLA, SDL_WINDOW_SHOWN);

	if (mVentana == NULL) {

		printf("WINDOW CREATION ERROR: %s\n", SDL_GetError());
		return false;
	}

	mRenderizador = SDL_CreateRenderer(mVentana, -1, SDL_RENDERER_ACCELERATED);

	if (mRenderizador == NULL) {

		printf("RENDERER CREATION ERROR: %s\n", SDL_GetError());
		return false;
	}

	SDL_SetRenderDrawColor(mRenderizador, 0x00, 0x00, 0x00, 0xff);

	int flags = IMG_INIT_PNG;
	if (!(IMG_Init(flags)) && flags) {

		printf("IMG INIT ERROR: %s\n", IMG_GetError());
		return false;
	}

	if (TTF_Init() == -1) {

		printf("TTF INIT ERROR: %s\n", TTF_GetError());
		return false;
	}

	mBuffer = SDL_GetWindowSurface(mVentana);

	return true;
}

SDL_Texture* Graficos::CargarTextura(std::string ruta) {
	
	SDL_Texture* tex = NULL;

	SDL_Surface* surface = IMG_Load(ruta.c_str());
	if (surface == NULL) {

		printf("IMAGE LOAD ERROR: ruta(%s) - ERROR: (%s)\n", ruta.c_str(), IMG_GetError());
		return tex;
	}

	tex = SDL_CreateTextureFromSurface(mRenderizador, surface);
	if (tex == NULL) {

		printf("CREATION OF TEXTURE ERROR: %s\n", SDL_GetError());
		return tex;
	}

	SDL_FreeSurface(surface);

	return tex;
}

SDL_Texture* Graficos::CrearTexturaDeTexto(TTF_Font* fuente, std::string texto, SDL_Color color) {

	SDL_Surface* surface = TTF_RenderText_Solid(fuente, texto.c_str(), color);

	if (surface == NULL) {

		printf("TEXT RENDER ERROR: %s\n", TTF_GetError());
		return NULL;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(mRenderizador, surface);

	if (tex == NULL) {

		printf("TEXT TEXTURE CREATION ERROR: %s\n", SDL_GetError());
		return NULL;
	}

	SDL_FreeSurface(surface);

	return tex;
}

void Graficos::LimpiarBuffer() {

	SDL_RenderClear(mRenderizador);
}

void Graficos::DibujarTextura(SDL_Texture* tex, SDL_Rect* clip, SDL_Rect* rend, float angulo, SDL_RendererFlip flip) {

	SDL_RenderCopyEx(mRenderizador, tex, clip, rend, angulo, NULL, flip);
}

void Graficos::Renderizar() {

	SDL_RenderPresent(mRenderizador);
}
