#ifndef _PANTALLAMAPA_H
#define _PANTALLAMAPA_H
#include "AdminEntradas.h"
#include "EntidadJuego.h"
#include "AdminAudio.h"
#include "Textura.h"
#include "Layout.h"
#include "Mapa.h"
#include "Jugador.h"

class PantallaMapa : public EntidadJuego {

	private:

		AdminEntradas* mEntradas;
		AdminAudio* mAudio;

		Layout* mLayout;
		Mapa* mMapa;


		bool NivelTerminado;
		int TipoNivel;

		Jugador* mJugador;

	public:

		PantallaMapa(Jugador* &jugador);
		~PantallaMapa();
		
		bool Accesible();
		void CambiarAccesibilidad();
		int TipoNivelSeleccionado();
		void CambiarEstadoNivel();

		void Actualizar();

		void Renderizar();

};

#endif