#pragma once
#ifndef MENU_NOWA_GRA_H
#define MENU_NOWA_GRA_H

#include "button_border.h"
#include <string>
#include <vector>

class nowa_gra
{
public:
	vector<button_border*> przycisk;
	button_border* poprzednio_zaznaczony;
	int klasy[4];
	string imiona[4];
	int ktora_klasa, ktora_postac;

	nowa_gra()
	{
		//domyslne wartosci klas
		ktora_klasa = 0;
		ktora_postac = 0;
		klasy[0] = 0;
		klasy[1] = 0;
		klasy[2] = 0;
		klasy[3] = 0;
		imiona[0] = "brak";
		imiona[1] = "brak";
		imiona[2] = "brak";
		imiona[3] = "brak";
		//0-4
		przycisk.push_back(new button_border("Lista postaci", typ_przycisku::napis, 0, 20, 20, 30, 0));
		przycisk.push_back(new button_border("PUSTO", typ_przycisku::slot, 0, 20, 80, 40));
		przycisk.push_back(new button_border("PUSTO", typ_przycisku::slot, 1, 20, 140, 40));
		przycisk.push_back(new button_border("PUSTO", typ_przycisku::slot, 2, 20, 200, 40));
		przycisk.push_back(new button_border("PUSTO", typ_przycisku::slot, 3, 20, 260, 40));
	//5-6
		przycisk.push_back(new button_border("Zatwierdz", typ_przycisku::nawigacja, 0, 20, 460, 40,5));
		przycisk.push_back(new button_border("Wroæ", typ_przycisku::nawigacja, 1, 20, 520, 40,5));
	//7-13
		przycisk.push_back(new button_border("Klasy :", typ_przycisku::napis, 0, 250, 20, 30, 0));
		przycisk.push_back(new button_border("MAG", typ_przycisku::osoba, 0, 250, 80, 40,5));
		przycisk.push_back(new button_border("WOJOWNIK", typ_przycisku::osoba, 1, 250, 140, 40,5));
		przycisk.push_back(new button_border("£UCZNIK", typ_przycisku::osoba, 2, 250, 200, 40,5));
		przycisk.push_back(new button_border("KAP£AN", typ_przycisku::osoba, 3, 250, 260, 40,5));
		przycisk.push_back(new button_border("£OTR", typ_przycisku::osoba, 4, 250, 320, 40,5));
		przycisk.push_back(new button_border("DRUID", typ_przycisku::osoba, 5, 250, 380, 40,5));
	//14-15
		przycisk.push_back(new button_border("Imie : ", typ_przycisku::napis, 3, 500, 20, 30, 0));
		przycisk.push_back(new button_border("brak", typ_przycisku::pole_tekstowe, 3, 600, 20, 40, 5));

		poprzednio_zaznaczony = NULL;
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