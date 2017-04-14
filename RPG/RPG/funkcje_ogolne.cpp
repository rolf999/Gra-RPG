#include "funkcje_ogolne.h"
#include"postac.h"
#include"klasy.h"
#include<vector>
#include <fstream>
#include <algorithm>
#include"button.h"
#include "button_border.h"
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace std;

//funkcja zapisujaca do pliku dane o graczach i poziomie druzyny
bool zapis_do_pliku(int poziom_druzyny, vector<postac*> druzyna, vector<eliksir> baza_eliksirow)
{
	fstream plik;	//otwarcie pliku do zapisu
	plik.open("postepy.sav", std::ios::out | ios::trunc);

	if (plik.good() == true && druzyna.size() == 4)	//na wypadek uszkodzonego pliku, lub druzyna za mala
	{
		//zapis
		plik << poziom_druzyny << "\n";	//poziom druzyny
		plik << druzyna.size() << "\n";	//wielkosc druzyny
		vector<ubior>::iterator ekwip;	//iteratory pomocnicze
		map <string, ubior>::iterator w_uzyciu;

		for (vector<postac*>::iterator pomocniczy = druzyna.begin(); pomocniczy != druzyna.end(); pomocniczy++)
		{
			plik << typeid(*(*pomocniczy)).name() << "\n" <<	//nazwa klasy (RTTI)
				((*pomocniczy)->imie).c_str() << "\n" <<     	//zapisanie informacji o postaci
				(*pomocniczy)->pozycja << "\n" <<
				(*pomocniczy)->HP << "\n" <<
				(*pomocniczy)->wytrzymalosc << "\n" <<
				(*pomocniczy)->mana << "\n" <<
				(*pomocniczy)->doswiadczenie << "\n" <<
				(*pomocniczy)->maxzdrowie << "\n" <<
				(*pomocniczy)->maxwytrzymalosc << "\n" <<
				(*pomocniczy)->maxmana << "\n" <<
				(*pomocniczy)->odnawianie_many << "\n" <<
				(*pomocniczy)->odnawianie_wytrzymalosci << "\n";

			//zapisanie poziomow umiejetnosci

			for (int i = 0; i < 7; i++)
			{
				plik << (*pomocniczy)->ataki[i].poziom << "\n";
			}

			//zapisanie posiadanego przez postac ekwipunku
			for (ekwip = (*pomocniczy)->ekwipunek.begin(); ekwip != (*pomocniczy)->ekwipunek.end(); ekwip++)
			{
				plik << ekwip->nazwa << "\n";
			}

			plik << "AAAAkoniecekwipunkuAAAAA\n";	//straznik

													//zapisanie nalozzonego ekwipunku
			for (w_uzyciu = (*pomocniczy)->aktualnie_uzywane.begin(); w_uzyciu != (*pomocniczy)->aktualnie_uzywane.end(); w_uzyciu++)
			{
				plik << w_uzyciu->second.nazwa << "\n";
			}

			plik << "AAAAkoniecwurzyciuAAAAA\n";	//straznik

		}

		//zapisanie ilosci eliksirow 
		for (vector<eliksir>::iterator p = baza_eliksirow.begin(); p != baza_eliksirow.end(); p++)
		{
			plik << (*p).ilosc << "\n";
		}
		return true;
	}
	else
		return false;

	plik.close();	//zamkniecie pliku
}


