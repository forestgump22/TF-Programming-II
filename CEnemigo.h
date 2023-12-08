#pragma once
#include"CPersona.h"

class CEnemigo:public CPersona
{
public:
	CEnemigo(int limx, int limy) :CPersona(limx, limy)
	{
		x = rand() % 2 * (limx);
		y = rand() % 2 * (limy);
		dx = 1; dy = 1;
		velocidad = 2;
	}
	~CEnemigo() {}
	void rebote() {
		dx *= -20; dy *= -20;
	}
private:
};

