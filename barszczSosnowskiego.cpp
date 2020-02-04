#include "barszczSosnowskiego.h"
#include "Roslina.h"
#include <iostream>
using namespace std;

barszczSosnowskiego::barszczSosnowskiego(Swiat& world, const int &x, const int &y, const int &sila, const int &inicjatywa) :
	Roslina(world, x, y, sila, inicjatywa)
{

}
barszczSosnowskiego::~barszczSosnowskiego() {

}
void barszczSosnowskiego::rysowanie() {
	Organizm::rysowanie();
	cout << "B";
}
void barszczSosnowskiego::akcja() {
		if (Roslina::rozsianie() == true) {

			world.organizmy.push_back(new barszczSosnowskiego(this->world, this->nx, this->ny));
		}
}
/*void barszczSosnowskiego::kolizja() {
	cout << "XD";
}*/