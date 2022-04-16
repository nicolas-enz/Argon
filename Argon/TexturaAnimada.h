#ifndef _TEXTURAANIMADA_H
#define _TEXTURAANIMADA_H
#include "Temporizador.h"
#include "Textura.h"

class TexturaAnimada : public Textura {
	public:

		enum WRAP_MODE { once = 0, loop = 1 };
		enum ANIM_DIR { horizontal = 0, vertical = 1};

	private:
		
		Temporizador * mTemporizador;

		int mComienzoX;
		int mComienzoY;

		float mTiempoAnimacion;
		float mVelocidadAnimacion;
		float mTiempoPorImagen;

		int mContadorImagen;

		WRAP_MODE mWrapMode;
		ANIM_DIR mDireccionAnimacion;

		bool mAnimacionHecha;

	public:
		TexturaAnimada(std::string nombreArchivo, int x, int y, int w, int h, int ContadorImagen, float VelocidadAnimacion, ANIM_DIR direccionAnimacion);
		~TexturaAnimada();

		void WrapMode(WRAP_MODE mode);

		void Actualizar();
};

#endif