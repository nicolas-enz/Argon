#include "AdminAudio.h"

AdminAudio* AdminAudio::sInstancia = NULL;

AdminAudio* AdminAudio::Instancia() {

	if (sInstancia == NULL) {

		sInstancia = new AdminAudio();
	}

	return sInstancia;
}

void AdminAudio::Liberar() {

	delete sInstancia;
	sInstancia = NULL;
}

AdminAudio::AdminAudio() {

	mAdminBienes = AdminBienes::Instancia();

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {

		printf("MIXER INIT ERROR: %s\n", Mix_GetError());
	}
}

AdminAudio::~AdminAudio() {

	mAdminBienes = NULL;
	Mix_Quit();
}

void AdminAudio::PlayMusica(std::string nombreArchivo, int loops) {

	Mix_PlayMusic(mAdminBienes->GetMusica(nombreArchivo), loops);
}

void AdminAudio::PausarMusica() {

	if (Mix_PlayingMusic() != 0) {

		Mix_PauseMusic();
	}
}

void AdminAudio::ResumirMusica() {

	if (Mix_PausedMusic() != 0) {

		Mix_ResumeMusic();
	}
}

void AdminAudio::PlaySFX(std::string nombreArchivo, int loops, int channel) {

	Mix_PlayChannel(channel, mAdminBienes->GetSFX(nombreArchivo), loops);
}

void AdminAudio::Volumen() {
	Mix_Volume(0, 10);
}

void AdminAudio::Volumen(int vol) {
	Mix_VolumeMusic(vol);
}