bool odczyt_z_pliku(int & poziom_druzyny, vector<postac*> &druzyna, vector<ubior> baza_przedmiotow, vector<eliksir> & baza_eliksirow)
{
	fstream plik;
	plik.open("postepy.sav", std::ios::in);

	if (plik.good() == true)  //na wypadek uszkodzonego pliku
	{
		cout << "//odczyt";
		//odczyt
		plik >> poziom_druzyny;	//wczytanie poziomu druzyny
		int wielkosc_druzyny;
		plik >> wielkosc_druzyny;	//wczytanie wieloksci druzyny


		string klasa;	//zmienna na nazwe klasy aktualnie czytanej postaci
		string imie;	//zmienna na imie czytanej postaci
						//zmienne pomocnicze
		string pomoc;
		ubior znaleziony;

		for (int i = 0; i < wielkosc_druzyny; i++)
		{
			plik >> klasa;		//wczytanie nazwy klasy
			plik >> pomoc;
			klasa += pomoc;
			plik >> imie;		//wczytanie nazwy postaci

								//tworzenie postaci
			if (klasa == "classMag")
				druzyna.push_back(new Mag(imie));
			else if (klasa == "classWojownik")
				druzyna.push_back(new Wojownik(imie));
			else if (klasa == "classLucznik")
				druzyna.push_back(new Lucznik(imie));
			else if (klasa == "classKaplan")
				druzyna.push_back(new Kaplan(imie));
			else if (klasa == "classLotr")
				druzyna.push_back(new Lotr(imie));
			else if (klasa == "classDruid")
				druzyna.push_back(new Druid(imie));

			//wczytanie informacji o postaci
			plik >> druzyna[i]->pozycja >>
				druzyna[i]->HP >>
				druzyna[i]->wytrzymalosc >>
				druzyna[i]->mana >>
				druzyna[i]->doswiadczenie >>
				druzyna[i]->maxzdrowie >>
				druzyna[i]->maxwytrzymalosc >>
				druzyna[i]->maxmana >>
				druzyna[i]->odnawianie_many >>
				druzyna[i]->odnawianie_wytrzymalosci;

			for (int j = 0; j < 7; j++)
			{
				plik >> druzyna[i]->ataki[j].poziom;
			}

			//wczytanie ekwipunku
			plik >> pomoc;
			while (pomoc != "AAAAkoniecekwipunkuAAAAA")
			{
				//wyszukanie elementu w bazie
				for (vector<ubior>::iterator p = baza_przedmiotow.begin(); p != baza_przedmiotow.end(); p++)
					if ((*p).nazwa == pomoc)
					{
						znaleziony = *p;
						break;
					}
				druzyna[i]->ekwipunek.push_back(znaleziony);
				plik >> pomoc;
			}

			//wczytanie nalozonych przedmiotow
			plik >> pomoc;	//wczytanie nazwy zalozonego ekwipunku
			while (pomoc != "AAAAkoniecwurzyciuAAAAA")
			{
				//wyszukanie elementu w bazie
				for (vector<ubior>::iterator p = baza_przedmiotow.begin(); p != baza_przedmiotow.end(); p++)
					if ((*p).nazwa == pomoc)
					{
						znaleziony = *p;
						break;
					}
				//dodanie go do ekwipunku
				druzyna[i]->ekwipunek.push_back(znaleziony);
				//zalozenie dodanego elementu do ekwipunku
				druzyna[i]->zaluz(druzyna[i]->ekwipunek.size() - 1);
				plik >> pomoc;
			}

			//usuniecie elementow dodanych przy tworzeniu postaci (standordowo dodnych podczas tworzenia postaci)
			for (int j = 0; j < 6; j++)
				druzyna[i]->ekwipunek.pop_back();
		}

		//zapisanie eliksirow
		for (vector<eliksir>::iterator p = baza_eliksirow.begin(); p != baza_eliksirow.end(); p++)
		{
			plik >> (*p).ilosc ;
		}

		plik.close();	//zamkniecie pliku

		if (druzyna.size() != 4)	//sprawdzenie poprawnosci odczytu
			return false;
		else
			return true;
	}
	else
	{
		plik.close();	//zamkniecie pliku
		return false;
	}


}




