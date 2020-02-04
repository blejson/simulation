#pragma once
#include "Swiat.h"
#include "Organizm.h"
#include "Roslina.h"
#include"Zwierze.h"
#include<iostream>
using namespace std;
class Organizm;
class Roslina;
class czlowiek : public Zwierze {
	int start=0; //nr tury w której zosta³a ostatnio uruchomiona akcja, je¿eli akcja == 0 to nie zosta³a ona jeszcze ani razu wykonana
public:
	czlowiek(Swiat& world, const int &x = 0, const int &y = 0, const int &sila = 5, const int &inicjatywa = 4);
	void akcja() override;
	void kolizja(Organizm* n) override;
	void rysowanie() override;
	void dziecko() override;
	void setStart(int ns);
	int getStart();
	~czlowiek() override;
};
