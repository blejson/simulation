#pragma once
#include "Swiat.h"
#include "Organizm.h"
#include "Roslina.h"
#include<iostream>
using namespace std;
class Organizm;
class Roslina;
class trawa : public Roslina {
public:
	trawa(Swiat& world, const int &x = 0, const int &y = 0, const int &sila = 0, const int &inicjatywa = 0);
	void akcja() override;
	//void kolizja() override;
	void rysowanie() override;
	~trawa() override;
};
