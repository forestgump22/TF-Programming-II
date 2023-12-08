#pragma once
#include"CPersona.h"
class CCreditos:public CPersona
{
public:
	CCreditos(Rectangle^ pantalla);
	~CCreditos();
	void dibujarcreditos(Graphics^ g, Bitmap^ bmpcreditos);
	void movercreditos( Bitmap^ bmpcreditos);
private:

};

CCreditos::CCreditos(Rectangle^ pantalla):CPersona(0,0){
	filas = pantalla->Height;
	columnas = pantalla->Width;
	dx = 0; dy = 10;
}

CCreditos::~CCreditos(){}

void CCreditos::dibujarcreditos(Graphics^ g,Bitmap^ bmpcreditos)
{
	g->DrawImage(bmpcreditos,Rectangle(0,0,columnas,filas),
		Rectangle(x, y, bmpcreditos->Width, bmpcreditos->Height / 2),GraphicsUnit::Pixel);
}

void CCreditos::movercreditos( Bitmap^ bmpcreditos)
{
	if (y+dy<bmpcreditos->Height/2){
		y += dy;
	}
}
