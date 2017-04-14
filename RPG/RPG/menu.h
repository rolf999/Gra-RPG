#pragma once
#ifndef MENU_H
#define MENU_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "button.h"
#include <string>

using namespace std;


class menu
{
public:
	vector<button*> przycisk;
	button* poprzednio_zaznaczony;
	
	menu()
	{
		przycisk.push_back(new button("Nowa gra", typ_przycisku::nawigacja,0, 350, 180, 80));
		przycisk.push_back(new button("Kontytuuj", typ_przycisku::nawigacja,1, 350, 260, 80));
		przycisk.push_back(new button("Wyjdz", typ_przycisku::nawigacja,2, 350, 340, 80));
		poprzednio_zaznaczony = NULL;
	}

	void draw(sf::RenderWindow & okno)
	{
		for (vector<button*>::iterator aktualny = przycisk.begin(); aktualny != przycisk.end(); aktualny++)
		{
			okno.draw((*aktualny)->text);
		}
	}

};



#endif