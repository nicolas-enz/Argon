#ifndef _PANTALLAAYUDA_H
#define _PANTALLAAYUDA_H
#include "Textura.h"

class PantallaAyuda : public EntidadJuego {

	private:

		EntidadJuego* Explicaciones;
		Textura* mExplicacionFuerza;
		Textura* mExplicacionVigor;
		Textura* mExplicacionInteligencia;
		Textura* mExplicacionDestreza;
		Textura* mExplicacionCritico;
		Textura* mExplicacionAtaque;
		Textura* mExplicacionDefensa;
		Textura* mExplicacionMagia;
		Textura* mExplicacionParry;
		Textura* mIconoEnemigo;
		Textura* mExplicacionEnemigo;
		Textura* mIconoCofre;
		Textura* mExplicacionCofre;
		Textura* mIconoMercader;
		Textura* mExplicacionMercader;
		Textura* mIconoFogata;
		Textura* mExplicacionFogata;
		Textura* mIconoJefe;
		Textura* mExplicacionJefe;

	public:

		PantallaAyuda();
		~PantallaAyuda();

		void Renderizar();
};

#endif