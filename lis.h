#pragma once
#include "Swiat.h"
#include "Organizm.h"
#include "Roslina.h"
#include"Zwierze.h"
#include<iostream>
using namespace std;
class Organizm;
class Roslina;
class lis : public Zwierze {
public:
	lis(Swiat& world, const int &x = 0, const int &y = 0, const int &sila = 3, const int &inicjatywa = 7);
	void kolizja(Organizm* n) override;
	void rysowanie() override;
	void dziecko() override;
	~lis() override;
};