void zaladuj_ekwipunek(vector<ubior> & ekwipunek, vector<button_border*> & lista, int poczatek, int koniec, int pierwszy_element)
{
	//nadanie barierom koloru zielonego
	lista[koniec - 1]->ramka.setOutlineColor(sf::Color::Green);
	lista[koniec]->ramka.setOutlineColor(sf::Color::Green);

	if (ekwipunek.size() >= 0)
	{
		for (int i = 0; i < ekwipunek.size() && i < (koniec - poczatek - 1); i++) //(koniec - poczatek -1) maksymalna liczba wyswietlanych przedmiotow z ekwipunku
		{//wypelnienie listy ekwipunkiem
			lista[poczatek + i]->text.setString(ekwipunek[i + pierwszy_element].nazwa);	//wypisanie ekwipunku
			lista[poczatek + i]->typ2 = i + pierwszy_element;
		}

		if (ekwipunek.size() < (koniec - poczatek - 1))
		{//wypelnienie pozostalych elementow listy, na ktore zabraklo pol z ekwipunku
			for (int i = ekwipunek.size(); i <= (koniec - poczatek - 1); i++)
			{
				lista[poczatek + i]->text.setString("");
				lista[poczatek + i]->typ2 = 0;
			}
		}
		// ustawienie koloru znacznikow pokazujacych czy lista wyswietla wszystkie elementy
		if (lista[poczatek]->typ2 != 0)
			lista[koniec - 1]->ramka.setOutlineColor(sf::Color::Red);
		if ((lista[koniec - 2]->typ2 != ekwipunek.size() - 1))
			lista[koniec]->ramka.setOutlineColor(sf::Color::Red);
		if ((ekwipunek.size() < (koniec - poczatek - 1)))
			lista[koniec]->ramka.setOutlineColor(sf::Color::Green);

	}
}


void czysc_postac(vector<postac*> & druzyna)
{
	for (vector<postac*>::iterator pomocniczy = druzyna.begin(); pomocniczy != druzyna.end(); pomocniczy++)
	{
		(*pomocniczy)->dzialajace_efekty.clear();
		(*pomocniczy)->ekwipunek.clear();
		(*pomocniczy)->aktualnie_uzywane.clear();

		if (typeid((*pomocniczy)).name() == "class Mag")	//usuniecie w zaleznosci od klasy postaci
			delete dynamic_cast<Mag*>(*pomocniczy);
		else if (typeid((*pomocniczy)).name() == "class Wojownik")
			delete dynamic_cast<Wojownik*>(*pomocniczy);
		else if (typeid((*pomocniczy)).name() == "class Lucznik")
			delete dynamic_cast<Lucznik*>(*pomocniczy);
		else if (typeid((*pomocniczy)).name() == "class Lotr")
			delete dynamic_cast<Lotr*>(*pomocniczy);
		else if (typeid((*pomocniczy)).name() == "class Kaplan")
			delete dynamic_cast<Kaplan*>(*pomocniczy);
		else if (typeid((*pomocniczy)).name() == "class Druid")
			delete dynamic_cast<Druid*>(*pomocniczy);
	}

	druzyna.clear();
}



bool koniec_tury(vector<postac*> osoby)	//sprawdzenie czy wszystkie postacie wykona³y ju¿ swój ruch
{
	bool wynik = false;

	for (vector<postac*>::iterator pom = osoby.begin(); pom != osoby.end(); pom++)
	{
		wynik = wynik || (*pom)->czy_atakowac;
	}

	return !wynik;
}

void spr_efekty(vector<postac*> osoby)		//sprawdzenie dzia³aj¹cych efektów ka¿dej osoby z dró¿yny
{
	for (vector<postac*>::iterator pom = osoby.begin(); pom != osoby.end(); pom++)
	{
		(*pom)->sprawdz_efekty();
	}
}

void aktywuj_postacie(vector<postac*> osoby)	//aktywacja postaci z danej dru¿yny
{
	for (vector<postac*>::iterator pom = osoby.begin(); pom != osoby.end(); pom++)
	{
		if ((*pom)->czy_obalony != true)
			(*pom)->czy_atakowac = true;
	}
}

void nagroda(vector<postac*> osoby)	//przyznanie doœwiadczenia wszystkim postaciom z listy
{
	for (vector<postac*>::iterator pom = osoby.begin(); pom != osoby.end(); pom++)
	{
		(*pom)->doswiadczenie += 300;
	}
}