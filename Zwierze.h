#pragma once
#include "Swiat.h"
#include "Organizm.h"
#include<iostream>
using namespace std;
class Swiat;
class Zwierze : public Organizm {
public:
	Zwierze(Swiat& world, const int &x = 0, const int &y = 0, const int &sila = 0, const int &inicjatywa = 0);
	virtual void akcja() override;
	virtual void kolizja(Organizm* n);
	virtual bool rozmnazanie();
	virtual void dziecko()=0;
	virtual ~Zwierze();
};
