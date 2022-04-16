#ifndef _TEXTURA_H
#define _TEXTURA_H
#include "EntidadJuego.h"
#include "AdminBienes.h"

class Textura : public EntidadJuego {

	protected:

		SDL_Texture* mTex;
		
		Graficos* mGraficos;

		int mAncho;
		int mAlto;

		bool mCortado;
		SDL_Rect mRenderizadorRect;
		SDL_Rect mRectCortado;

	public:

		Textura(std::string nombreArchivo);
		Textura(std::string nombreArchivo, int x, int y, int w, int h);
		Textura(std::string texto, std::string rutaFuente, int tam, SDL_Color color);
		~Textura();

		virtual void Renderizar();
};

#endif