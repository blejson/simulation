#pragma once
#include "Swiat.h"
#include "Organizm.h"
#include "Roslina.h"
#include"Zwierze.h"
#include<iostream>
using namespace std;
class Organizm;
class Roslina;
class owca : public Zwierze {
public:
	owca(Swiat& world, const int &x = 0, const int &y = 0, const int &sila = 4, const int &inicjatywa = 4);
	//void akcja() override;
	void kolizja(Organizm* n) override;
	void rysowanie() override;
	void dziecko() override;
	~owca() override;
};
