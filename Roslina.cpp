#include "Roslina.h"
#include "Organizm.h"
#include "Swiat.h"
#include <iostream>
#include <time.h>

using namespace std;

Roslina::Roslina(Swiat& world, const int &x, const int &y, const int &sila, const int &inicjatywa) :
	Organizm(world,x,y,sila,inicjatywa)
{

}
Roslina::~Roslina() {

}
void Roslina::akcja() {
	
}
bool Roslina::rozsianie() {
	if (int prawdopodobienstwo = rand() % 10 == 0) { //decyduje czy przemieszczenie zostanie wykonane
		int a;
		do {
				a = Organizm::losujPole();
				switch (a) {
				case 0: 
					this->nx = this->x-1;
					this->ny = this->y-1; 
					break;
				case 1: 
					this->nx = this->x;
					this->ny = this->y-1; 
					break;
				case 2: 
					this->nx = this->x+1;
					this->ny = this->y-1; break;
				case 3: 
					this->nx = this->x+1;
					this->ny = this->y; 
					break;
				case 4:
					this->nx = this->x+1;
					this->ny = this->y+1; 
					break;
				case 5: 
					this->nx = this->x;
					this->ny = this->y-1; 
					break;
				case 6: 
					this->nx = this->x-1;
					this->ny = this->y; 
					break;
				case 7: 
					this->nx = this->x-1;
					this->ny = this->y; 
					break;
				}
		} while (this->nx < 1 || this->ny < 1 || this->nx> world.getX() || this->ny> world.getY());
		bool wolne = true;
		for (auto n : world.organizmy) {
			if (n->getX() == this->nx) {
				if (n->getY() == this->ny) {
					wolne = false;
				}
			}
		}
		world.komentator(this, this, "rozmnaza sie");
		return wolne;
	}
	else return false;
}