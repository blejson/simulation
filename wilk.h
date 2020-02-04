#pragma once
#include "Swiat.h"
#include "Organizm.h"
#include "Roslina.h"
#include"Zwierze.h"
#include<iostream>
using namespace std;
class Organizm;
class Roslina;
class wilk : public Zwierze {
public:
	wilk(Swiat& world, const int &x = 0, const int &y = 0, const int &sila = 9, const int &inicjatywa = 5);
	//void akcja() override;
	void kolizja(Organizm* n) override;
	void rysowanie() override;
	void dziecko() override;
	~wilk() override;
};
