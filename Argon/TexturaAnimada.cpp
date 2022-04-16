#include "TexturaAnimada.h"

TexturaAnimada::TexturaAnimada(std::string nombreArchivo, int x, int y, int w, int h, int ContadorImagen, float VelocidadAnimacion, ANIM_DIR direccionAnimacion)
	: Textura(nombreArchivo, x, y, w, h)
{
	mTemporizador = Temporizador::Instancia();

	mComienzoX = x;
	mComienzoY = y;

	mContadorImagen = ContadorImagen;
	mVelocidadAnimacion = VelocidadAnimacion;
	mTiempoPorImagen = mVelocidadAnimacion / mContadorImagen;
	mTiempoAnimacion = 0.0f;

	mDireccionAnimacion = direccionAnimacion;

	mAnimacionHecha = false;

	mWrapMode = loop;
}

TexturaAnimada::~TexturaAnimada() {


}

void TexturaAnimada::WrapMode(WRAP_MODE mode) {

	mWrapMode = mode;
}

void TexturaAnimada::Actualizar() {

	if (!mAnimacionHecha) {
		
		mTiempoAnimacion += mTemporizador->TiempoDelta();

		if (mTiempoAnimacion >= mVelocidadAnimacion) {

			if (mWrapMode == loop) {

				mTiempoAnimacion -= mVelocidadAnimacion;
			}
			else {
				
				mAnimacionHecha = true;
				mTiempoAnimacion = mVelocidadAnimacion - mTiempoPorImagen;
			}
		}

		if (mDireccionAnimacion == horizontal) {

			mRectCortado.x = mComienzoX + (int)(mTiempoAnimacion / mTiempoPorImagen) * mAncho;
		}
		else {
			mRectCortado.y = mComienzoY + (int)(mTiempoAnimacion / mTiempoPorImagen) * mAlto;
		}
	}
}