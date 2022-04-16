#include "AdminPantalla.h"

AdminPantalla* AdminPantalla::sInstancia = NULL;

AdminPantalla* AdminPantalla::Instancia() {

	if (sInstancia == NULL) {

		sInstancia = new AdminPantalla();
	}

	return sInstancia;
}

void AdminPantalla::Liberar() {
	
	delete sInstancia;
	sInstancia = NULL;
}

AdminPantalla::AdminPantalla() {

	mJugador = new Jugador();

	mEntradas = AdminEntradas::Instancia();
	mAudio = AdminAudio::Instancia();
	mAudio->Volumen(10);
	mAudio->PlayMusica("music/musica.mp3", -1);

	mPantallaInicio = new PantallaInicio();
	mPantallaOpciones = new PantallaOpciones(mJugador, mAudio);
	mPantallaMapa = new PantallaMapa(mJugador);
	mPantallaPelea = new PantallaPelea(mJugador);
	mPantallaGameOver = new PantallaGameOver();
	mPantallaCofre = new PantallaCofre(mJugador);
	mPantallaMercader = new PantallaMercader(mJugador);
	mPantallaContinuar = new PantallaContinuar();
	mPantallaAyuda = new PantallaAyuda();
	mPantallaJefe = new PantallaJefe(mJugador);
	mPantallaFogata = new PantallaFogata(mJugador);
	mPantallaVictoria = new PantallaVictoria();

	mPantallaActual = inicio;
}

AdminPantalla::~AdminPantalla() {

	mEntradas = NULL;
	mAudio = NULL;

	delete mPantallaInicio;
	mPantallaInicio = NULL;

	delete mPantallaOpciones;
	mPantallaOpciones = NULL;

	delete mPantallaMapa;
	mPantallaMapa = NULL;

	delete mPantallaPelea;
	mPantallaPelea = NULL;
	
	delete mPantallaGameOver;
	mPantallaGameOver = NULL;

	delete mPantallaCofre;
	mPantallaCofre = NULL;

	delete mPantallaMercader;
	mPantallaMercader = NULL;

	delete mPantallaContinuar;
	mPantallaContinuar = NULL;

	delete mPantallaAyuda;
	mPantallaAyuda = NULL;

	delete mPantallaJefe;
	mPantallaJefe = NULL;

	delete mPantallaFogata;
	mPantallaFogata = NULL;

	delete mPantallaVictoria;
	mPantallaVictoria = NULL;

	delete mJugador;
	mJugador = NULL;
}

