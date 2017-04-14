#pragma once
#ifndef KLASY_H
#define KLASY_H

#include "postac.h"
#include <ctime>



class Mag : public virtual postac
{
public:
	vector<string> uzyj_umiejetnosci(int numer_umiejetnosci, vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	//---------------------funkcje umiejêtnoœci--------------------------------

	vector<string> kula_ognia(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	
	vector<string> morze_ognia(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	
	vector<string> trzesienie_ziemi(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	
	vector<string> leczenie(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	
	vector<string> tarcza(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	
	vector<string> kontrola(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);

	//--------------------------koniec funkcji umiejetnosci--------------------------------

	Mag(string imie_);
	Mag() {};
};

class Wojownik : public virtual postac
{
public:
	vector<string> uzyj_umiejetnosci(int numer_umiejetnosci, vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);

	//---------------------funkcje umiejêtnoœci--------------------------------

	vector<string> potezne_uderzenie(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	

	vector<string> obalenie(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	

	vector<string> mlyn(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	

	vector<string> podwojne_uderzenie(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	

	vector<string> modlitwa(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	

	vector<string> nieczysty_cios(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	
	//--------------------------koniec funkcji umiejetnosci--------------------------------

	Wojownik(string imie_);
	Wojownik() {};
};

class Lucznik : public virtual postac
{
public:
	vector<string> uzyj_umiejetnosci(int numer_umiejetnosci, vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	//---------------------funkcje umiejêtnoœci--------------------------------

	vector<string> strzala_zapalajaca(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	
	vector<string> potepienie(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	
	vector<string> grad_strzal(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	
	vector<string> strzala_wybuchowa(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	
	vector<string> zwiad(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	
	vector<string> strzal_w_noge(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	
	//--------------------------koniec funkcji umiejetnosci--------------------------------


	Lucznik(string imie_);
	Lucznik() {};
};

class Kaplan : public Mag, public Wojownik
{
public:
	vector<string> uzyj_umiejetnosci(int numer_umiejetnosci, vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	Kaplan(string imie_);
	Kaplan() {};
};

class Lotr : public Wojownik, public Lucznik
{
public:
	vector<string> uzyj_umiejetnosci(int numer_umiejetnosci, vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	Lotr(string imie_);
	Lotr() {};
};

class Druid : public Mag, public Lucznik
{
public:
	vector<string> uzyj_umiejetnosci(int numer_umiejetnosci, vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim);
	Druid(string imie_);
	Druid() {};
};
#endif