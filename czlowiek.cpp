#include "czlowiek.h"
#include "Zwierze.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
void _gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
czlowiek::czlowiek(Swiat& world, const int &x, const int &y, const int &sila, const int &inicjatywa) :
	Zwierze(world, x, y, sila, inicjatywa)
{
}
czlowiek::~czlowiek() {

}
void czlowiek::rysowanie() {
	Organizm::rysowanie();
	cout << "C";
}
void czlowiek::kolizja(Organizm* n) {
	Zwierze::kolizja(n);
}
int czlowiek::getStart() {
	return this->start;
}
void czlowiek::akcja() {
	_gotoxy(0, 1);
	cout << "Runda czlowieka. Wybierz strzalkami kierunek ruchu.      " << endl;
	if ((world.getL_tur() - this->getStart() > 9 || this->getStart() == 0))
		cout << "Kliknij a, aby uruchomic akcje specjalna czlowieka                         ";
	else
	cout << "                                                                  ";
	char inp, tmp;
	int dp = 1;
	do {
		inp = _getch();
		tmp = inp;
		if (inp == 97 && (world.getL_tur() - this->getStart() > 9|| this->getStart()==0)) this->setStart(world.getL_tur()); //"a" uruchamia akcjê
		if (this->getStart() != 0 && world.getL_tur() - this->getStart() < 5) dp = 2;
		if (inp == -32) {
			inp = _getch();
			switch (inp) {
			case 72:
				this->nx = this->getX();
				this->ny = this->getY()-dp;
				break;
			case 77:
				this->nx = this->getX()+dp;
				this->ny = this->getY();
				break;
			case 80:
				this->nx = this->getX();
				this->ny = this->getY() + dp;
				break;
			case 75:
				this->nx = this->getX()-dp;
				this->ny = this->getY();
				break;
			}

		}
	} while (tmp != -32 || this->nx < 1 || this->ny < 1 || this->nx> world.getX() || this->ny> world.getY());
	Zwierze::akcja();
}
void czlowiek::dziecko() {
	//nie wykona siê nigdy poniewa¿ cz³owiek jest tylko jeden
}
void czlowiek::setStart(int ns) {
	this->start = ns;
}