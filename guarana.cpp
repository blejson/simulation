#include "guarana.h"
#include "Roslina.h"
#include <iostream>
using namespace std;

guarana::guarana(Swiat& world, const int &x, const int &y, const int &sila, const int &inicjatywa) :
	Roslina(world, x, y, sila, inicjatywa)
{

}
guarana::~guarana() {

}
void guarana::rysowanie() {
	Organizm::rysowanie();
	cout << "G";
}
void guarana::akcja() {
	if (Roslina::rozsianie() == true) {

		world.organizmy.push_back(new guarana(this->world, this->nx, this->ny));
	}
}
/*void guarana::kolizja() {
	cout << "XD";
}*/