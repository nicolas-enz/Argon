#ifndef _AdminAudio_H
#define _AdminAudio_H
#include "AdminBienes.h"

class AdminAudio {

	private:
		
		static AdminAudio* sInstancia;

		AdminBienes* mAdminBienes;

	public:
		static AdminAudio* Instancia();
		static void Liberar();

		void PlayMusica(std::string nombreArchivo, int loops = -1);
		void PausarMusica();
		void ResumirMusica();

		void PlaySFX(std::string nombreArchivo, int loops = 0, int channel = 0);

		void Volumen();
		void Volumen(int vol);

	private:
		
		AdminAudio();
		~AdminAudio();
};

#endif
