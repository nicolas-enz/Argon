#ifndef _ASSETSMANAGER_H
#define _ASSETSMANAGER_H
#include "Graficos.h"
#include <SDL_mixer.h>
#include <map>

class AdminBienes {

	private:
		
		static AdminBienes* sInstancia;

		std::map<std::string, SDL_Texture*> mTexturas;
		std::map<std::string, SDL_Texture*> mTexto;
		std::map<std::string, TTF_Font*> mFuentes;
		std::map<std::string, Mix_Music*> mMusica;
		std::map<std::string, Mix_Chunk*> mSFX;

	public:
		
		static AdminBienes* Instancia();
		static void Liberar();

		SDL_Texture* GetTextura(std::string nombreArchivo);
		SDL_Texture* GetTexto(std::string texto, std::string nombreArchivo, int tam, SDL_Color color);

		Mix_Music* GetMusica(std::string nombreArchivo);
		Mix_Chunk* GetSFX(std::string nombreArchivo);

	private:
		
		AdminBienes();
		~AdminBienes();

		TTF_Font* GetFont(std::string nombreArchivo, int tam);
};

#endif