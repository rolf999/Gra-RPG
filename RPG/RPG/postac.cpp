#include <iostream>
#include "postac.h"

using namespace std;

postac::postac(string imie_)
{
	czy_obalony = false;;
	czy_atakowac = true;
	imie = imie_;
	pozycja = 3;
	HP = 0;
	wytrzymalosc = 0;
	mana = 0;
	doswiadczenie = 0;
	maxzdrowie = 0;
	maxwytrzymalosc = 0;
	maxmana = 0;
	odnawianie_many = 0;
	odnawianie_wytrzymalosci = 0;
	//nadanie poczatkowego ekwipunku
	statystyka.fizyczne = 11;

	aktualnie_uzywane["glowa"] = ubior("helm1", "glowa", 1, 0, "brak");
	aktualnie_uzywane["nogi"] = ubior("spodnie1", "nogi", 2, 0, "brak");
	aktualnie_uzywane["stopy"] = ubior("buty1", "stopy", 2, 0, "brak");
	aktualnie_uzywane["rece"] = ubior("rekawice1", "rece", 1, 0, "brak");
	aktualnie_uzywane["tlow"] = ubior("zbroja1", "tlow", 5, 0, "brak");

	//wyzerowanie poziomu wszystkich ataków
	for (int i = 0; i < 7;i++)
	{
		ataki[i].poziom = 0;
	}
	//nadanie pierwszego ataku
	ataki[0].podnies_poziom();	//nadanie podstawowej umiejêtnoœci
	ataki[0].nazwa = "atak podstawowy";

}

void postac::sprawdz_efekty()
{
	int ktory;
	ktory = 0;
	//vector<efekt>::iterator pomocniczy = dzialajace_efekty.begin();
	while (ktory < int(dzialajace_efekty.size()))
	{
		if ((dzialajace_efekty[ktory].typ == "powietrze") || (dzialajace_efekty[ktory].typ == "fizyczne") ||
			(dzialajace_efekty[ktory].typ == "ogien") || (dzialajace_efekty[ktory].typ == "ziemia"))
		{
			if (dzialajace_efekty[ktory].czas == 0)
			{
				statystyka.dodaj(dzialajace_efekty[ktory].typ, -dzialajace_efekty[ktory].wielkosc);	//odjecie efektu
				dzialajace_efekty.erase(dzialajace_efekty.begin() + ktory);
			}
			else
			{
				dzialajace_efekty[ktory].czas--;
				ktory++;
			}

		}
		else if (dzialajace_efekty[ktory].typ == "atak")
		{
			if (dzialajace_efekty[ktory].czas == 0)
			{
				zadane.fizyczne -= dzialajace_efekty[ktory].wielkosc;//odjecie efektu
				dzialajace_efekty.erase(dzialajace_efekty.begin() + ktory);
			}
			else
			{
				dzialajace_efekty[ktory].czas--;
				ktory++;
			}

		}
		else if (dzialajace_efekty[ktory].typ == "obalenie")
		{
			if (dzialajace_efekty[ktory].czas != 0)
			{
				dzialajace_efekty[ktory].czas--;
				//rzucenie wyj¹tku
				czy_atakowac = false;	//obalenie
				czy_obalony = true;
				ktory++;
			}
			else
			{
				czy_obalony = false;
				dzialajace_efekty.erase(dzialajace_efekty.begin() + ktory);
			}

		}
		else if (dzialajace_efekty[ktory].typ == "modlitwa")
		{
			if (dzialajace_efekty[ktory].czas == 0)
			{
				HP -= dzialajace_efekty[ktory].wielkosc;
				dzialajace_efekty.erase(dzialajace_efekty.begin() + ktory);
			}
			else
			{
				dzialajace_efekty[ktory].czas--;
				ktory++;
			}

		}
		else if (dzialajace_efekty[ktory].typ == "podpalenie")
		{
			if (dzialajace_efekty[ktory].czas != 0)
			{
				HP -= dzialajace_efekty[ktory].wielkosc;
				dzialajace_efekty[ktory].czas--;
				ktory++;
			}
			else
				dzialajace_efekty.erase(dzialajace_efekty.begin() + ktory);
		}
	}
}

obrazenia postac::odbierz_obrazenia(obrazenia zadane_)
{
	zadane = zadane*double(1 / pozycja);	//pomniejszenie obrazen 
	//w przypadku odpornosci na ataki fizyczne wieksze od 100% 
	//aby postac nie dostawa³a dodatkowegozdrowia
	double obrazenia_fizyczne = statystyka.fizyczne;
	if (obrazenia_fizyczne > 100) obrazenia_fizyczne = 100;

	obrazenia otrzymane;
	otrzymane.fizyczne = (1 - obrazenia_fizyczne / 100)*zadane_.fizyczne;
	otrzymane.ogien = (1 - statystyka.ogien / 100)*zadane_.ogien;
	otrzymane.powietrze = (1 - statystyka.powietrze / 100)*zadane_.powietrze;
	otrzymane.ziemia = (1 - statystyka.ziemia / 100)*zadane_.ziemia;
	HP -= otrzymane.fizyczne + otrzymane.ogien + otrzymane.powietrze +
		otrzymane.ziemia ;
	return otrzymane;
}

