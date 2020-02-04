#include <iostream>
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
#include <conio.h>
#include <Windows.h>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL)); 
	int w, s;
	bool zlyrozmiar = false;
	do {
		zlyrozmiar = false;
		system("cls");
		cout << "Podaj wysokosc planszy, nie mniejsza niz 20: "; cin >> w;
		cout << "Podaj szerokosc planszy, nie mniejsza niz 40: "; cin >> s;
		if (s < 40 || w < 20) {
			cout << "Zbyt male wymiary planszy";
			Sleep(1000);
			zlyrozmiar = true;
}
	} while (zlyrozmiar);
		Swiat swiat(s, w);
		swiat.organizmy.push_back(new trawa(swiat, 3, 4));
		swiat.organizmy.push_back(new mlecz(swiat, 7, 19));
		swiat.organizmy.push_back(new guarana(swiat, 7, 2));
		swiat.organizmy.push_back(new wilczeJagody(swiat, 35, 5));
		swiat.organizmy.push_back(new barszczSosnowskiego(swiat, 35, 15));
		swiat.organizmy.push_back(new wilk(swiat, 2, 1));
		swiat.organizmy.push_back(new owca(swiat, 7, 7));
		swiat.organizmy.push_back(new lis(swiat, 1, 7));
		swiat.organizmy.push_back(new zolw(swiat, 1, 1));
		swiat.organizmy.push_back(new antylopa(swiat, 2, 2));
		swiat.organizmy.push_back(new wilk(swiat, 15, 11));
		swiat.organizmy.push_back(new owca(swiat, 18, 7));
		swiat.organizmy.push_back(new lis(swiat, 21, 7));
		swiat.organizmy.push_back(new zolw(swiat, 16, 1));
		swiat.organizmy.push_back(new antylopa(swiat, 32, 2));
		swiat.organizmy.push_back(new czlowiek(swiat, 32, 12));
		swiat.organizmy.push_back(new guarana(swiat, 32, 13));
		swiat.tworzPlansze();
		swiat.wykonajTure();
	return 0;
}