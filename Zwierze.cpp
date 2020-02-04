#include "Zwierze.h"
#include "Organizm.h"
#include "Swiat.h"
#include <iostream>
using namespace std;

Zwierze::Zwierze(Swiat& world, const int &x, const int &y, const int &sila, const int &inicjatywa) :
	Organizm(world, x, y, sila, inicjatywa)
{

}
Zwierze::~Zwierze() {

}
void Zwierze::akcja()
{
	int a;
	this->sx = this->x;
	this->sy = this->y;
	string nazwa2 = typeid(*this).name();//nazwa obiektu który wykonuje ruch
	if (nazwa2 != "class czlowiek") {
		do {
			int dp = 1;								//dp to zmienna decyduj¹ca o jak¹ odleg³oœæ przemieœci siê obiekt
			if (nazwa2 == "class antylopa") dp = 2;   //gdy obiekt to antylopa, przemieszczenie bêdzie wynosiæ 2
			a = Organizm::losujPole();
			switch (a) {
			case 0:
				this->nx = this->x - dp;
				this->ny = this->y - dp;
				break;
			case 1:
				this->nx = this->x;
				this->ny = this->y - dp;
				break;
			case 2:
				this->nx = this->x + dp;
				this->ny = this->y - dp; break;
			case 3:
				this->nx = this->x + dp;
				this->ny = this->y;
				break;
			case 4:
				this->nx = this->x + dp;
				this->ny = this->y + dp;
				break;
			case 5:
				this->nx = this->x;
				this->ny = this->y - dp;
				break;
			case 6:
				this->nx = this->x - dp;
				this->ny = this->y;
				break;
			case 7:
				this->nx = this->x - dp;
				this->ny = this->y;
				break;
			}
		} while (this->nx < 1 || this->ny < 1 || this->nx> world.getX() || this->ny> world.getY());
	}
	this->x = nx;
	this->y = ny;
	for (auto n : world.organizmy) {
		if (n != this) {
			if(n->getX()==this->nx){
				if (n->getY() == this->ny) {
					string nazwa = typeid(*n).name(); //nazwa obiektu na który ma zostaæ wykonany ruch
					if (nazwa == "class trawa") {
						int ni = 0, nn=0;
						for (auto z : world.organizmy) {
							if (z == n) nn = ni;
							ni++;
						}
						world.komentator(this, n, "zjada");
						world.organizmy.erase(world.organizmy.begin() + nn);
					}
					else if (nazwa == "class mlecz") {
						int ni = 0, nn = 0;
						for (auto z : world.organizmy) {
							if (z == n) nn = ni;
							ni++;
						}
						world.komentator(this, n, "zjada");
						world.organizmy.erase(world.organizmy.begin() + nn);
					}
					else if (nazwa == "class guarana") {
						this->setSila(this->getSila() + 3);
						int ni = 0, nn = 0;
						for (auto z : world.organizmy) {
							if (z == n) nn = ni;
							ni++;
						}
						world.komentator(this, n, "zjada");
						world.organizmy.erase(world.organizmy.begin() + nn);
					}
					else if (nazwa == "class wilczeJagody") {
						int ni = 0, nn = 0;
						if (this->getSila() < n->getSila()) {
							for (auto z : world.organizmy) {
								if (z == this) nn = ni;
								ni++;
							}
							world.komentator(n, this,"zabija");
						}
						else {
							for (auto z : world.organizmy) {
								if (z == n) nn = ni;
								ni++;
							}
							world.komentator(this, n, "zjada");
						}
						world.organizmy.erase(world.organizmy.begin() + nn);
					}
					else if (nazwa == "class barszczSosnowskiego") {
						int ni = 0, nn = 0;
						if (this->getSila() < n->getSila()) {
							for (auto z : world.organizmy) {
								if (z == this) nn = ni;
								ni++;
							}
							world.komentator(n, this, "zabija");
						}
						else {
							for (auto z : world.organizmy) {
								if (z == n) nn = ni;
								ni++;
							}
							world.komentator(this, n, "zjada");
						}
						world.organizmy.erase(world.organizmy.begin() + nn);
					}
					else if (nazwa == nazwa2) {
						this->x = sx;
						this->y = sy;
						this->dziecko();
						world.komentator(this, this, "rozmnaza sie");
						break;
					}
					else if (nazwa == "class zolw") {
						if (this->getSila() < 5) { // je¿eli organizm chce siê przemieœciæ na pole zajmowane przez ¿ó³wia 
							this->x = sx;		   // i jego si³a jest mniejsza ni¿ 5 to wraca on na swoje poprzednie miejsce
							this->y = sy;
							world.komentator(n, this, "odgania");
						}
						else if (nazwa2 == "class lis") {
							if (n->getSila() > this->getSila()) {
								this->x = sx;
								this->y = sy;
							}
							else this->kolizja(n);
						}
						else this->kolizja(n);
					}
					else {
						if (nazwa2 == "class lis") {
							if (n->getSila() > this->getSila()) {
								this->x = sx;		   
								this->y = sy;
							}
							else this->kolizja(n);
						}
						else this->kolizja(n);
					}
				}
			}
		}
	}
}
void Zwierze::kolizja(Organizm* n){
	string name = typeid(*n).name();
	if (rand() % 2 != 0 || name != "class anylopa") {
		if (n->getSila() > this->getSila()) {
			int ni = 0, nn = 0;
			for (auto z : world.organizmy) {
				if (z == this) nn = ni;
				ni++;
			}
			world.komentator(n, this, "zabija");
			world.organizmy.erase(world.organizmy.begin() + nn);
		}
		else {
			int ni = 0, nn = 0;
			for (auto z : world.organizmy) {
				if (z == n) nn = ni;
				ni++;
			}
			world.komentator(this, n, "zabija");
			world.organizmy.erase(world.organizmy.begin() + nn);
		}
	}
	else {
		n->setX(this->sx);
		n->setY(this->sy);
	}
}
bool Zwierze::rozmnazanie() {
	bool wolne = false;
	if (world.plansza[this->getX() - 2][this->getY() - 2] != "Z" && this->getX() - 1>0&& this->getY() - 1>0) {
		this->nx = this->getX() - 1;
		this->ny = this->getY() - 1;
		wolne = true;
	}
	else if (world.plansza[this->getX() - 1][this->getY() - 2] != "Z"&& this->getY() - 1 > 0) {
		this->nx = this->getX();
		this->ny = this->getY() - 1;
		wolne = true;
	}
	else if (world.plansza[this->getX()][this->getY() - 2] != "Z"&& this->getX() +1< world.getX()+1 && this->getY() - 1 > 0) {
		this->nx = this->getX() +1;
		this->ny = this->getY() - 1;
		wolne = true;
	}
	else if (world.plansza[this->getX()][this->getY() - 1] != "Z" && this->getX()+1 < world.getX()+1) {
		this->nx = this->getX() +1;
		this->ny = this->getY();
		wolne = true;
	}
	else if (world.plansza[this->getX()][this->getY()] != "Z" && this->getX()+1<world.getX()+1&& this->getY()+1 < world.getY() + 1) {
		this->nx = this->getX() +1;
		this->ny = this->getY() + 1;
		wolne = true;
	}
	else if (world.plansza[this->getX() - 1][this->getY()] != "Z" && this->getY()+1 < world.getY() + 1) {
		this->nx = this->getX();
		this->ny = this->getY() + 1;
		wolne = true;
	}
	else if (world.plansza[this->getX() - 2][this->getY()] != "Z" && this->getX()-1 >0 && this->getY()+1 < world.getY() + 1) {
		this->nx = this->getX() -1;
		this->ny = this->getY() + 1;
		wolne = true;
	}
	else if (world.plansza[this->getX() - 2][this->getY() - 1] != "Z" && this->getX()-1 >0) {
		this->nx = this->getX() -1;
		this->ny = this->getY();
		wolne = true;
	}
	if (wolne) {
		int nn = 0;
		for (auto n : world.organizmy) {
			if (n->getX() == this->nx && n->getY() == this->ny) {
				world.organizmy.erase(world.organizmy.begin() + nn);
				break;
			}
			nn++;
		}
	}
	return wolne;
}