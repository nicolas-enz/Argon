#ifndef _ADMINPANTALLA_H
#define _ADMINPANTALLA_H
#include "PantallaInicio.h"
#include "PantallaOpciones.h"
#include "PantallaMapa.h"
#include "PantallaPelea.h"
#include "PantallaGameOver.h"
#include "PantallaMercader.h"
#include "PantallaCofre.h"
#include "PantallaContinuar.h"
#include "PantallaAyuda.h"
#include "PantallaJefe.h"
#include "PantallaFogata.h"
#include "PantallaVictoria.h"

class AdminPantalla {

	private:

		enum SCREENS { inicio, opciones, mapa, pelea, fogata, mercader, continuar, gameOver, cofre, jefe, ayuda, victoria };

		static AdminPantalla* sInstancia;

		AdminEntradas* mEntradas;
		AdminAudio* mAudio;

		PantallaInicio* mPantallaInicio;
		PantallaMapa* mPantallaMapa;
		PantallaOpciones* mPantallaOpciones;
		PantallaPelea* mPantallaPelea;
		PantallaGameOver* mPantallaGameOver;
		PantallaMercader* mPantallaMercader;
		PantallaCofre* mPantallaCofre;
		PantallaContinuar* mPantallaContinuar;
		PantallaAyuda* mPantallaAyuda;
		PantallaJefe* mPantallaJefe;
		PantallaFogata* mPantallaFogata;
		PantallaVictoria* mPantallaVictoria;

		Jugador* mJugador;

		SCREENS mPantallaActual;
		SCREENS mPantallaAnterior;

	public:

		static AdminPantalla* Instancia();
		static void Liberar();

		void Actualizar();
		void Renderizar();

	private:

		AdminPantalla();
		~AdminPantalla();
};

#endif