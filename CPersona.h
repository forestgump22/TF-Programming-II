#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<time.h>
using namespace std;
using namespace System;
using namespace System::Drawing;
class CPersona
{
protected:
	int x, y, columnas, filas, dx, dy;
	int intimg; int direccion; int velocidad;
	int cercano;
public:
	CPersona(int px, int py)
	{
		x = px;
		y = py;
		columnas = 75;
		filas = 75;
		dx = 0; dy = 0;
		intimg = 1;
		direccion = 3;
		cercano = 0;
	}
	~CPersona()	{}
	void dibujar(Graphics^ g, Bitmap^ img)	{
		direccion = 0;
		if (dx < 0) { direccion = 1; }
		else
			if (dx > 0) { direccion = 2; }
			else
				if (dy < 0) { direccion = 3; }
				else
					if (dy > 0) { direccion = 0; }
					else { intimg = 1; }

		g->DrawImage(img, Rectangle(x, y,
			columnas * 1.0, filas * 1.0),
			Rectangle(img->Width / 3 * intimg,
				img->Height / 4 * direccion,
				img->Width / 3, img->Height / 4),
			GraphicsUnit::Pixel);
		intimg++;
		if (intimg == 2)intimg = 0;
	}
	bool colision(Rectangle rec){
		return getrec().IntersectsWith(rec);
	}

	Rectangle getrec()	{
		return Rectangle(x, y, columnas, filas);
	}
	Rectangle getfutrec()	{
		return Rectangle(x + dx, y + dy, columnas, filas);
	}
	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}
	void setdx(int v) {
		this->dx = v;
	}
	void setdy(int v) {
		this->dy = v;
	}
	void setDXDY() {
		dx = 5;
		dy = 5;
	}
	void setpositionNormal() {
		this->direccion = 0;
		this->intimg = 1;
	}
	void perseguir(CPersona* obj, int limx, int limy){
		int auxsimx = 1, auxsimy = 1;
		if (x + columnas / 2 > obj->getrec().X)auxsimx = -1;
		if (y + filas / 2 > obj->getrec().Y)auxsimy = -1;
		int distx = abs(obj->getrec().X - (x + columnas / 2));
		int disty = abs(obj->getrec().Y - (y + filas / 2));
		if (distx != 0) {
			float angulo = atan(float(disty) / distx);
			dx = cos(angulo) * velocidad * auxsimx;
			dy = sin(angulo) * velocidad * auxsimy;
		}
		else { dy = velocidad * auxsimy; }
	}
	virtual void movinval() {
		dx = 0; dy = 0;
	}
	void mover(int limx,int limy){
		if (x + dx<0 || x + dx + columnas>limx || y + dy<0 || y + dy + filas>limy)
		{
			movinval();
		}
		else
		{
			x += dx;
			y += dy;
		}
	}
	float getdist(CPersona* objper) {
		return sqrt(pow(objper->getX() - this->getX(), 2) +
			pow(objper->getY() - this->getY(), 2));
	}
	int getcercano() {
		return cercano;
	}
	void setcercano(int v) {
		this->cercano = v;
	}
	void reposicionar(Rectangle^ pantalla) {
		x = rand() % (pantalla->Width - columnas);
		y = rand() % (pantalla->Height - filas);
		dx = 0; dy = 0;
	}
};


