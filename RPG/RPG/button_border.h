#pragma once
#ifndef BUTTON_BORDER_H
#define BUTTON_BORDER_H
#include "button.h"

using namespace std;


class button_border : public button
{
public:

	sf::RectangleShape ramka;
	

	button_border(string napis, typ_przycisku typ_, int typ2_, int x, int y, double wielkosc_czcionki_,double dlugosc_ramki = 4) : button(napis, typ_,typ2_, x, y, wielkosc_czcionki_)
	{
		sf::RectangleShape ramka2;

		ramka.setSize(sf::Vector2f(float(wielkosc_czcionki_)*float(dlugosc_ramki), float(wielkosc_czcionki_+10)));
		ramka.setPosition(x, y);
		if (typ_ == typ_przycisku::ramka)	//tworzenie ramki, a nie przycisku
		{
			text.setString("");	//skasowanie napisu
			ramka.setSize(sf::Vector2f( float(wielkosc_czcionki_),float(dlugosc_ramki) ));
			if(napis == "Black")	//ustawienie koloru
				ramka.setOutlineColor(sf::Color::Black);
			else if (napis == "Blue")
				ramka.setOutlineColor(sf::Color::Blue);
			else if (napis == "Green")
				ramka.setOutlineColor(sf::Color::Green);
			else if (napis == "Red")
				ramka.setOutlineColor(sf::Color::Red);
			else if (napis == "White")
				ramka.setOutlineColor(sf::Color::White);
			else if (napis == "Yellow")
				ramka.setOutlineColor(sf::Color::Yellow);
			else if (napis == "Cyan")
				ramka.setOutlineColor(sf::Color::Cyan);
			else //na wypadk podana zlego koloru
				ramka.setOutlineColor(sf::Color::Green);

			ramka.setOutlineThickness(float(typ2));
		}
		else
			ramka.setFillColor(sf::Color::Green);
	}
};

#endif