#pragma once
#include <vector>
#include "Organizm.h"
using namespace std;
class Organizm;

class Swiat {
	int x, y, n = 3, z = 3, l_tur; //""n" i "z" to wsp�rz�dne lewego g�rnego k�ta ramki
public:
	vector<string> komentarze;
	vector<Organizm*>organizmy;
	string **plansza;
	Swiat(int x, int y);
	int getX();
	int getY();
	int getL_tur();
	void setL_tur(int nl);
	void wykonajTure();
	void rysujSwiat();
	void tworzPlansze();
	void komentator(Organizm* a, Organizm* b, string akt);
	~Swiat();

};