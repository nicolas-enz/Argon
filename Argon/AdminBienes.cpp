#include "AdminBienes.h"

AdminBienes* AdminBienes::sInstancia = NULL;

AdminBienes* AdminBienes::Instancia() {

	if (sInstancia == NULL)
		sInstancia = new AdminBienes();

	return sInstancia;
}

void AdminBienes::Liberar() {

	delete sInstancia;
	sInstancia = NULL;
}

AdminBienes::AdminBienes() {

}

AdminBienes::~AdminBienes() {

	for (auto tex : mTexturas) {

		if (tex.second != NULL) {

			SDL_DestroyTexture(tex.second);
		}
	}

	mTexturas.clear();

	for (auto text : mTexto) {

		if (text.second != NULL) {
			
			SDL_DestroyTexture(text.second);
		}
	}

	mTexto.clear();

	for (auto font : mFuentes) {

		if (font.second != NULL) {

			TTF_CloseFont(font.second);
		}
	}

	mFuentes.clear();

	for (auto musica : mMusica) {

		if (musica.second != NULL) {

			Mix_FreeMusic(musica.second);
		}
	}

	mMusica.clear();

	for (auto sfx : mSFX) {

		if (sfx.second != NULL) {

			Mix_FreeChunk(sfx.second);
		}
	}

	mSFX.clear();
}

SDL_Texture* AdminBienes::GetTextura(std::string nombreArchivo) {

	std::string rutaCompleta = SDL_GetBasePath();
	rutaCompleta.append("Assets/" + nombreArchivo);
	
	if (mTexturas[rutaCompleta] == nullptr) {
		
		mTexturas[rutaCompleta] = Graficos::Instancia()->CargarTextura(rutaCompleta);
	}

	return mTexturas[rutaCompleta];
}

TTF_Font* AdminBienes::GetFont(std::string nombreArchivo, int tam) {

	std::string rutaCompleta = SDL_GetBasePath();
	rutaCompleta.append("Assets/" + nombreArchivo);
	std::string key = rutaCompleta + (char)tam;

	if (mFuentes[key] == nullptr) {

		mFuentes[key] = TTF_OpenFont(rutaCompleta.c_str(), tam);
		if (mFuentes[key] == nullptr) {

			printf("FONT LOADING ERROR: Font - %s Error - %s", nombreArchivo.c_str(), TTF_GetError());
		}
	}

	return mFuentes[key];
}

SDL_Texture* AdminBienes::GetTexto(std::string texto, std::string nombreArchivo, int tam, SDL_Color color) {

	TTF_Font* font = GetFont(nombreArchivo, tam);

	std::string key = texto + nombreArchivo + (char)tam + (char)color.r + (char)color.b + (char)color.g;

	if (mTexto[key] == nullptr) {

		mTexto[key] = Graficos::Instancia()->CrearTexturaDeTexto(font, texto, color);
	}

	return mTexto[key];
}

Mix_Music* AdminBienes::GetMusica(std::string nombreArchivo) {

	std::string rutaCompleta = SDL_GetBasePath();
	rutaCompleta.append("Assets/" + nombreArchivo);

	if (mMusica[rutaCompleta] == nullptr) {

		mMusica[rutaCompleta] = Mix_LoadMUS(rutaCompleta.c_str());
		if (mMusica[rutaCompleta] == NULL) {

			printf("MUSIC LOADING ERROR: File - %s Error - %s", nombreArchivo.c_str(), Mix_GetError());
		}
	}

	return mMusica[rutaCompleta];
}

Mix_Chunk* AdminBienes::GetSFX(std::string nombreArchivo) {

	std::string rutaCompleta = SDL_GetBasePath();
	rutaCompleta.append("Assets/" + nombreArchivo);

	if (mSFX[rutaCompleta] == nullptr) {

		mSFX[rutaCompleta] = Mix_LoadWAV(rutaCompleta.c_str());
		if (mSFX[rutaCompleta] == NULL) {

			printf("SFX LOADING ERROR: File - %s Error - %s", nombreArchivo.c_str(), Mix_GetError());
		}
	}

	return mSFX[rutaCompleta];
}