string postac::zaluz(int pozycja)
{
	ubior aktualny = aktualnie_uzywane[ekwipunek[pozycja].typ];	//aktualnie noszone
	ubior do_zalozenia = ekwipunek[pozycja];					//to ktore ma zostac nalozone

	ekwipunek.push_back(aktualny);	//dodaj do ekwipunku aktualnie noszony element
	aktualnie_uzywane[aktualny.typ] = do_zalozenia;	//przypisz na miejsce aktualnie uzywanego elementu ten wybrany
	if (do_zalozenia.typ == "bron")
	{
		zadane.fizyczne = do_zalozenia.obrona;	//ustawienie nowych obrazeñ
		if (aktualny.wlasciwosc.typ != "brak")	//zdjêcie dodatkowych obra¿eñ od broni
			zadane.dodaj(aktualny.wlasciwosc.typ, -aktualny.wlasciwosc.wielkosc);
		if (do_zalozenia.typ != "brak")			//dodanie dodatkowych obra¿eñ broni
			zadane.dodaj(do_zalozenia.wlasciwosc.typ, do_zalozenia.wlasciwosc.wielkosc);
	}	
	else
	{
		statystyka.fizyczne -= aktualny.obrona;
		statystyka.fizyczne += do_zalozenia.obrona;
		if (aktualny.wlasciwosc.typ != "brak")
			statystyka.dodaj(aktualny.wlasciwosc.typ, -aktualny.wlasciwosc.wielkosc);
		if (do_zalozenia.typ != "brak")
			statystyka.dodaj(do_zalozenia.wlasciwosc.typ, do_zalozenia.wlasciwosc.wielkosc);
	}
	

	ekwipunek.erase(ekwipunek.begin() + pozycja); //usun wstawiony element z ekwipunku

	return "zalozono " + aktualnie_uzywane[ekwipunek[pozycja].typ].nazwa;	//zwrucenie komunikatu
}
string postac::usun(int pozycja)
{
	string pomocniczy;
	pomocniczy = "usunieto " + ekwipunek[pozycja].nazwa;	//zapisanie komunikatu
	ekwipunek.erase(ekwipunek.begin() + pozycja);			//ususniecie przedmiotu
	return pomocniczy;										//zwrucenie komunikatu
}

vector<string> postac::uzyj_umiejetnosci(int numer_umiejetnosci ,vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim = 0)
{
	switch (numer_umiejetnosci)
	{
	case 0:
		return atak_podstawowy(sojusznicy, wrogowie, poziom, na_kim);
	default:
		vector<string> wynik;
		wynik.push_back("blad");
		return wynik;
	}
}

//podstawowa funkcja do zadawania obrazeñ
string postac::atak(postac * przeciwnik, obrazenia przeprowadzony_atak)
{
	przeprowadzony_atak = przeprowadzony_atak*double(1 / pozycja);
	obrazenia otrzymane;		//do przechowania obrazeñ
	otrzymane = przeciwnik->odbierz_obrazenia(przeprowadzony_atak);	//zadanie obraeñ
	return przeciwnik->imie + "\t"
		+ "\t" + to_string(int(otrzymane.fizyczne))
		+ " \t" + to_string(int(otrzymane.ogien))
		+ "\t" + to_string(int(otrzymane.powietrze))
		+ "\t" + to_string(int(otrzymane.ziemia));
	//wypisanie informacji o zadanych obrazeniach
}

//podstawowa umiejetnosc
vector<string> postac::atak_podstawowy(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> pomocniczy;
	pomocniczy.push_back(atak(wrogowie[na_kim], zadane*poziom));
	return pomocniczy;
}


void postac::wypisz()		//funkcja testowa
{
	cout << "STATYSTYKA\n" <<
		"HP" << HP <<
		"	wytrzymalosc" << wytrzymalosc <<
		"	mana" << mana <<
		"\nZADANE\n";

	cout << "DZIALAJACE EFEKTY\n";
	if (dzialajace_efekty.size() != 0)
	{
		vector<efekt>::iterator pomocniczy;
		for (pomocniczy = dzialajace_efekty.begin(); pomocniczy != dzialajace_efekty.end(); pomocniczy++)
			cout << pomocniczy->typ << " " << pomocniczy->wielkosc << " " << pomocniczy->czas << endl;
	}

	cout << "EKWIPUNEK\n";
	if (ekwipunek.size() != 0)
	{
		vector<ubior>::iterator pomocniczy;
		for (pomocniczy = ekwipunek.begin(); pomocniczy != ekwipunek.end(); pomocniczy++)
			cout << pomocniczy->nazwa << endl;
	}

	cout << "AKTUALNIE UZYWANE\n";
	if (aktualnie_uzywane.size() != 0)
	{
		map<string, ubior>::iterator pomocniczy;
		for (pomocniczy = aktualnie_uzywane.begin(); pomocniczy != aktualnie_uzywane.end(); pomocniczy++)
			cout << pomocniczy->first << " " << pomocniczy->second.nazwa << endl;
	}
}