#pragma once
#ifndef PRZEDMIOTY_H
#define PRZEDMIOTY_H
#include<iostream>
#include<string>
using namespace std;

class efekt
{
public:
	double wielkosc;
	string typ;
	int czas;


	efekt(double wielkosc_, string typ_, int czas_ = 0) : wielkosc(wielkosc_), typ(typ_), czas(czas_)
	{};
	efekt() {};
};

class przedmioty
{
public:
	string nazwa;		//nazwa przedmiotu
	string typ;			//typ przedmiotu np. spodnie
	string klasa;		//dla jakiej klasy postaci


	przedmioty(string nazwa_, string typ_, string klasa_) : nazwa(nazwa_), typ(typ_) , klasa(klasa_)
	{};	//konstruktor
	przedmioty() {};

};

class ubior : public przedmioty
{
public:
	int obrona;		//ilosc punktow obrony danego przedmiotu
	efekt wlasciwosc;	//odpornosc na zywioly

	ubior(string nazwa_, string typ_ubioru, int obrona_, int wielkosc_efektu, string typ_efektu, string klasa_ = "brak")
		: przedmioty(nazwa_, typ_ubioru, klasa_), obrona(obrona_), wlasciwosc(efekt(wielkosc_efektu, typ_efektu))
	{};
	ubior() {};

	string wypisz()
	{
		if(typ != "bron")
			return (nazwa + " " + "obr. fizyczna " + to_string(obrona) + " " + wlasciwosc.typ + " " + to_string(int(wlasciwosc.wielkosc)));
		else
			return (nazwa + " " + "atak " + to_string(obrona) + " " + wlasciwosc.typ + " " + to_string(int(wlasciwosc.wielkosc)));
	}
};

class eliksir : public przedmioty
{
public:
	int czas;		//czas dzialania eliksiru, jesli 0 to staly
	int wielkosc;	//ilosc przyznanych punktow 
	int ilosc;		//ilosc eliksirow w ekwipunku
	

public:
	eliksir(string nazwa_, string typ_eliksiru, int wielkosc_, int ilosc_, int czas_ = 0, string klasa_ = "brak") : przedmioty(nazwa_, typ_eliksiru, klasa_), wielkosc(wielkosc_), ilosc(ilosc_), czas(czas_)
	{};
	
	string wypisz()
	{
			return (to_string(wielkosc) + " " + typ + " posiadasz " + to_string(ilosc));
	}
};

#endif