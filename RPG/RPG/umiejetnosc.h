#pragma once
#ifndef UMIEJETNOSC_H
#define UMIEJETNOSC_H
#include<string>

using namespace std;

class umiejetnosc
{

public:
	string nazwa;	//nazwa umiejetnosci
	
	int koszt_aktywacji;	//koszt podniesienia poziomu
	int poziom;		//poziom umiejetnosci

	umiejetnosc()
	{
		poziom = 0;
		koszt_aktywacji = (poziom + 1) * 300;
	}

	void podnies_poziom()
	{
		if (poziom < 3)
		{
			poziom++;
			koszt_aktywacji = (poziom + 1) * 300;
		}
	}

	int getKoszt(int poziom_)	//koszt uzycia umiejetnosci
	{
		return 50 * poziom_;
	}

	string wypisz()
	{
		return nazwa + "\t\t" + " poziom " + to_string(poziom);
	}
};




#endif