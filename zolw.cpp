#include "zolw.h"
#include "Zwierze.h"
#include <iostream>
using namespace std;

zolw::zolw(Swiat& world, const int &x, const int &y, const int &sila, const int &inicjatywa) :
	Zwierze(world, x, y, sila, inicjatywa)
{

}
zolw::~zolw() {

}
void zolw::rysowanie() {
	Organizm::rysowanie();
	cout << "Z";
}
void zolw::kolizja(Organizm* n) {
	Zwierze::kolizja(n);
}
void zolw::akcja() {
	int g = rand() % 4;
	if (g == 0) {
		Zwierze::akcja();
	}
}
void zolw::dziecko() {
	if (this->rozmnazanie()) {
		world.organizmy.push_back(new zolw(this->world, this->nx, this->ny));
	}
}