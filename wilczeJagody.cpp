#include "wilczeJagody.h"
#include "Roslina.h"
#include <iostream>
using namespace std;

wilczeJagody::wilczeJagody(Swiat& world, const int &x, const int &y, const int &sila, const int &inicjatywa) :
	Roslina(world, x, y, sila, inicjatywa)
{

}
wilczeJagody::~wilczeJagody() {

}
void wilczeJagody::rysowanie() {
	Organizm::rysowanie();
	cout << "J";
}
void wilczeJagody::akcja() {
	if (Roslina::rozsianie() == true) {

		world.organizmy.push_back(new wilczeJagody(this->world, this->nx, this->ny));
	}
}/*void wilczeJagody::kolizja() {
	cout << "XD";
}*/