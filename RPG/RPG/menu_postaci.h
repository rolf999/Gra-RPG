#pragma once
#ifndef MENU_POSTACI_H
#define MENU_POSTACI_H
#include "button_border.h"
#include "postac.h"
#include "przedmioty.h"
#include <string>
#include <vector>
using namespace std;
class menu_postaci
{
public:
	vector<button_border*> przycisk;
	button_border* poprzednio_zaznaczony;

	int ktora_postac;
	int numer_z_ekwipunku;


	menu_postaci()
	{
		//domyslne wartosci klas
		ktora_postac = 0;
		numer_z_ekwipunku = 0;
		//0-4	przyciski wyboru postaci
		przycisk.push_back(new button_border("Dru¿yna", typ_przycisku::napis, 0, 20, 20, 30, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::osoba, 0, 20, 80, 40));
		przycisk.push_back(new button_border("?", typ_przycisku::osoba, 1, 20, 140, 40));
		przycisk.push_back(new button_border("?", typ_przycisku::osoba, 2, 20, 200, 40));
		przycisk.push_back(new button_border("?", typ_przycisku::osoba, 3, 20, 260, 40));
		//5-7	nawigacja
		przycisk.push_back(new button_border("Walka", typ_przycisku::nawigacja, 0, 20, 460, 40, 5));
		przycisk.push_back(new button_border("Wroæ", typ_przycisku::nawigacja, 1, 20, 520, 40, 5));
		przycisk.push_back(new button_border("Sklep", typ_przycisku::nawigacja, 2, 20, 400, 40, 5));
		//8-21   statystyka
		//polozenie statystyki
		int x = 600;
		int y = 140;
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 10, x, y, 350, 250));	//ramka
		przycisk.push_back(new button_border("Black", typ_przycisku::ramka, 2, x + 20,  y + 75,  295, 0.1));		//linie poziome
		przycisk.push_back(new button_border("Black", typ_przycisku::ramka, 2, x + 20,  y + 115, 295, 0.1));		//linie poziome
		przycisk.push_back(new button_border("Black", typ_przycisku::ramka, 2, x + 20,  y + 155, 295, 0.1));		//linie poziome
		przycisk.push_back(new button_border("Black", typ_przycisku::ramka, 2, x + 20,  y + 195, 295, 0.1));		//linie poziome
		przycisk.push_back(new button_border("Black", typ_przycisku::ramka, 2, x + 150, y + 50,  0.1, 180));		//linie pionowe
		przycisk.push_back(new button_border("Black", typ_przycisku::ramka, 2, x + 240, y + 50,  0.1, 180));		//linie pionowe
		przycisk.push_back(new button_border("Statystyka :",   typ_przycisku::napis, 0, x + 110, y,      30,  0));
		przycisk.push_back(new button_border("atak :",         typ_przycisku::napis, 0, x + 160, y + 40, 20,  0));
		przycisk.push_back(new button_border("obrona :",       typ_przycisku::napis, 0, x + 260, y + 40, 20,  0));
		przycisk.push_back(new button_border("obr. fizyczne ", typ_przycisku::napis, 0, x + 10,  y + 80,  20, 0));
		przycisk.push_back(new button_border("ogieñ    ",      typ_przycisku::napis, 0, x + 10,  y + 120, 20, 0));
		przycisk.push_back(new button_border("powietrze",      typ_przycisku::napis, 0, x + 10,  y + 160, 20, 0));
		przycisk.push_back(new button_border("ziemia   ",      typ_przycisku::napis, 0, x + 10,  y + 200, 20, 0));
		//22-29 wartosci w satystyce 
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x + 180, y + 85, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x + 180, y + 125, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x + 180, y + 165, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x + 180, y + 205, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x + 270, y + 85, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x + 270, y + 125, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x + 270, y + 165, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x + 270, y + 205, 20, 0));
		//30 - 34 ogolne o postaci
		int x_ogolne = 600;
		int y_ogolne = 20;
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 10, x_ogolne, y_ogolne, 350, 90));	//ramka
		przycisk.push_back(new button_border("HP :", typ_przycisku::napis, 0, x_ogolne + 70, y_ogolne, 20, 0));
		przycisk.push_back(new button_border("Mana :", typ_przycisku::napis, 0, x_ogolne + 140, y_ogolne, 20, 0));
		przycisk.push_back(new button_border("wytrzyma³osc :", typ_przycisku::napis, 0, x_ogolne + 215, y_ogolne, 20, 0));
		przycisk.push_back(new button_border("odnowienie :", typ_przycisku::napis, 0, x_ogolne + 20, y_ogolne+60, 20, 0));
		//35 - 39
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x_ogolne + 20, y_ogolne + 30, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x_ogolne + 140, y_ogolne + 30, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x_ogolne + 220, y_ogolne + 30, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x_ogolne + 140, y_ogolne + 60, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x_ogolne + 220, y_ogolne + 60, 20, 0));
		
		//40 46- aktualnie uzywane
		int x_aktual = 600;
		int y_aktual = 420;
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 10, x_aktual, y_aktual, 350, 140));	//ramka
		przycisk.push_back(new button_border("broñ  :", typ_przycisku::napis, 0, x_aktual + 10, y_aktual + 15, 20, 0));
		przycisk.push_back(new button_border("g³owa :", typ_przycisku::napis, 0, x_aktual + 10, y_aktual + 55, 20, 0));
		przycisk.push_back(new button_border("nogi  :", typ_przycisku::napis, 0, x_aktual + 10, y_aktual + 95, 20, 0));
		przycisk.push_back(new button_border("stopy :", typ_przycisku::napis, 0, x_aktual + 175, y_aktual + 15, 20, 0));
		przycisk.push_back(new button_border("rêce  :", typ_przycisku::napis, 0, x_aktual + 175, y_aktual + 55, 20, 0));
		przycisk.push_back(new button_border("t³ów  :", typ_przycisku::napis, 0, x_aktual + 175, y_aktual + 95, 20, 0));
		//47 - 52
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x_aktual + 75, y_aktual + 15, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x_aktual + 75, y_aktual + 55, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x_aktual + 75, y_aktual + 95, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x_aktual + 240, y_aktual + 15, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x_aktual + 240, y_aktual + 55, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x_aktual + 240, y_aktual + 95, 20, 0));

		
		// 53 - 56 ekwipunek
		int x_ekwipunek = 240;
		int y_ekwipunek = 20;
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 10, x_ekwipunek, y_ekwipunek, 330, 360));	//ramka
		przycisk.push_back(new button_border("Ekwipunek :", typ_przycisku::napis, 0, x_ekwipunek + 10, y_ekwipunek, 30, 0));
		przycisk.push_back(new button_border("Za³ó¿", typ_przycisku::zarzadzanie_ekwipunkiem, 0, x_ekwipunek+240, y_ekwipunek+10, 30, 2.6));
		przycisk.push_back(new button_border("Usuñ", typ_przycisku::zarzadzanie_ekwipunkiem, 1, x_ekwipunek+240, y_ekwipunek+60, 30, 2.6));
		//57- 65
		przycisk.push_back(new button_border("", typ_przycisku::lista, 3, x_ekwipunek + 10, y_ekwipunek + 60, 30, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 3, x_ekwipunek + 10, y_ekwipunek + 100, 30, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 3, x_ekwipunek + 10, y_ekwipunek + 140, 30, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 3, x_ekwipunek + 10, y_ekwipunek + 180, 30, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 3, x_ekwipunek + 10, y_ekwipunek + 220, 30, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 3, x_ekwipunek + 10, y_ekwipunek + 260, 30, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 3, x_ekwipunek + 10, y_ekwipunek + 300, 30, 0));
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 8, x_ekwipunek + 50, y_ekwipunek + 50, 140, 0.01));		//suwak
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 8, x_ekwipunek + 50, y_ekwipunek + 345, 140, 0.01));		//suwak

		// 66- 71 porownanie 
		int x_porownanie = 240;
		int y_porownanie = 410;
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 10, x_porownanie, y_porownanie, 330, 150));	//ramka
		przycisk.push_back(new button_border("Black", typ_przycisku::ramka, 2, x_porownanie + 20, y_porownanie + 75, 295, 0.1));		//linia pozioma
		przycisk.push_back(new button_border("Wybrane", typ_przycisku::napis, 0, x_porownanie + 20, y_porownanie + 10, 20, 0));
		przycisk.push_back(new button_border("U¿ywane", typ_przycisku::napis, 0, x_porownanie + 20, y_porownanie + 85, 20, 0));
		przycisk.push_back(new button_border("", typ_przycisku::napis, 0, x_porownanie, y_porownanie + 40, 20, 0));
		przycisk.push_back(new button_border("", typ_przycisku::napis, 0, x_porownanie, y_porownanie + 115, 20, 0));

		


		poprzednio_zaznaczony = NULL;


	}

	void zaladuj_postac(postac * aktoalnie_wybrany, int pierwszy_element_listy, vector<postac*> & druzyna)
	{
		if(ktora_postac == 0)//aby po wejsciu do menu kontynuuj od razu byla zaznaczona pierwsza postac
			przycisk[1]->text.setColor(sf::Color::Blue);//zaznaczenie pierwszej postaci z listy
		//imiona postaci
		przycisk[1]->text.setString(druzyna[0]->imie);
		przycisk[2]->text.setString(druzyna[1]->imie);
		przycisk[3]->text.setString(druzyna[2]->imie);
		przycisk[4]->text.setString(druzyna[3]->imie);

		//ataki
		przycisk[22]->text.setString(to_string(int(aktoalnie_wybrany->zadane.fizyczne)));
		przycisk[23]->text.setString(to_string(int(aktoalnie_wybrany->zadane.ogien)));
		przycisk[24]->text.setString(to_string(int(aktoalnie_wybrany->zadane.powietrze)));
		przycisk[25]->text.setString(to_string(int(aktoalnie_wybrany->zadane.ziemia)));
		//obrona
		przycisk[26]->text.setString(to_string(int(aktoalnie_wybrany->statystyka.fizyczne)) + "%");
		przycisk[27]->text.setString(to_string(int(aktoalnie_wybrany->statystyka.ogien)) + "%");
		przycisk[28]->text.setString(to_string(int(aktoalnie_wybrany->statystyka.powietrze)) + "%");
		przycisk[29]->text.setString(to_string(int(aktoalnie_wybrany->statystyka.ziemia)) + "%");
		//o HP,mana ...
		przycisk[35]->text.setString(to_string(int(aktoalnie_wybrany->maxzdrowie)));
		przycisk[36]->text.setString(to_string(int(aktoalnie_wybrany->maxmana)));
		przycisk[37]->text.setString(to_string(int(aktoalnie_wybrany->maxwytrzymalosc)));
		przycisk[38]->text.setString(to_string(int(aktoalnie_wybrany->odnawianie_many)));
		przycisk[39]->text.setString(to_string(int(aktoalnie_wybrany->odnawianie_wytrzymalosci)));

		//aktualnie uzywane
		przycisk[47]->text.setString(aktoalnie_wybrany->aktualnie_uzywane["bron"].nazwa);
		przycisk[48]->text.setString(aktoalnie_wybrany->aktualnie_uzywane["glowa"].nazwa);
		przycisk[49]->text.setString(aktoalnie_wybrany->aktualnie_uzywane["nogi"].nazwa);
		przycisk[50]->text.setString(aktoalnie_wybrany->aktualnie_uzywane["stopy"].nazwa);
		przycisk[51]->text.setString(aktoalnie_wybrany->aktualnie_uzywane["rece"].nazwa);
		przycisk[52]->text.setString(aktoalnie_wybrany->aktualnie_uzywane["tlow"].nazwa);

		//wypisanie ekwipunku
		zaladuj_ekwipunek(aktoalnie_wybrany->ekwipunek, przycisk, 57, 65, pierwszy_element_listy);

		if (aktoalnie_wybrany->ekwipunek.size() != 0)	//w przypadku braku ekwipunku
		{

			przycisk[70]->text.setString(aktoalnie_wybrany->ekwipunek[numer_z_ekwipunku].wypisz());
			string nno = aktoalnie_wybrany->aktualnie_uzywane[aktoalnie_wybrany->ekwipunek[numer_z_ekwipunku].typ].wypisz();
			przycisk[71]->text.setString(nno);
		}
	}



	void draw(sf::RenderWindow & okno)
	{
		for (vector<button_border*>::iterator aktualny = przycisk.begin(); aktualny != przycisk.end(); aktualny++)
		{
			okno.draw((*aktualny)->ramka);
			okno.draw((*aktualny)->text);

		}
	}
};

#endif