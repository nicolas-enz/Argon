#ifndef _GRAFICOS_H
#define _GRAFICOS_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>

class Graficos {
	public:

		static const int ANCHO_PANTALLA = 1024;
		static const int ALTO_PANTALLA = 768;
		
	private:

		static Graficos* sInstancia;
		static bool sInicializado;

		SDL_Window* mVentana;
		SDL_Surface* mBuffer;

		SDL_Renderer* mRenderizador;

	public:

		static Graficos* Instancia();
		static void Liberar();
		static bool Inicializado();

		SDL_Texture* CargarTextura(std::string ruta);
		SDL_Texture* CrearTexturaDeTexto(TTF_Font* fuente, std::string texto, SDL_Color color);

		void LimpiarBuffer();

		void DibujarTextura(SDL_Texture* tex, SDL_Rect* clip, SDL_Rect* rend, float angulo = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);

		void Renderizar();

	private:
		Graficos();
		~Graficos();

		bool Init();
};

#endif