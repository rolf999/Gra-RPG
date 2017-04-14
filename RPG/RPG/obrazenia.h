#pragma once
#ifndef OBRAZENIA_H
#define OBRAZENIA_H
#include <map>
#include <string>
#include "postac.h"
#include<vector>

using namespace std;

class obrazenia
{
public:
	double fizyczne,
		ogien,
		powietrze,
		ziemia;	//obrazenia zadane danej postaci

	obrazenia()
	{

		fizyczne = 0;
		ogien = 0;
		powietrze = 0;
		ziemia = 0;
	}

	//dodaj obra�enia danego typu
	void dodaj(string gdzie, double ile)
	{
		if (gdzie == "fizyczne")	fizyczne += ile;
		else if (gdzie == "ogien")	ogien += ile;
		else if (gdzie == "powietrze")	powietrze += ile;
		else if (gdzie == "ziemia")	ziemia += ile;
	}

	//��czna ilosc zadanych obra�e�
	double laczny()
	{
		return fizyczne + ogien + powietrze +  ziemia;
	}

	//operator mno�enia (ka�dy typ obra�e� pomno�ony o d� zmienno�
	obrazenia operator*(double czynnik)
	{
		obrazenia wynik;
		wynik.fizyczne = czynnik*fizyczne;
		wynik.ogien = czynnik * ogien;
		wynik.powietrze = czynnik * powietrze;
		wynik.ziemia = czynnik * ziemia;
		return wynik;
	}

};

#endif