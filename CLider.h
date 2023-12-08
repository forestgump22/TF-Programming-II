#pragma once
#include"CPersona.h"
class CLider:public CPersona
{
public:
	CLider(int x, int y) :CPersona(200, 200)
	{
		this->x = x;
		this->y = y;
	}
	~CLider() {}

private:

};
