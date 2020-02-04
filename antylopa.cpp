#include "antylopa.h"
#include "Zwierze.h"
#include <iostream>
using namespace std;

antylopa::antylopa(Swiat& world, const int &x, const int &y, const int &sila, const int &inicjatywa) :
	Zwierze(world, x, y, sila, inicjatywa)
{

}
antylopa::~antylopa() {

}
void antylopa::rysowanie() {
	Organizm::rysowanie();
	cout << "A";
}
void antylopa::kolizja(Organizm* n) {
	Zwierze::kolizja(n);
}
void antylopa::dziecko() {
	if (Zwierze::rozmnazanie()) {
		world.organizmy.push_back(new antylopa(this->world, this->nx, this->ny));
	}
}