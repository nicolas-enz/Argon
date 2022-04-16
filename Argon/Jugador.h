#ifndef _JUGADOR_H
#define _JUGADOR_H
#include "Textura.h"

class Jugador {

	private:

		// Estadisticas
		int mVigor;
		int mInteligencia;
		int mDestreza;
		int mFuerza;
		float mChanceCritico;
		float mAtaqueFisico;
		float mAtaqueMagico;
		int mVidaRestante;
		int mVida;
		int mManaRestante;
		int mMana;
		int mOro;

		int mTurno;
		int mPiso;

		bool SFX;
		bool Musica;

		Textura* mTex;

	public:

		Jugador();
		~Jugador();

		int Vigor();
		int Inteligencia();
		int Destreza();
		int Fuerza();
		float ChanceCritico();
		int AtaqueFisico();
		int AtaqueMagico();
		int VidaRestante();
		int Vida();
		int ManaRestante();
		int Mana();
		int Oro();

		bool GetSFX();
		bool GetMusica();

		int Turno();

		int Piso();

		void AumentarFuerza();
		void AumentarVigor();
		void AumentarInteligencia();
		void AumentarDestreza();
		void RecuperarVida100();
		void RecuperarVida50();
		void RecuperarVida30();
		void RecuperarVida10();
		void RecuperarMana();
		void Recompensa(int recompensa);

		void SubirPiso();
		void SiguienteTurno();
		void ResetiarTurno();

		void MusicaON();
		void SFXON();
		void MusicaOFF();
		void SFXOFF();

		void ReducirOro(int costo);
		void ReducirMana(int reduccion);
		void ReducirVida(int danio);

		void Renderizar();
		

};


#endif