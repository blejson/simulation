#include "lis.h"
#include "Zwierze.h"
#include <iostream>
using namespace std;

lis::lis(Swiat& world, const int &x, const int &y, const int &sila, const int &inicjatywa) :
	Zwierze(world, x, y, sila, inicjatywa)
{

}
lis::~lis() {

}
void lis::rysowanie() {
	Organizm::rysowanie();
	cout << "L";
}
void lis::kolizja(Organizm* n) {
	Zwierze::kolizja(n);
}
void lis::dziecko() {
	if (this->rozmnazanie()) {
		world.organizmy.push_back(new lis(this->world, this->nx, this->ny));
	}
}