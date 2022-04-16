#include "AdminJuego.h"
#include "Piso.h"

int main(int argc, char* argv[]) {

	srand(time(NULL));
	AdminJuego* juego = AdminJuego::Instancia();

	juego->Correr();

	AdminJuego::Liberar();
	juego = NULL;

	return 0;
}