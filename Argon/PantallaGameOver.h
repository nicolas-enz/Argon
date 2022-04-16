#ifndef _PANTALLAGAMEOVER_H
#define _PANTALLAGAMEOVER_H
#include "Textura.h"

class PantallaGameOver {

	private:

		Textura* mTexto;

	public:

		PantallaGameOver();
		~PantallaGameOver();

		void Actualizar();

		void Renderizar();
};

#endif