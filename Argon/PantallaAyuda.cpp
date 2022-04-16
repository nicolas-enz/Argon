#include "PantallaAyuda.h"

PantallaAyuda::PantallaAyuda() {

	Explicaciones = new EntidadJuego(Graficos::Instancia()->ANCHO_PANTALLA*0.5f, Graficos::Instancia()->ALTO_PANTALLA*0.4f);
	Explicaciones->Padre(this);

	mExplicacionFuerza = new Textura("Fuerza: En base a esta estadistica se calcula el daño fisico. Aumentarla aumenta este daño fisico.", "fonts/OpenSans-ExtraBold.ttf", 15, { 230, 230, 230 });
	mExplicacionFuerza->Padre(Explicaciones);
	mExplicacionFuerza->Pos(Vector2(0.0f, -240.0f));
	
	mExplicacionVigor = new Textura("Vigor: En base a esta estadistica se calcula la vida maxima. Aumentarla aumenta la vida maxima.", "fonts/OpenSans-ExtraBold.ttf", 15, { 230, 230, 230 });
	mExplicacionVigor->Padre(Explicaciones);
	mExplicacionVigor->Pos(Vector2(0.0f, -200.0f));

	mExplicacionInteligencia = new Textura("Inteligencia: En base a esta estadistica se calcula el daño magico y el mana. Aumentarla aumenta el daño magico y el mana.", "fonts/OpenSans-ExtraBold.ttf", 15, { 230, 230, 230 });
	mExplicacionInteligencia->Padre(Explicaciones);
	mExplicacionInteligencia->Pos(Vector2(0.0f, -160.0f));

	mExplicacionDestreza = new Textura("Destreza: En base a esta estadistica se calcula la chance de golpe critico. Aumentarla aumenta la chance de golpe critico.", "fonts/OpenSans-ExtraBold.ttf", 15, { 230, 230, 230 });
	mExplicacionDestreza->Padre(Explicaciones);
	mExplicacionDestreza->Pos(Vector2(0.0f, -120.0f));

	mExplicacionCritico = new Textura("Chance Critico: Es la probabilidad de que un golpe fisico sea critico, es decir que realize el doble del daño esperado.", "fonts/OpenSans-ExtraBold.ttf", 15, { 230, 230, 230 });
	mExplicacionCritico->Padre(Explicaciones);
	mExplicacionCritico->Pos(Vector2(0.0f, -80.0f));

	mExplicacionAtaque = new Textura("Ataque: El jugador realiza un ataque en base a su daño fisico. Tiene probabilidad de ser critico.", "fonts/OpenSans-ExtraBold.ttf", 15, { 230, 230, 230 });
	mExplicacionAtaque->Padre(Explicaciones);
	mExplicacionAtaque->Pos(Vector2(0.0f, -40.0f));

	mExplicacionDefensa = new Textura("Defensa: El jugador se defiende en un 100% el daño recibido en 1 turno", "fonts/OpenSans-ExtraBold.ttf", 15, { 230, 230, 230 });
	mExplicacionDefensa->Padre(Explicaciones);
	mExplicacionDefensa->Pos(Vector2(0.0f, 0.0f));
	
	mExplicacionMagia = new Textura("Magia: El jugador realiza un ataque en base a su daño magico. No puede ser critico.", "fonts/OpenSans-ExtraBold.ttf", 15, { 230, 230, 230 });
	mExplicacionMagia->Padre(Explicaciones);
	mExplicacionMagia->Pos(Vector2(0.0f, 40.0f));

	mExplicacionParry = new Textura("Parry: El jugador se defiende un 50% del daño y realiza un ataque por el 50% del daño fisico. No puede ser critico.", "fonts/OpenSans-ExtraBold.ttf", 15, { 230, 230, 230 });
	mExplicacionParry->Padre(Explicaciones);
	mExplicacionParry->Pos(Vector2(0.0f, 80.0f));

	mIconoEnemigo = new Textura("sprites/enemigo.png");
	mIconoEnemigo->Padre(Explicaciones);
	mIconoEnemigo->Pos(Vector2(-200.0f, 120.0f));

	mExplicacionEnemigo = new Textura("Enemigo: Enfrentamiento contra un enemigo.", "fonts/OpenSans-ExtraBold.ttf", 15, { 230, 230, 230 });
	mExplicacionEnemigo->Padre(Explicaciones);
	mExplicacionEnemigo->Pos(Vector2(0.0f, 120.0f));

	mIconoMercader = new Textura("sprites/tienda.png");
	mIconoMercader->Padre(Explicaciones);
	mIconoMercader->Pos(Vector2(-350.0f, 160.0f));

	mExplicacionMercader = new Textura("Mercader: El jugador puede aumentar sus estadisticas o curarse a cambio de oro.", "fonts/OpenSans-ExtraBold.ttf", 15, { 230, 230, 230 });
	mExplicacionMercader->Padre(Explicaciones);
	mExplicacionMercader->Pos(Vector2(0.0f, 160.0f));

	mIconoCofre = new Textura("sprites/cofre.png");
	mIconoCofre->Padre(Explicaciones);
	mIconoCofre->Pos(Vector2(-240.0f, 200.0f));

	mExplicacionCofre = new Textura("Cofre: El jugador recibe una cantidad aleatoria de oro.", "fonts/OpenSans-ExtraBold.ttf", 15, { 230, 230, 230 });
	mExplicacionCofre->Padre(Explicaciones);
	mExplicacionCofre->Pos(Vector2(0.0f, 200.0f));

	mIconoFogata = new Textura("sprites/fogata.png");
	mIconoFogata->Padre(Explicaciones);
	mIconoFogata->Pos(Vector2(-435.0f, 240.0f));

	mExplicacionFogata = new Textura("Fogata: El jugador puede elegir entre curarse 50% de su vida maxima o aumentar estadisticas (3 puntos).", "fonts/OpenSans-ExtraBold.ttf", 15, { 230, 230, 230 });
	mExplicacionFogata->Padre(Explicaciones);
	mExplicacionFogata->Pos(Vector2(0.0f, 240.0f));

	mIconoJefe = new Textura("sprites/jefe.png");
	mIconoJefe->Padre(Explicaciones);
	mIconoJefe->Pos(Vector2(-200.0f, 280.0f));

	mExplicacionJefe = new Textura("Jefe: Enfrentamiento contra el jefe del piso.", "fonts/OpenSans-ExtraBold.ttf", 15, { 230, 230, 230 });
	mExplicacionJefe->Padre(Explicaciones);
	mExplicacionJefe->Pos(Vector2(0.0f, 280.0f));
}

