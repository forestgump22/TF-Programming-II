#pragma once
#include"CPersona.h"
class CAliado:public CPersona
{
public:
	CAliado(int xL, int yL, int tipo) :CPersona(xL, yL) {
		dx = 5; dy = 5; this->tipo = tipo; 
		velocidad = 5;
	}
	~CAliado() {}
	int gettipo() { return tipo; }
private:
	int tipo;
};
