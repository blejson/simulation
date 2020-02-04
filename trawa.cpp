#include "trawa.h"
#include "Roslina.h"
#include <iostream>
using namespace std;

trawa::trawa(Swiat& world, const int &x, const int &y, const int &sila, const int &inicjatywa) :
	Roslina(world, x, y, sila, inicjatywa)
{

}
trawa::~trawa() {

}
void trawa::rysowanie() {
	Organizm::rysowanie();
	cout << "T";
}
void trawa::akcja() {
	if (Roslina::rozsianie() == true) {

		world.organizmy.push_back(new trawa(this->world, this->nx, this->ny));
	}
}/*void trawa::kolizja() {
	cout << "XD";
}*/