#pragma once
#include"CPersona.h"
class CObjAleat:public CPersona
{
public:
	CObjAleat(Rectangle^pantalla,int tipo);
	~CObjAleat();
	void dibujarObjAlet(Graphics^ g, Bitmap^ bmpobj);
	int gettipo();
private:
	int tipo;
};

CObjAleat::CObjAleat(Rectangle^ pantalla,int tipo):CPersona(0,0)
{
	this->tipo = tipo;
	if (tipo==1){
		filas = 60;
		columnas = 40;
		y = rand() % (pantalla->Height - filas);
		x = rand() % (pantalla->Width - columnas);
	}else{
		filas = 200;
		columnas = 250;
		y = rand() % (pantalla->Height/2 - filas);
		x = rand() % (pantalla->Width/2 - columnas);
	}
	dx = 0; dy = 0;
}

CObjAleat::~CObjAleat(){}

void CObjAleat::dibujarObjAlet(Graphics^ g,Bitmap^ bmpobj){
	g->DrawImage(bmpobj, getrec(), Rectangle(0,0,bmpobj->Width,bmpobj->Height), GraphicsUnit::Pixel);
}

int CObjAleat::gettipo(){
	return tipo;
}