void AdminPantalla::Actualizar() {

	switch (mPantallaActual) {

		case inicio:

			mPantallaInicio->Actualizar();

			if (mEntradas->TeclaPresionada(SDL_SCANCODE_RETURN)) {
				
				if (mPantallaInicio->ModoSeleccionado() == 0) {
					mPantallaAnterior = inicio;
					mPantallaActual = mapa;
					mAudio->PlayMusica("music/bg-musica.mp3", -1);
				}
				else if (mPantallaInicio->ModoSeleccionado() == 1) {
					mPantallaAnterior = inicio;
					mPantallaActual = opciones;
				}
				else if (mPantallaInicio->ModoSeleccionado() == 2)
					exit(0);

				mPantallaInicio->ResetearAnimacion();
			}
			break;

		case mapa:

			mPantallaMapa->Actualizar();

			if (mEntradas->TeclaPresionada(SDL_SCANCODE_ESCAPE)) {
				mPantallaAnterior = mapa;
				mPantallaActual = continuar;
				mAudio->PlayMusica("music/musica.mp3", -1);
			}
			else if (mEntradas->TeclaPresionada(SDL_SCANCODE_O)) {
				mPantallaAnterior = mapa;
				mPantallaActual = opciones;
			}
			else if (mEntradas->TeclaPresionada(SDL_SCANCODE_RETURN)) {
				system("cls");
				if (mPantallaMapa->Accesible()) {
					if (mPantallaMapa->TipoNivelSeleccionado() == 1) {
						mPantallaAnterior = mapa;
						mPantallaActual = pelea;
					}
					else if (mPantallaMapa->TipoNivelSeleccionado() == 2) {
						mPantallaAnterior = mapa;
						mPantallaActual = mercader;
					}
					else if (mPantallaMapa->TipoNivelSeleccionado() == 3) {
						mPantallaAnterior = mapa;
						mPantallaActual = fogata;
					}
					else if (mPantallaMapa->TipoNivelSeleccionado() == 4) {
						mPantallaAnterior = mapa;
						mPantallaActual = cofre;
					}
					else if (mPantallaMapa->TipoNivelSeleccionado() == 5) {
						mPantallaAnterior = mapa;
						mPantallaActual = jefe;
					}
				}
			}
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_H)) {
				mPantallaAnterior = mapa;
				mPantallaActual = ayuda;
			}
			break;

		case opciones:

			mPantallaOpciones->Actualizar();

			if (mEntradas->TeclaPresionada(SDL_SCANCODE_ESCAPE)) {
				if (mPantallaAnterior == inicio) {
					mPantallaActual = inicio;
				}
				else if (mPantallaAnterior == mapa) {
					mPantallaActual = mapa;
				}
				else if (mPantallaAnterior == continuar) {
					mPantallaActual = continuar;
				}
				else if (mPantallaAnterior == mercader) {
					mPantallaActual = mercader;
				}
				else if (mPantallaAnterior == fogata) {
					mPantallaActual = fogata;
				}
				else if (mPantallaAnterior == cofre) {
					mPantallaActual = cofre;
				}
				else if (mPantallaAnterior == jefe) {
					mPantallaActual = jefe;
				}
				else if (mPantallaAnterior == pelea) {
					mPantallaActual = pelea;
				}
			}
			break;

		case pelea:

			mPantallaPelea->Actualizar();

			if (mEntradas->TeclaPresionada(SDL_SCANCODE_ESCAPE)) {
				mPantallaAnterior = pelea;
				mPantallaActual = continuar;
				mAudio->PlayMusica("music/musica.mp3", -1);
			}
			if (mPantallaPelea->Terminada()) {
				if (mJugador->VidaRestante() > 0) {
					mPantallaActual = mapa;
					mPantallaMapa->CambiarAccesibilidad();

					mJugador->RecuperarVida10();

					delete mPantallaPelea;
					mPantallaPelea = NULL;
					mPantallaPelea = new PantallaPelea(mJugador);
					mPantallaMapa->CambiarEstadoNivel();
				}
				else if (mJugador->VidaRestante() <= 0) {
					mPantallaActual = gameOver;
				}
			}
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_O)) {
				mPantallaAnterior = pelea;
				mPantallaActual = opciones;
			}
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_H)) {
				mPantallaAnterior = pelea;
				mPantallaActual = ayuda;
			}
			
			break;

		case cofre:

			mPantallaCofre->Actualizar();
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_S)) {
				mPantallaActual = mapa;
				mPantallaMapa->CambiarAccesibilidad();

				delete mPantallaCofre;
				mPantallaCofre = NULL;
				mPantallaCofre = new PantallaCofre(mJugador);
			}
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_ESCAPE)) {
				mPantallaAnterior = cofre;
				mPantallaActual = continuar;
				mAudio->PlayMusica("music/musica.mp3", -1);
			}
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_O)) {
				mPantallaAnterior = cofre;
				mPantallaActual = opciones;
			}
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_H)) {
				mPantallaAnterior = cofre;
				mPantallaActual = ayuda;
			}
			break;

		case mercader:
			mPantallaMercader->Actualizar();

			if (mEntradas->TeclaPresionada(SDL_SCANCODE_S)) {
				mPantallaActual = mapa;
				mPantallaMapa->CambiarAccesibilidad();

				delete mPantallaMercader;
				mPantallaMercader = NULL;
				mPantallaMercader = new PantallaMercader(mJugador);
			}
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_ESCAPE)) {
				mPantallaAnterior = mercader;
				mPantallaActual = continuar;
				mAudio->PlayMusica("music/musica.mp3", -1);
			}
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_O)) {
				mPantallaAnterior = mercader;
				mPantallaActual = opciones;
			}
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_H)) {
				mPantallaAnterior = mercader;
				mPantallaActual = ayuda;
			}
			break;

		case fogata:
			mPantallaFogata->Actualizar();

			if (mEntradas->TeclaPresionada(SDL_SCANCODE_S)) {
				mPantallaActual = mapa;
				mPantallaMapa->CambiarAccesibilidad();
				
				delete mPantallaFogata;
				mPantallaFogata = NULL;
				mPantallaFogata = new PantallaFogata(mJugador);
			}
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_ESCAPE)) {
				mPantallaAnterior = fogata;
				mPantallaActual = continuar;
				mAudio->PlayMusica("music/musica.mp3", -1);
			}
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_O)) {
				mPantallaAnterior = fogata;
				mPantallaActual = opciones;
			}
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_H)) {
				mPantallaAnterior = fogata;
				mPantallaActual = ayuda;
			}
			break;

		case jefe:
			mPantallaJefe->Actualizar();

			if (mPantallaJefe->Terminada()) {
				if (mJugador->VidaRestante() > 0) {
					mJugador->SubirPiso();
					if (mJugador->Piso() < 3) {
						mPantallaActual = mapa;

						delete mPantallaJefe;
						mPantallaJefe = NULL;
						mPantallaJefe = new PantallaJefe(mJugador);

						delete mPantallaPelea;
						mPantallaPelea = NULL;
						mPantallaPelea = new PantallaPelea(mJugador);

						delete mPantallaMapa;
						mPantallaMapa = NULL;
						mPantallaMapa = new PantallaMapa(mJugador);

						delete mPantallaCofre;
						mPantallaCofre = NULL;
						mPantallaCofre = new PantallaCofre(mJugador);

						delete mPantallaMercader;
						mPantallaMercader = NULL;
						mPantallaMercader = new PantallaMercader(mJugador);

						delete mPantallaFogata;
						mPantallaFogata = NULL;
						mPantallaFogata = new PantallaFogata(mJugador);
					}
					else {
						mPantallaActual = victoria;
					}
					
				}
				else if (mJugador->VidaRestante() <= 0) {
					mPantallaActual = gameOver;
				}
			}
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_ESCAPE)) {
				mPantallaAnterior = jefe;
				mPantallaActual = continuar;
				mAudio->PlayMusica("music/musica.mp3", -1);
			}
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_O)) {
				mPantallaAnterior = jefe;
				mPantallaActual = opciones;
			}
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_H)) {
				mPantallaAnterior = jefe;
				mPantallaActual = ayuda;
			}
			break;

		case ayuda:
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_ESCAPE)) {
				if (mPantallaAnterior == mapa) {
					mPantallaActual = mapa;
				}
				else if (mPantallaAnterior == mercader) {
					mPantallaActual = mercader;
				}
				else if (mPantallaAnterior == fogata) {
					mPantallaActual = fogata;
				}
				else if (mPantallaAnterior == cofre) {
					mPantallaActual = cofre;
				}
				else if (mPantallaAnterior == jefe) {
					mPantallaActual = jefe;
				}
				else if (mPantallaAnterior == pelea) {
					mPantallaActual = pelea;
				}
			}
			break;

		case continuar:
			mPantallaContinuar->Actualizar();
			
			if (mEntradas->TeclaPresionada(SDL_SCANCODE_RETURN)) {
				
				if (mPantallaContinuar->ModoSeleccionado() == 0) {
					mAudio->PlayMusica("music/bg-musica.mp3", -1);
					if (mPantallaAnterior == mapa) {
						mPantallaActual = mapa;
					}
					else if (mPantallaAnterior == mercader) {
						mPantallaActual = mercader;
					}
					else if (mPantallaAnterior == fogata) {
						mPantallaActual = fogata;
					}
					else if (mPantallaAnterior == cofre) {
						mPantallaActual = cofre;
					}
					else if (mPantallaAnterior == jefe) {
						mPantallaActual = jefe;
					}
					else if (mPantallaAnterior == pelea) {
						mPantallaActual = pelea;
					}
				}
				else if (mPantallaContinuar->ModoSeleccionado() == 1) {

					mAudio->PlayMusica("music/bg-musica.mp3", -1);
					system("cls");

					delete mJugador;
					mJugador = NULL;
					mJugador = new Jugador();

					delete mPantallaPelea;
					mPantallaPelea = NULL;
					mPantallaPelea = new PantallaPelea(mJugador);

					delete mPantallaMapa;
					mPantallaMapa = NULL;
					mPantallaMapa = new PantallaMapa(mJugador);

					delete mPantallaCofre;
					mPantallaCofre = NULL;
					mPantallaCofre = new PantallaCofre(mJugador);

					delete mPantallaMercader;
					mPantallaMercader = NULL;
					mPantallaMercader = new PantallaMercader(mJugador);
					
					delete mPantallaFogata;
					mPantallaFogata = NULL;
					mPantallaFogata = new PantallaFogata(mJugador);
					
					delete mPantallaJefe;
					mPantallaJefe = NULL;
					mPantallaJefe = new PantallaJefe(mJugador);
					
					mPantallaActual = mapa;
				}
				else if (mPantallaContinuar->ModoSeleccionado() == 2) {
					mPantallaAnterior = continuar;
					mPantallaActual = opciones;
				}
				else if (mPantallaContinuar->ModoSeleccionado() == 3)
					exit(0);

			}
			break;

		case victoria:

			mPantallaVictoria->Actualizar();

			if (mEntradas->TeclaPresionada(SDL_SCANCODE_ESCAPE)) {
				mPantallaActual = inicio;
				mAudio->PlayMusica("music/musica.mp3", -1);
				delete mJugador;
				mJugador = NULL;
				mJugador = new Jugador();

				delete mPantallaPelea;
				mPantallaPelea = NULL;
				mPantallaPelea = new PantallaPelea(mJugador);

				delete mPantallaMapa;
				mPantallaMapa = NULL;
				mPantallaMapa = new PantallaMapa(mJugador);

				delete mPantallaCofre;
				mPantallaCofre = NULL;
				mPantallaCofre = new PantallaCofre(mJugador);

				delete mPantallaMercader;
				mPantallaMercader = NULL;
				mPantallaMercader = new PantallaMercader(mJugador);

				delete mPantallaFogata;
				mPantallaFogata = NULL;
				mPantallaFogata = new PantallaFogata(mJugador);

				delete mPantallaJefe;
				mPantallaJefe = NULL;
				mPantallaJefe = new PantallaJefe(mJugador);
			}
			break;

		case gameOver:

			mPantallaGameOver->Actualizar();

			if (mEntradas->TeclaPresionada(SDL_SCANCODE_ESCAPE)) {
				mPantallaActual = inicio;
				mAudio->PlayMusica("music/musica.mp3", -1);
				delete mJugador;
				mJugador = NULL;
				mJugador = new Jugador();

				delete mPantallaPelea;
				mPantallaPelea = NULL;
				mPantallaPelea = new PantallaPelea(mJugador);

				delete mPantallaMapa;
				mPantallaMapa = NULL;
				mPantallaMapa = new PantallaMapa(mJugador);

				delete mPantallaCofre;
				mPantallaCofre = NULL;
				mPantallaCofre = new PantallaCofre(mJugador);

				delete mPantallaMercader;
				mPantallaMercader = NULL;
				mPantallaMercader = new PantallaMercader(mJugador);
				
				delete mPantallaFogata;
				mPantallaFogata = NULL;
				mPantallaFogata = new PantallaFogata(mJugador);

				delete mPantallaJefe;
				mPantallaJefe = NULL;
				mPantallaJefe = new PantallaJefe(mJugador);
				
			}
			break;

	}
}

void AdminPantalla::Renderizar() {

	switch (mPantallaActual) {
		case inicio:
			mPantallaInicio->Renderizar();
			break;

		case opciones:
			mPantallaOpciones->Renderizar();
			break;

		case mapa:
			mPantallaMapa->Renderizar();
			break;

		case pelea:
			mPantallaPelea->Renderizar();
			break;

		case cofre:
			mPantallaCofre->Renderizar();
			break;

		case mercader:
			mPantallaMercader->Renderizar();
			break;

		case fogata:
			mPantallaFogata->Renderizar();
			break;

		case jefe:
			mPantallaJefe->Renderizar();
			break;

		case victoria:
			mPantallaVictoria->Renderizar();
			break;

		case gameOver:
			mPantallaGameOver->Renderizar();
			break;

		case ayuda:
			mPantallaAyuda->Renderizar();
			break;

		case continuar:
			mPantallaContinuar->Renderizar();
			break;
	}
	
}