#pragma once
#include "Organizm.h"
#include "Swiat.h"


#include<iostream>
using namespace std;
class Swiat;
class Organizm;
class Roslina : public Organizm {
public:
	Roslina(Swiat& world, const int &x = 0, const int &y = 0, const int &sila = 0, const int &inicjatywa = 0);
	virtual void akcja() override;
	virtual ~Roslina();
	bool rozsianie();
};
