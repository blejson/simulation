#include "owca.h"
#include "Zwierze.h"
#include <iostream>
using namespace std;

owca::owca(Swiat& world, const int &x, const int &y, const int &sila, const int &inicjatywa) :
	Zwierze(world, x, y, sila, inicjatywa)
{

}
owca::~owca() {

}
void owca::rysowanie() {
	Organizm::rysowanie();
	cout << "O";
}
void owca::kolizja(Organizm* n) {
	Zwierze::kolizja(n);
}
void owca::dziecko() {
	if (this->rozmnazanie()) {
		world.organizmy.push_back(new owca(this->world, this->nx, this->ny));
	}
}