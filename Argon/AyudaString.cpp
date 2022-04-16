#include "AyudaString.h"

string NumeroIntACadena(int num) {
	string resultado;

	ostringstream convertir;

	convertir << num;

	resultado = convertir.str();

	return resultado;
}

string NumeroFloatACadena(float num) {
	string resultado;

	ostringstream convertir;

	convertir << num;

	resultado = convertir.str();

	return resultado;
}