#include "Swiat.h"
#include "Organizm.h"
#include "Roslina.h"
#include "Zwierze.h"
#include "trawa.h"
#include "wilk.h"
#include "mlecz.h"
#include "wilczeJagody.h"
#include "barszczSosnowskiego.h"
#include "guarana.h"
#include "owca.h"
#include "lis.h"
#include "zolw.h"
#include "antylopa.h"
#include "czlowiek.h"
#include <iostream>
#include<Windows.h>
#include <time.h>
#include <conio.h>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Swiat::tworzPlansze() {
	for (int i = 0; i < this->getX(); i++) {
		for (int j = 0; j < this->getY(); j++) {
			this->plansza[i][j] = " ";
		}
	}
	for (auto n : this->organizmy) {
		string name = typeid(*n).name();
		if (name == "class antylopa" || name == "class lis" || name == "class owca" || name == "class wilk" || name == "class zolw" || name=="class czlowiek") {
			plansza[n->getX() - 1][n->getY() - 1] = "Z";
		}
	}
}
Swiat::Swiat(int x, int y) {
	this->x = x;
	this->y = y;
	this->l_tur = 1;

	this->plansza = new string *[x];
	for (int i = 0; i < x; i++) {
		this->plansza[i] = new string [y];
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			this->plansza[i][j] = " ";
		}
	}
}
bool sortowanie(Organizm* org1, Organizm* org2) {
	if (org1->getInicjatywa() != org2->getInicjatywa()) {
		return org1->getInicjatywa() > org2->getInicjatywa();
	}
	else return org1->getWiek() > org2->getWiek();
}
void zapis(vector<Organizm*> organizmy, Swiat* world) {
	fstream plik;
	plik.open("zapis.txt", ios::out);
	plik << organizmy.size() << endl;
	plik << world->getL_tur() << endl;
	for (auto n : organizmy) {
		int z=0;
		string name = typeid(*n).name();
		if (name == " class antylopa") z = 0;
		else if (name == "class czlowiek") z = 2;
		else if (name == "class guarana") z = 3;
		else if (name == "class lis") z = 4;
		else if (name == "class mlecz") z = 5;
		else if (name == "class owca") z = 6;
		else if (name == "class trawa") z = 7;
		else if (name == "class wilczeJagody") z = 8;
		else if (name == "class wilk") z = 9;
		else if (name == "class zolw") z = 10;
		plik << z << endl;
		plik << n->getX() << endl;
		plik<< n->getY() << endl;

	}
	plik.close();
}
void odczyt(Swiat* world) {
	fstream plik;
	plik.open("zapis.txt", ios::in);
	string linia;
	getline(plik, linia);
	int il = atoi(linia.c_str());
	getline(plik, linia);
	world->setL_tur(atoi(linia.c_str()));
	for (int i = 0; i < il; i++) {
		int n, px, py;
		getline(plik, linia);
		n = atoi(linia.c_str());
		getline(plik, linia);
		px = atoi(linia.c_str());
		getline(plik, linia);
		py = atoi(linia.c_str());
		switch (n) {
		case 0: world->organizmy.push_back(new antylopa(*world, px, py)); break;
		case 1: world->organizmy.push_back(new barszczSosnowskiego(*world, px, py)); break;
		case 2: world->organizmy.push_back(new czlowiek(*world, px, py)); break;
		case 3: world->organizmy.push_back(new guarana(*world, px, py)); break;
		case 4: world->organizmy.push_back(new lis(*world, px, py)); break;
		case 5: world->organizmy.push_back(new mlecz(*world, px, py)); break;
		case 6: world->organizmy.push_back(new owca(*world, px, py)); break;
		case 7: world->organizmy.push_back(new trawa(*world, px, py)); break;
		case 8: world->organizmy.push_back(new wilczeJagody(*world, px, py)); break;
		case 9: world->organizmy.push_back(new wilk(*world, px, py)); break;
		case 10: world->organizmy.push_back(new zolw(*world, px, py)); break;
		}
	}
	plik.close();
}
void Swiat::wykonajTure() {
	char inp;
	do {
		sort(this->organizmy.begin(), this->organizmy.end(), sortowanie);
		system("cls");
		cout << "Runda nr: " << this->getL_tur();
		gotoxy(0, 1);
		cout << "kliknij dowolny przycisk aby rozpoczac runde" << endl;
		cout << "kliknij q aby wyjsc, z aby zapisac gre, lub o aby otworzyc zapisana";
		int i = 0;
		while (!this->komentarze.empty()) {
			gotoxy(this->n + this->x + 5, 5+i);
			string kom = this->komentarze.front();
			cout << kom;
			this->komentarze.erase(this->komentarze.begin());
			i++;
		}
		this->komentarze.clear();
		Swiat::rysujSwiat();
		inp = _getch();
		if (inp == -32) {
			inp = _getch();
		}
		this->setL_tur(this->getL_tur()+1);
		if (inp == 122) zapis(this->organizmy, this); // je¿eli u¿ytkownik klikn¹³ "z" program zapisze aktualny stan do pliku
		if (inp == 111) { // "o" odczytuje z pliku
			organizmy.clear();
			odczyt(this);
	}
		if (inp != 111 && inp != 122 && inp != 113) {
			vector<Organizm*> korganizmy = organizmy;
			for (auto n : korganizmy) {
				this->tworzPlansze();
				n->akcja();
				n->setWiek(n->getWiek() + 1);
			}
		}
	} while (inp != 113); //while inp!= "q"
}
int Swiat::getL_tur() {
	return this->l_tur;
}
void Swiat::setL_tur(int nl) {
	this->l_tur = nl;
}
void Swiat::rysujSwiat() {
	gotoxy(n, z);
	for (int i = 0; i <= (this->x + 1); i++) {
		cout << "#";
	}
	gotoxy(n, z + y+1);
	for (int i = 0; i <= (this->x + 1); i++) {
		cout << "#";
	}
	for (int i = 0; i <= y; i++) {
		gotoxy(n, z + i);
		cout << "#";
	}
	for (int i = 0; i <= y; i++) {
		gotoxy(n+x+1, z + i);
		cout << "#";
	}
	for (auto n : organizmy) {
		n->rysowanie();
	}
}
int Swiat::getX() {
	return this->x;
}
int Swiat::getY() {
	return this->y;
}
void Swiat::komentator(Organizm* a, Organizm* b, string akt) {
	string kom;
	string name1,name2, name11, name22;
	name1= typeid(*a).name();
		name2= typeid(*b).name();
	for (int i = 6; i < name1.length(); i++) {
		name11 += name1[i];
	}
	for (int i = 6; i < name2.length(); i++) {
		name22 += name2[i];
	}
	if (akt == "zabija") {
		kom += name11;
		kom += " ";
		kom += akt;
		kom += " ";
		kom += name22;
	}
	else if (akt == "zjada") {
		kom += name11;
		kom += " ";
		kom += akt;
		kom += " ";
		kom += name22;
	}
	else if (akt == "rozmnaza sie") {
		kom += name11;
		kom += " ";
		kom += akt;
	}
	this->komentarze.push_back(kom);
}
Swiat::~Swiat() {
	for (int i = 0; i < this->getX(); i++) {
		delete[] this->plansza[i];
	}
	delete [] this->plansza;
	this->komentarze.clear();
	this->organizmy.clear();
}