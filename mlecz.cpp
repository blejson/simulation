#include "mlecz.h"
#include "Roslina.h"
#include <iostream>
using namespace std;

mlecz::mlecz(Swiat& world, const int &x, const int &y, const int &sila, const int &inicjatywa) :
	Roslina(world, x, y, sila, inicjatywa)
{

}
mlecz::~mlecz() {

}
void mlecz::rysowanie() {
	Organizm::rysowanie();
	cout << "M";
}
void mlecz::akcja() {
	for (int i = 0; i < 3; i++) {
		if (Roslina::rozsianie() == true) {

			world.organizmy.push_back(new mlecz(this->world, this->nx, this->ny));
		}
	}
}
/*void mlecz::kolizja() {
	cout << "XD";
}*/