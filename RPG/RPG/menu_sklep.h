#pragma once
#ifndef MENU_SKLEP_H
#define MENU_SKLEP_H
#include "button_border.h"
#include "postac.h"
#include "przedmioty.h"
#include <string>
#include <vector>

using namespace std;

class sklep
{
public:
	vector<button_border*> przycisk;
	button_border* poprzednio_zaznaczony;

	int ktora_postac;
	//dla pola info
	int wcisniety;
	typ_przycisku typ_wcisnietego;
	//odblokowanie przycisku kup
	bool czy_mozna_kupic;
	int koszt;

	sklep(int postac_kupujaca = 0)
	{
		int wcisniety = 0;	
		typ_wcisnietego = typ_przycisku::umiejet;
		ktora_postac = postac_kupujaca;
		czy_mozna_kupic = false;
		koszt = 0;
		//0-1 //ubior
		int x_ekwipunek = 20;
		int y_ekwipunek = 20;
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 10, x_ekwipunek, y_ekwipunek, 250, 490));	//ramka
		przycisk.push_back(new button_border("Ubiór :", typ_przycisku::napis, 0, x_ekwipunek + 10, y_ekwipunek, 30, 0));
		//2-16
		przycisk.push_back(new button_border("", typ_przycisku::lista, 0, x_ekwipunek + 10, y_ekwipunek + 60 , 20, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 0, x_ekwipunek + 10, y_ekwipunek + 90 , 20, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 0, x_ekwipunek + 10, y_ekwipunek + 120, 20, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 0, x_ekwipunek + 10, y_ekwipunek + 150, 20, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 0, x_ekwipunek + 10, y_ekwipunek + 180, 20, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 0, x_ekwipunek + 10, y_ekwipunek + 210, 20, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 0, x_ekwipunek + 10, y_ekwipunek + 240, 20, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 0, x_ekwipunek + 10, y_ekwipunek + 270, 20, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 0, x_ekwipunek + 10, y_ekwipunek + 300, 20, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 0, x_ekwipunek + 10, y_ekwipunek + 330, 20, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 0, x_ekwipunek + 10, y_ekwipunek + 360, 20, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 0, x_ekwipunek + 10, y_ekwipunek + 390, 20, 0));
		przycisk.push_back(new button_border("", typ_przycisku::lista, 0, x_ekwipunek + 10, y_ekwipunek + 420, 20, 0));
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 8, x_ekwipunek + 50, y_ekwipunek + 50 , 140, 0.01));		//suwak
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 8, x_ekwipunek + 50, y_ekwipunek + 470, 140, 0.01));		//suwak
		//17 - 25 eliksiry
		int x_miks = 300;
		int y_miks = 20;
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 10, x_miks, y_miks, 250, 560));	//ramka
		przycisk.push_back(new button_border("Eliksiry :",                  typ_przycisku::napis, 0 , x_miks + 10, y_miks     ,  30, 0));
		przycisk.push_back(new button_border("sta³e efekty :",              typ_przycisku::napis, 0 , x_miks + 10, y_miks + 30,  20, 0));
		przycisk.push_back(new button_border("Ma³y sredni du¿y",            typ_przycisku::napis, 0 , x_miks + 70, y_miks + 60,  20, 0));
		przycisk.push_back(new button_border("HP\nWytrz.\nMana",            typ_przycisku::napis, 0 , x_miks + 10, y_miks + 90,  20, 0));
		przycisk.push_back(new button_border("Zwiêkszenie max. wartosci :", typ_przycisku::napis, 0 , x_miks + 10, y_miks + 170, 20, 0));
		przycisk.push_back(new button_border("HP    Mana  Wytrz.",          typ_przycisku::napis, 0 , x_miks + 10, y_miks + 200, 20, 0));
		przycisk.push_back(new button_border("Odnaw.",                      typ_przycisku::napis, 0 , x_miks + 10, y_miks + 260, 20, 0));
		przycisk.push_back(new button_border("Odpornosci :",                typ_przycisku::napis, 0 , x_miks + 10, y_miks + 290, 20, 0));
		//26-34 eliksiry maly, duzy , sredni
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 0, x_miks + 80,  y_miks + 85,  20, 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 1, x_miks + 130, y_miks + 85,  20, 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 2, x_miks + 180, y_miks + 85, 20 , 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 3, x_miks + 80,  y_miks + 115, 20, 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 4, x_miks + 130, y_miks + 115, 20, 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 5, x_miks + 180, y_miks + 115, 20, 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 6, x_miks + 80,  y_miks + 145, 20, 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 7, x_miks + 130, y_miks + 145, 20, 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 8, x_miks + 180, y_miks + 145, 20, 1));
		
		//35 - 39
		przycisk.push_back(new button_border("obr.fizyczne", typ_przycisku::mikstura, 9, x_miks + 10, y_miks + 330, 20, 6));
		przycisk.push_back(new button_border("zwiêksz atak", typ_przycisku::mikstura, 10, x_miks + 10, y_miks + 370, 20, 6));
		przycisk.push_back(new button_border("ogieñ       ", typ_przycisku::mikstura, 11, x_miks + 10, y_miks + 410, 20, 6));
		przycisk.push_back(new button_border("powietrze:  ", typ_przycisku::mikstura, 12, x_miks + 10, y_miks + 450, 20, 6));
		przycisk.push_back(new button_border("ziemia      ", typ_przycisku::mikstura, 13, x_miks + 10, y_miks + 490, 20, 6));
		// 40- 44 zwiekszenie na stale zdrowia many wytrz i odnawiania
		przycisk.push_back(new button_border("x", typ_przycisku::mikstura, 14, x_miks + 20 , y_miks + 230, 20, 1));	//hp
		przycisk.push_back(new button_border("x", typ_przycisku::mikstura, 15, x_miks + 80 , y_miks + 230, 20, 1));	//mana
		przycisk.push_back(new button_border("x", typ_przycisku::mikstura, 16, x_miks + 140, y_miks + 230, 20, 1));	//wytrzymalosc
		przycisk.push_back(new button_border("x", typ_przycisku::mikstura, 17, x_miks + 80 , y_miks + 260, 20, 1));	//zwieksz odnawianie many
		przycisk.push_back(new button_border("x", typ_przycisku::mikstura, 18, x_miks + 140, y_miks + 260, 20, 1));	//zwieksz odnawianie wytrzymalosc

		//45 -53 umiejetnosci
		int x_umie = 580;
		int y_umie = 20;
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 10, x_umie, y_umie, 400, 350));	//ramka
		przycisk.push_back(new button_border("Umiejêtnosci :", typ_przycisku::napis, 0, x_umie + 10, y_umie, 30, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::umiejet, 0, x_umie + 10, y_umie + 40 , 20, 0));	//miejsca na umiejetonsci
		przycisk.push_back(new button_border("?", typ_przycisku::umiejet, 1, x_umie + 10, y_umie + 80 , 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::umiejet, 2, x_umie + 10, y_umie + 120, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::umiejet, 3, x_umie + 10, y_umie + 160, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::umiejet, 4, x_umie + 10, y_umie + 200, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::umiejet, 5, x_umie + 10, y_umie + 240, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::umiejet, 6, x_umie + 10, y_umie + 280, 20, 0));

		//54 - 59 informacje
		int x_info = 580;
		int y_info = 400;
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 10, x_info, y_info, 400, 180));	//ramka
		przycisk.push_back(new button_border("Doswiadczenie :", typ_przycisku::napis, 0, x_info+10, y_info, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::napis, 0, x_info + 200, y_info, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::slot, 0, x_info + 10, y_info+80, 20, 0));

		przycisk.push_back(new button_border("Wróæ", typ_przycisku::nawigacja, 0, 10, 530, 40, 3.2));
		przycisk.push_back(new button_border("Kup", typ_przycisku::nawigacja, 1, 150, 530, 40, 3.2));
		

		
	}
	

	void zaladuj_postac(postac * aktoalnie_wybrany, int pierwszy_element_listy, vector<postac*> & druzyna, vector<ubior> & baza_przedmiotow, vector<eliksir> & baza_eliksirow)
	{
		//zape³nienie listy ubran do kupna
		zaladuj_ekwipunek(baza_przedmiotow, przycisk, 2, 16, pierwszy_element_listy);

		for (int i = 0; i < 7; i++)
		{
			if (aktoalnie_wybrany->ataki[i].poziom > 2)	//w przypadku osi¹gniêcia maksymalnego poziomu zaznacz umiejêtnoœc na czerowno
				przycisk[i + 47]->text.setColor(sf::Color::Red);
			else
				przycisk[i + 47]->text.setColor(sf::Color::Black);

			przycisk[i + 47]->text.setString(aktoalnie_wybrany->ataki[i].wypisz());
		}

		przycisk[56]->text.setString(to_string(int(aktoalnie_wybrany->doswiadczenie)));

		if (koszt > aktoalnie_wybrany->doswiadczenie)	//czy masz na tyle doœwiadczenia
			czy_mozna_kupic = false;
		else
			czy_mozna_kupic = true;

		string pomocniczy = " ";
		switch (typ_wcisnietego)
		{
		case typ_przycisku::lista:
			if(baza_przedmiotow[wcisniety].klasa != "class Wojownik")	//przedmioty dla wojownika tansze
				koszt = baza_przedmiotow[wcisniety].obrona * 20;
			else
				koszt = baza_przedmiotow[wcisniety].obrona * 8;

			pomocniczy = baza_przedmiotow[wcisniety].wypisz() + "\nKoszt : " + to_string(koszt);	

			if (baza_przedmiotow[wcisniety].klasa == "class Wojownik" && typeid(*aktoalnie_wybrany).name() != "class Wojownik") //RTTI sprawdzenie czy mo¿e nosciæ dany przedmiot
			{
				pomocniczy += "\nNiewlasciwa klasa";
				czy_mozna_kupic = false;
			}

			break;
		case typ_przycisku::mikstura:
			if (wcisniety < 14)
			{
				koszt = baza_przedmiotow[wcisniety].obrona * 10;
				pomocniczy = baza_eliksirow[wcisniety].wypisz() + "\nKoszt : " + to_string(koszt);
			}
			else
			{
				koszt = 500;
				pomocniczy = "Koszty : " + to_string(koszt);
			}
			break;
		case typ_przycisku::umiejet:
			if (aktoalnie_wybrany->ataki[wcisniety].poziom < 3)	//w przypadku kupna umiejetnosci na ju max poziomie
			{
				koszt = aktoalnie_wybrany->ataki[wcisniety].koszt_aktywacji;
				pomocniczy = "Koszty : " + to_string(koszt);
			}
			else
				czy_mozna_kupic = false;
			break;
		default:
			break;
		}

		


		przycisk[57]->text.setString(pomocniczy);

		if (czy_mozna_kupic == false)
			przycisk[59]->text.setColor(sf::Color::Transparent);
		else
			przycisk[59]->text.setColor(sf::Color::Black);
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