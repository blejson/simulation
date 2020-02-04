#include "Organizm.h"
#include <iostream>
#include <time.h>
#include<Windows.h>
using namespace std;
void gotoab(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int Organizm::getWiek() {
	return this->wiek;
}
void Organizm::setWiek(int nw) {
	this->wiek = nw;
}
Organizm::Organizm(Swiat& world, const int &x, const int &y, const int &sila, const int &inicjatywa):
world(world)
{
	this->x = x;
	this->y = y;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
}
void Organizm::rysowanie() {
	gotoab(this->x + 3, this->y + 3);
}
int Organizm::getX() {
	return this->x;
}
int Organizm::getY() {
	return this->y;
}
int Organizm::getSila() {
	return this->sila;
}
int Organizm::getInicjatywa() {
	return this->inicjatywa;
}
void Organizm::setSila(int ns) {
	this->sila = ns;
}
void Organizm::setX(int nx) {
	this->x = nx;
}
void Organizm::setY(int ny) {
	this->y = ny;
}
Organizm::~Organizm(){}
int Organizm::losujPole() {
	int g= rand() % 8;
	return g;
}