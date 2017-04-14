#pragma once
#ifndef MENU_WALKI_H
#define MENU_WALKI_H
#include "button_border.h"
#include "postac.h"
#include "przedmioty.h"
#include <string>
#include <vector>

using namespace std;

class walka
{
public:
	vector<button_border*> przycisk;
	button_border* poprzednio_zaznaczony;

	int ktory_elkisir,	//informacje o wybranych rzeczach
		ktory_gracz,
		ktory_wrog,
		ktora_umiejetnosc,
		ktory_poziom;



	walka()
	{
		ktory_elkisir = 0;
		ktory_gracz = 0;
		ktory_wrog = 0;
		ktora_umiejetnosc = 0;
		ktory_poziom = 0;

		//0-5
		int x_miks = 20;
		int y_miks = 20;
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 10, x_miks, y_miks, 250, 560));	//ramka
		przycisk.push_back(new button_border("Eliksiry :", typ_przycisku::napis, 0, x_miks + 10, y_miks, 30, 0));
		przycisk.push_back(new button_border("sta³e efekty :", typ_przycisku::napis, 0, x_miks + 10, y_miks + 30, 20, 0));
		przycisk.push_back(new button_border("Ma³y sredni du¿y", typ_przycisku::napis, 0, x_miks + 70, y_miks + 60, 20, 0));
		przycisk.push_back(new button_border("HP\nWytrz.\nMana", typ_przycisku::napis, 0, x_miks + 10, y_miks + 90, 20, 0));
		przycisk.push_back(new button_border("Odpornosci :", typ_przycisku::napis, 0, x_miks + 10, y_miks + 180, 20, 0));
		//6-14 eliksiry maly, duzy , sredni
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 0, x_miks + 80, y_miks + 85, 20, 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 1, x_miks + 130, y_miks + 85, 20, 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 2, x_miks + 180, y_miks + 85, 20, 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 3, x_miks + 80, y_miks + 115, 20, 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 4, x_miks + 130, y_miks + 115, 20, 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 5, x_miks + 180, y_miks + 115, 20, 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 6, x_miks + 80, y_miks + 145, 20, 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 7, x_miks + 130, y_miks + 145, 20, 1));
		przycisk.push_back(new button_border("x ", typ_przycisku::mikstura, 8, x_miks + 180, y_miks + 145, 20, 1));

		//15 - 22
		przycisk.push_back(new button_border("obr.fizyczne", typ_przycisku::mikstura, 9, x_miks + 10, y_miks + 220, 20, 6));
		przycisk.push_back(new button_border("zwiêksz atak", typ_przycisku::mikstura, 10, x_miks + 10, y_miks + 260, 20, 6));
		przycisk.push_back(new button_border("ogieñ       ", typ_przycisku::mikstura, 11, x_miks + 10, y_miks + 300, 20, 6));
		przycisk.push_back(new button_border("powietrze:  ", typ_przycisku::mikstura, 12, x_miks + 10, y_miks + 340, 20, 6));
		przycisk.push_back(new button_border("ziemia      ", typ_przycisku::mikstura, 13, x_miks + 10, y_miks + 380, 20, 6));
		przycisk.push_back(new button_border("ilosc :     ", typ_przycisku::napis   , 0, x_miks + 10, y_miks + 480, 18, 0));
		przycisk.push_back(new button_border("u¿yj     ",    typ_przycisku::nawigacja, 0, x_miks + 10, y_miks + 520, 20, 5));
		przycisk.push_back(new button_border("wyjdz    ",    typ_przycisku::nawigacja, 1, x_miks + 120, y_miks + 520, 20, 5));

		//23 - 31																											//45 -53 umiejetnosci
		int x_umie = 300;
		int y_umie = 370;
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 10, x_umie, y_umie, 400, 210));	//ramka
		przycisk.push_back(new button_border("Umiejêtnosci :", typ_przycisku::napis, 0, x_umie + 10, y_umie, 30, 0));
		przycisk.push_back(new button_border("?",  typ_przycisku::umiejet, 0, x_umie + 10, y_umie + 40 , 20, 0));	//miejsca na umiejetonsci
		przycisk.push_back(new button_border("?",  typ_przycisku::umiejet, 1, x_umie + 10, y_umie + 80 , 20, 0));
		przycisk.push_back(new button_border("?",  typ_przycisku::umiejet, 2, x_umie + 10, y_umie + 120, 20, 0));
		przycisk.push_back(new button_border("?",  typ_przycisku::umiejet, 3, x_umie + 10, y_umie + 160, 20, 0));
		przycisk.push_back(new button_border("?",  typ_przycisku::umiejet, 4, x_umie + 200, y_umie + 40 , 20, 0));
		przycisk.push_back(new button_border("?",  typ_przycisku::umiejet, 5, x_umie + 200, y_umie + 80 , 20, 0));
		przycisk.push_back(new button_border("?",  typ_przycisku::umiejet, 6, x_umie + 200, y_umie + 120, 20, 0));
		// 32 - 34
		przycisk.push_back(new button_border("", typ_przycisku::atakuj, 1, x_umie + 200, y_umie + 160, 30, 1));
		przycisk.push_back(new button_border("", typ_przycisku::atakuj, 2, x_umie + 250, y_umie + 160, 30, 1));
		przycisk.push_back(new button_border("", typ_przycisku::atakuj, 3, x_umie + 300, y_umie + 160, 30, 1));

		//35 - 40 informacje
		int x_log = 700;
		int y_log = 370;
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 10, x_log, y_log, 280, 210));	//ramka
		przycisk.push_back(new button_border("obrazenia :", typ_przycisku::napis, 0, x_log + 10, y_log, 20, 0));
		przycisk.push_back(new button_border("Black", typ_przycisku::ramka, 9, x_log + 130, y_log + 15 , 0.5, 0.5));
		przycisk.push_back(new button_border("Red",   typ_przycisku::ramka, 9, x_log + 170, y_log + 15, 0.5, 0.5));
		przycisk.push_back(new button_border("Blue",  typ_przycisku::ramka, 9, x_log + 210, y_log + 15, 0.5, 0.5));
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 9, x_log + 250, y_log + 15, 0.5, 0.5));

		//41 - 46
		int x_arena = 300;
		int y_arena = 20;
		przycisk.push_back(new button_border("Green", typ_przycisku::ramka, 10, x_arena, y_arena, 680, 320));	//ramka
		przycisk.push_back(new button_border("Dru¿yna  						pozyjcja:		Wrogowie", typ_przycisku::napis, 0, x_arena + 10, y_arena, 30, 0));
		przycisk.push_back(new button_border("HP      Mana   Wytrz.		Imie", typ_przycisku::napis, 0, x_arena + 10, y_arena + 50, 20, 0));
		przycisk.push_back(new button_border("3 ", typ_przycisku::przycisk_pozyc, 3, x_arena + 328, y_arena + 50, 30, 1));
		przycisk.push_back(new button_border("2 ", typ_przycisku::przycisk_pozyc, 2, x_arena + 410, y_arena + 50, 30, 1));
		przycisk.push_back(new button_border("1 ", typ_przycisku::przycisk_pozyc, 1, x_arena + 492, y_arena + 50, 30, 1));
		//47 - 50
		przycisk.push_back(new button_border("Gracz1:", typ_przycisku::osoba, 0, x_arena + 200, y_arena + 100, 25, 3.5));
		przycisk.push_back(new button_border("Gracz2:", typ_przycisku::osoba, 1, x_arena + 200, y_arena + 150, 25, 3.5));
		przycisk.push_back(new button_border("Gracz3:", typ_przycisku::osoba, 2, x_arena + 200, y_arena + 200, 25, 3.5));
		przycisk.push_back(new button_border("Gracz4:", typ_przycisku::osoba, 3, x_arena + 200, y_arena + 250, 25, 3.5));
		//51 - 62 statystyki 
		przycisk.push_back(new button_border("?", typ_przycisku::staty, 0, x_arena + 10,  y_arena + 100, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::staty, 1, x_arena + 70,  y_arena + 100, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::staty, 2, x_arena + 140, y_arena + 100, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::staty, 3, x_arena + 10,  y_arena + 150, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::staty, 4, x_arena + 70,  y_arena + 150, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::staty, 5, x_arena + 140, y_arena + 150, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::staty, 6, x_arena + 10,  y_arena + 200, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::staty, 7, x_arena + 70,  y_arena + 200, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::staty, 8, x_arena + 140, y_arena + 200, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::staty, 9, x_arena + 10,  y_arena + 250, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::staty, 10, x_arena + 70,  y_arena + 250, 20, 0));
		przycisk.push_back(new button_border("?", typ_przycisku::staty, 11, x_arena + 140, y_arena + 250, 20, 0));
		//63 - 74 pozycje
		przycisk.push_back(new button_border("", typ_przycisku::pozycja, 0,  x_arena + 492, y_arena + 100, 30, 0));
		przycisk.push_back(new button_border("", typ_przycisku::pozycja, 1,  x_arena + 410, y_arena + 100, 30, 0));
		przycisk.push_back(new button_border("x", typ_przycisku::pozycja, 2,  x_arena + 328, y_arena + 100, 30, 0));
		przycisk.push_back(new button_border("", typ_przycisku::pozycja, 3,  x_arena + 492, y_arena + 150, 30, 0));
		przycisk.push_back(new button_border("", typ_przycisku::pozycja, 4,  x_arena + 410, y_arena + 150, 30, 0));
		przycisk.push_back(new button_border("x", typ_przycisku::pozycja, 5,  x_arena + 328, y_arena + 150, 30, 0));
		przycisk.push_back(new button_border("", typ_przycisku::pozycja, 6,  x_arena + 492, y_arena + 200, 30, 0));
		przycisk.push_back(new button_border("", typ_przycisku::pozycja, 7,  x_arena + 410, y_arena + 200, 30, 0));
		przycisk.push_back(new button_border("x", typ_przycisku::pozycja, 8,  x_arena + 328, y_arena + 200, 30, 0));
		przycisk.push_back(new button_border("", typ_przycisku::pozycja, 9,  x_arena + 492, y_arena + 250, 30, 0));
		przycisk.push_back(new button_border("", typ_przycisku::pozycja, 10, x_arena + 410, y_arena + 250, 30, 0));
		przycisk.push_back(new button_border("x", typ_przycisku::pozycja, 11, x_arena + 328, y_arena + 250, 30, 0));
		// 75 -  80 wrogowie
		przycisk.push_back(new button_border("x", typ_przycisku::wrog, 0, x_arena + 580, y_arena + 120, 30, 0));
		przycisk.push_back(new button_border("x", typ_przycisku::wrog, 1, x_arena + 620, y_arena + 120, 30, 0));
		przycisk.push_back(new button_border("x", typ_przycisku::wrog, 2, x_arena + 580, y_arena + 160, 30, 0));
		przycisk.push_back(new button_border("x", typ_przycisku::wrog, 3, x_arena + 620, y_arena + 160, 30, 0));
		przycisk.push_back(new button_border("x", typ_przycisku::wrog, 4, x_arena + 580, y_arena + 200, 30, 0));
		przycisk.push_back(new button_border("x", typ_przycisku::wrog, 5, x_arena + 620, y_arena + 200, 30, 0));
		// 81 wyniki ataku
		przycisk.push_back(new button_border("", typ_przycisku::napis, 0, x_log + 10, y_log + 30, 20, 0));
	}


	void zaladuj_postac(vector<postac*> & druzyna, vector<postac*> & wrogowie, vector<ubior> & baza_przedmiotow, vector<eliksir> & baza_eliksirow)
	{
		if(druzyna.size() != 0)
		for (int i = 0; i < 7; i++)	//wypisanie umiejetnosci
		{
			if (druzyna.size() <= ktory_gracz)	//wypisanie umiejetnosci usunietego gracza
				ktory_gracz = 0;
			if (druzyna[ktory_gracz]->ataki[i].poziom < 1)	//w przypadku nine odblokowania umiejetnosci
				przycisk[i + 25]->text.setColor(sf::Color::Red);
			else
				przycisk[i + 25]->text.setColor(sf::Color::Black);

			przycisk[i + 25]->text.setString(druzyna[ktory_gracz]->ataki[i].nazwa);
		}


		//wpisanie ilosci wybranego eliksiru
		przycisk[20]->text.setString(baza_eliksirow[ktory_elkisir].wypisz());

		int j = 51;
		for (int i = 0; i < druzyna.size(); i++)
		{
			
			przycisk[j]->text.setString(to_string(int(druzyna[i]->HP)));
			przycisk[j + 1]->text.setString(to_string(int(druzyna[i]->mana)));
			przycisk[j + 2]->text.setString(to_string(int(druzyna[i]->wytrzymalosc)));
			j += 3;
		}

		for (int i = 0; i < wrogowie.size(); i++)	//wypelnienie przyciskow wrogow
		{
			przycisk[75 + i]->text.setString("x");
		}

		for (int i = wrogowie.size(); i < 6; i++) //wypelnienie reszty, nieaktywnych
		{
			przycisk[75 + i]->text.setString("");
		}

		for (int i = 0; i < druzyna.size(); i++)	//wypelnienie przyciskow druzyny
		{
			if(druzyna[i]->czy_atakowac)
				przycisk[47 + i]->text.setString(druzyna[i]->imie);
			else
				przycisk[47 + i]->text.setString("");

		}

		
		for (int i = 0; i < druzyna.size(); i++)	//usuniecie postaci ktore maja poziom zdrowia po nizej 0 druzyna
		{
			if (druzyna[i]->HP <= 0)
			{
				druzyna.erase(druzyna.begin() + i);
				i = 0;
			}
		}

		for (int i = 0; i < wrogowie.size(); i++)	//usuniecie postaci ktore maja poziom zdrowia po nizej 0 wrogowie
		{
			if (wrogowie[i]->HP <= 0)
			{
				wrogowie.erase(wrogowie.begin() + i);
				i = 0;
			}
		}

		for (int i = wrogowie.size(); i < 6; i++)	//usuniecie przyciskow pokonanych graczy
		{
			przycisk[75 + i]->text.setString("");
		}

		for (int i = druzyna.size(); i < 4; i++) //wypelnienie reszty, nieaktywnych
		{
			przycisk[47 + i]->text.setString("");	//wyczyszczenie imienia pustego miejsca na osobe

			//wyczyszczenie statystyk o tej osobie
			j = 51+  i * 3;
			przycisk[j]->text.setString("");
			przycisk[j + 1]->text.setString("");
			przycisk[j + 2]->text.setString("");

			//usuniecie pozycji osoby z pustego miejsca
			int pozycja_postaci;
			pozycja_postaci = 62 + i * 3;
			przycisk[pozycja_postaci]->text.setString("");
			przycisk[pozycja_postaci + 1]->text.setString("");
			przycisk[pozycja_postaci + 2]->text.setString("");
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