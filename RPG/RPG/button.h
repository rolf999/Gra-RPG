#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

enum typ_przycisku
{
	nawigacja,
	osoba,
	przedmiot,
	napis,
	slot,
	pole_tekstowe,
	ramka,
	lista,
	zarzadzanie_ekwipunkiem,
	mikstura,
	umiejet,
	pozycja,
	wrog,
	staty,
	przycisk_pozyc,
	atakuj
};



class button 
{
public:
	sf::Text text;
	typ_przycisku typ;	//typ, typ2 pola pomagajace scharakteryzowac guzik
	int typ2;
	sf::Font czcionka;
	int wielkosc_czcionki;
	

	button(string napis, typ_przycisku typ_,int typ2_, int x, int y, int wielkosc_czcionki_)
	{
		typ = typ_;	//nadanie typu
		typ2 = typ2_; //typ drugi
		text.setString(napis);	//nadanie wyswietlanego napisu
		czcionka.loadFromFile("arial.ttf");	
		text.setFont(czcionka);	//nadanie czcionki
		wielkosc_czcionki = wielkosc_czcionki_;
		text.setCharacterSize(wielkosc_czcionki_);	//wieloksc czcionki
		text.setPosition(float(x), float(y));
		text.setColor(sf::Color::Black);
	}

};

#endif