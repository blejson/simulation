#pragma once
#include <iostream>
#include "Swiat.h"

class Swiat;
class Organizm {
protected:
	int x, y, nx, ny, sx, sy;
	int sila;
	int inicjatywa;
	int wiek = 0;
	Swiat& world;
public:
	virtual void akcja() = 0;
	//virtual void kolizja(Organizm* n) = 0;
	virtual void rysowanie();
	int losujPole();
	int getX();
	int getY();
	int getSila();
	int getInicjatywa();
	void setSila(int ns);
	void setX(int nx);
	void setY(int ny);
	int getWiek();
	void setWiek(int nw);
	Organizm(Swiat& world, const int &x=0, const int &y=0, const int &sila=0, const int &inicjatywa=0);
	~Organizm();
};

