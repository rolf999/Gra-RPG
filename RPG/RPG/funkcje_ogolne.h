#ifndef SOURCE_H
#define SOURCE_H
#include"postac.h"
#include"button.h"
#include "button_border.h"
#include<vector>
#include <fstream>
#include <algorithm>
#include <SFML/Graphics.hpp>

using namespace std;

//funkcja zapisujaca do pliku dane o graczach i poziomie druzyny
bool zapis_do_pliku(int poziom_druzyny, vector<postac*> druzyna, vector<eliksir> baza_eliksirow);
//funkcja odczytujaca dane z pliku
bool odczyt_z_pliku(int & poziom_druzyny, vector<postac*> &druzyna, vector<ubior> baza_przedmiotow, vector<eliksir> & baza_eliksirow);


//sprawdzenie czy pozycja myszy o wspolrzednych x, y nie 
//nalezy do ktoregos z przycisków umieszczonych w wektorze typu podanego w klasie szablonu
template <class T>
T * znajdz_przycisk(int x, int y, vector<T*> przyciski)
{
	for (vector<T*>::iterator aktualny = przyciski.begin(); aktualny != przyciski.end(); aktualny++)
	{
		sf::Vector2f pozycja_przycisku = (*aktualny)->text.getPosition();	//pobranie pozycji przycisku
		int rozmiar_czcionki = (*aktualny)->wielkosc_czcionki;	//pobranie wielkoœci czcionki przycisku
		string tekstu = (*aktualny)->text.getString();	//pobranie napisu z przycisku


														//sprawdenie czy podane wspó³rzêdne znajduj¹ siê na przycisku
		if ((x > pozycja_przycisku.x && x < (pozycja_przycisku.x + 0.55 * rozmiar_czcionki*tekstu.length())) &&
			(y > pozycja_przycisku.y && y < (pozycja_przycisku.y + rozmiar_czcionki)))
		{
			//poprzednio_zaznaczony = *aktualny;
			return *aktualny;	//zwrocenie przycisku
		}
	}

	return NULL;
}

//funkcja laduj¹ca liste ze srodowiska graficznego
void zaladuj_ekwipunek(vector<ubior> & ekwipunek, vector<button_border*> & lista, int poczatek, int koniec, int pierwszy_element);


//zwolnienie pamiêci ka¿dej z postaci w wektorze
void czysc_postac(vector<postac*> & druzyna);

//zwalnianie pamiêci przyciskow w menu
template<class T, class T2>
void czysc_menu(T & menu)
{
	for (vector<T2*>::iterator pomocniczy = menu.przycisk.begin(); pomocniczy != menu.przycisk.end(); pomocniczy++)
	{//usuniecie przycisków z menu
		delete *pomocniczy;
	}

	menu.przycisk.clear();
}

//sprawdzenie czy wszystkie postacie wykona³y ju¿ swój ruch
bool koniec_tury(vector<postac*> osoby);	

//sprawdzenie dzia³aj¹cych efektów ka¿dej osoby z dró¿yny
void spr_efekty(vector<postac*> osoby);	

//aktywacja postaci z danej dru¿yny
void aktywuj_postacie(vector<postac*> osoby);	

//przyznanie doœwiadczenia wszystkim postaciom z listy
void nagroda(vector<postac*> osoby);	

#endif