PantallaAyuda::~PantallaAyuda() {

	delete mExplicacionFuerza;
	mExplicacionFuerza = NULL;

	delete mExplicacionVigor;
	mExplicacionVigor = NULL;

	delete mExplicacionInteligencia;
	mExplicacionInteligencia = NULL;

	delete mExplicacionDestreza;
	mExplicacionDestreza = NULL;

	delete mExplicacionCritico;
	mExplicacionCritico = NULL;

	delete mExplicacionAtaque;
	mExplicacionAtaque = NULL;

	delete mExplicacionDefensa;
	mExplicacionDefensa = NULL;

	delete mExplicacionMagia;
	mExplicacionMagia = NULL;

	delete mExplicacionParry;
	mExplicacionParry = NULL;

	delete mIconoEnemigo;
	mIconoEnemigo = NULL;

	delete mExplicacionEnemigo;
	mExplicacionEnemigo = NULL;

	delete mIconoMercader;
	mIconoMercader = NULL;

	delete mExplicacionMercader;
	mExplicacionMercader = NULL;

	delete mIconoCofre;
	mIconoCofre = NULL;

	delete mExplicacionCofre;
	mExplicacionCofre = NULL;

	delete mIconoFogata;
	mIconoFogata = NULL;

	delete mExplicacionFogata;
	mExplicacionFogata = NULL;

	delete mIconoJefe;
	mIconoJefe = NULL;

	delete mExplicacionJefe;
	mExplicacionJefe = NULL;
}

void PantallaAyuda::Renderizar() {

	mExplicacionFuerza->Renderizar();
	mExplicacionVigor->Renderizar();
	mExplicacionInteligencia->Renderizar();
	mExplicacionDestreza->Renderizar();
	mExplicacionCritico->Renderizar();
	mExplicacionAtaque->Renderizar();
	mExplicacionDefensa->Renderizar();
	mExplicacionMagia->Renderizar();
	mExplicacionParry->Renderizar();

	mIconoEnemigo->Renderizar();
	mExplicacionEnemigo->Renderizar();

	mIconoCofre->Renderizar();
	mExplicacionCofre->Renderizar();

	mIconoMercader->Renderizar();
	mExplicacionMercader->Renderizar();

	mIconoFogata->Renderizar();
	mExplicacionFogata->Renderizar();

	mIconoJefe->Renderizar();
	mExplicacionJefe->Renderizar();
}