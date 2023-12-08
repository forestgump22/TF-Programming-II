#pragma once
#include"CPersona.h"

class CHabitante:public CPersona
{
public:
	CHabitante(int px, int py) :CPersona(px, py){
		activo = true;
		TimepoProc = NULL;
		velocidad = 5;
		//dx = rand() % 2 * (-10) + 5;
		//dy = rand() % 2 * (-10) + 5;
		itmsj = rand() % 7;
	}
	~CHabitante()
	{
	}
	void movinval() {
		dx = rand() % 2 * (-10) + 5;
		dy = rand() % 2 * (-10) + 5;
	}
	bool getactivo() {
		return activo;
	}
	time_t getTProceso() {
		return TimepoProc;
	}
	void setactivo(int v){
		this->activo = v;
	}
	void setTiempoProc(time_t v) {
		this->TimepoProc = v;
	}
	int getresistencia() {
		resistencia++;
		return resistencia;
	}
	void setresistencia(){
		this->resistencia = 0;
	}
	
	void setcontmsj(int v) {
		itmsj = v;
	}
	int getitmsj() {
		return itmsj;
	}
private:
	time_t TimepoProc;
	bool activo;
	int resistencia = 0;
	int itmsj;
};



