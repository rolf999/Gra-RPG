#pragma once
#ifndef POSTAC_H
#define POSTAC_H

#include <vector>
#include <map>
#include <string>
#include "przedmioty.h"
#include "obrazenia.h"
#include "umiejetnosc.h"

using namespace std;


class postac
{

public:
	string imie;//nadane imie
	double pozycja,	//aktualna pozycja postaci
		HP,			//o postaci
		wytrzymalosc,
		mana,
		doswiadczenie,
		maxzdrowie,
		maxwytrzymalosc,
		maxmana,
		odnawianie_many,
		odnawianie_wytrzymalosci;
	
	bool czy_atakowac;
	bool czy_obalony;

	umiejetnosc ataki[7];					//tablica z danymi o umiejêtnoœci

	vector<efekt> dzialajace_efekty;		//efekty dzia³aj¹ce na postaæ
	obrazenia statystyka;					//statystyka postaci czyli obrazenia, zdrowie itd.
	obrazenia zadane;						//zadane obrazenia
	vector<ubior> ekwipunek;				//posiadany ekwipunek
	map <string, ubior> aktualnie_uzywane;	//do zak³adania 
	
	//konstruktory
	postac() {};
	postac(string imie_);

	//za³o¿enia konkretnej czêœci ekwipunku
	string zaluz(int);	

	//usuniêcie ¿eczy z ekwipunku
	string usun(int);	

	//sprawdzenie wektora dzialajacych efektow
	void sprawdz_efekty();

	//odebranie obrazen pomniejszonych o posiadana odpornosc
	obrazenia odbierz_obrazenia(obrazenia zadane);

	//funkcja pozwalajaca uzyc wybranej umiejetnosci
	virtual vector<string> uzyj_umiejetnosci(int numer_umiejetnosci, vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);

	//podstawowa funkcja do zadawania obrazeñ, i zwracajaca wektor z informacjami o zadanych obrazeniach
	string atak(postac * przeciwnik, obrazenia przeprowadzony_atak);
	
	//podstawowa umiejetnosc
	vector<string> atak_podstawowy(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);

	//funkcja testowa
	void wypisz();
	

};



#endif