#include "wilk.h"
#include "Zwierze.h"
#include <iostream>
using namespace std;

wilk::wilk(Swiat& world, const int &x, const int &y, const int &sila, const int &inicjatywa) :
	Zwierze(world, x, y, sila, inicjatywa)
{

}
wilk::~wilk() {

}
void wilk::rysowanie() {
	Organizm::rysowanie();
	cout << "W";
}
void wilk::kolizja(Organizm* n) {
	Zwierze::kolizja(n);
}
void wilk::dziecko() {
	if (this->rozmnazanie()) {
		world.organizmy.push_back(new wilk(this->world, this->nx, this->ny));
	}
}