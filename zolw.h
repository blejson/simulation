#pragma once
#include "Swiat.h"
#include "Organizm.h"
#include "Roslina.h"
#include"Zwierze.h"
#include<iostream>
using namespace std;
class Organizm;
class Roslina;
class zolw : public Zwierze {
public:
	zolw(Swiat& world, const int &x = 0, const int &y = 0, const int &sila = 2, const int &inicjatywa = 1);
	void akcja() override;
	void kolizja(Organizm* n) override;
	void rysowanie() override;
	void dziecko() override;
	~zolw() override;
};


