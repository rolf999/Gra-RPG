#include "przedmioty.h"
#include "postac.h"
#include<iostream>
#include<vector>
#include"obrazenia.h"


using namespace std;



void inicjalizacja(vector<ubior> & baza_przedmiotow, vector<eliksir> & baza_eliksirow)
{
	baza_przedmiotow.push_back(ubior("helm1", "glowa", 1, 0, "brak"));
	baza_przedmiotow.push_back(ubior("helm2", "glowa", 2, 10, "ogien"));
	baza_przedmiotow.push_back(ubior("helm3", "glowa", 3, 0, "brak"));
	baza_przedmiotow.push_back(ubior("helm4", "glowa", 4, 15, "ziemia"));
	baza_przedmiotow.push_back(ubior("helm5", "glowa", 5, 15, "powietrze"));
	baza_przedmiotow.push_back(ubior("helm7", "glowa", 7, 30, "powietrze"));
	baza_przedmiotow.push_back(ubior("helm10", "glowa", 8, 20, "ogien"));
	baza_przedmiotow.push_back(ubior("helm8", "glowa", 9, 20, "ogien", "class Wojownik"));
	baza_przedmiotow.push_back(ubior("helm9", "glowa", 10, 10, "ziemia", "class Wojownik"));
	baza_przedmiotow.push_back(ubior("helm6", "glowa", 15, 0, "brak", "class Wojownik"));


	baza_przedmiotow.push_back(ubior("zbroja1", "tlow", 5, 0, "brak"));
	baza_przedmiotow.push_back(ubior("zbroja2", "tlow", 6, 20, "ogien"));
	baza_przedmiotow.push_back(ubior("zbroja3", "tlow", 7, 20, "ziemia"));
	baza_przedmiotow.push_back(ubior("zbroja4", "tlow", 8, 25, "trucizna"));
	baza_przedmiotow.push_back(ubior("zbroja5", "tlow", 9, 20, "ogien"));
	baza_przedmiotow.push_back(ubior("zbroja6", "tlow", 10, 25, "powietrze", "class Wojownik"));
	baza_przedmiotow.push_back(ubior("zbroja7", "tlow", 10, 20, "ogien"));
	baza_przedmiotow.push_back(ubior("zbroja8", "tlow", 15, 20, "ziemia", "class Wojownik"));
	baza_przedmiotow.push_back(ubior("zbroja9", "tlow", 10, 30, "powietrze"));
	baza_przedmiotow.push_back(ubior("zbroja10", "tlow", 20, 50, "ogien", "class Wojownik"));

	baza_przedmiotow.push_back(ubior("spodnie1", "nogi", 2, 0, "brak"));
	baza_przedmiotow.push_back(ubior("spodnie2", "nogi", 3, 25, "ogien"));
	baza_przedmiotow.push_back(ubior("spodnie3", "nogi", 4, 25, "powietrze"));
	baza_przedmiotow.push_back(ubior("spodnie4", "nogi", 5, 25, "ziemia"));
	baza_przedmiotow.push_back(ubior("spodnie5", "nogi", 6, 25, "trucizna"));
	baza_przedmiotow.push_back(ubior("spodnie6", "nogi", 7, 25, "ogien"));
	baza_przedmiotow.push_back(ubior("spodnie7", "nogi", 9, 25, "trucizna"));
	baza_przedmiotow.push_back(ubior("spodnie8", "nogi", 10, 25, "ziemia"));
	baza_przedmiotow.push_back(ubior("spodnie9", "nogi", 10, 25, "trucizna", "class Wojownik"));
	baza_przedmiotow.push_back(ubior("spodnie10", "nogi", 13, 25, "ogien", "class Wojownik"));

	baza_przedmiotow.push_back(ubior("buty1", "stopy", 2, 0, "brak"));
	baza_przedmiotow.push_back(ubior("buty2", "stopy", 5, 10, "ziemia"));
	baza_przedmiotow.push_back(ubior("buty3", "stopy", 6, 16, "powietrze"));
	baza_przedmiotow.push_back(ubior("buty4", "stopy", 7, 17, "ziemia"));
	baza_przedmiotow.push_back(ubior("buty5", "stopy", 8, 19, "ogien"));
	baza_przedmiotow.push_back(ubior("buty6", "stopy", 9, 20, "powietrze"));
	baza_przedmiotow.push_back(ubior("buty7", "stopy", 10, 25, "ziemia"));
	baza_przedmiotow.push_back(ubior("buty8", "stopy", 9, 19, "ogien", "class Wojownik"));
	baza_przedmiotow.push_back(ubior("buty9", "stopy", 11, 20, "powietrze", "class Wojownik"));
	baza_przedmiotow.push_back(ubior("buty10", "stopy", 14, 19, "ziemia", "class Wojownik"));

	baza_przedmiotow.push_back(ubior("rekawice1", "rece", 1, 0, "brak"));
	baza_przedmiotow.push_back(ubior("rekawice2", "rece", 2, 6, "ziemia"));
	baza_przedmiotow.push_back(ubior("rekawice3", "rece", 3, 8, "powietrze"));
	baza_przedmiotow.push_back(ubior("rekawice4", "rece", 4, 9, "ogien"));
	baza_przedmiotow.push_back(ubior("rekawice5", "rece", 5, 10, "ogien"));
	baza_przedmiotow.push_back(ubior("rekawice6", "rece", 6, 11, "brak"));
	baza_przedmiotow.push_back(ubior("rekawice7", "rece", 7, 15, "ziemia"));
	baza_przedmiotow.push_back(ubior("rekawice8", "rece", 8, 17, "brak", "class Wojownik"));
	baza_przedmiotow.push_back(ubior("rekawice9", "rece", 9, 20, "ogien", "class Wojownik"));
	baza_przedmiotow.push_back(ubior("rekawice10", "rece", 10, 9, "powietrze", "class Wojownik"));

	baza_przedmiotow.push_back(ubior("luk1", "bron", 15, 0, "brak"));
	baza_przedmiotow.push_back(ubior("luk2", "bron", 30, 0, "brak"));
	baza_przedmiotow.push_back(ubior("luk3", "bron", 50, 9, "powietrze"));
	baza_przedmiotow.push_back(ubior("luk4", "bron", 90, 30, "ogien"));
	baza_przedmiotow.push_back(ubior("luk5", "bron", 130, 50, "powietrze"));

	baza_przedmiotow.push_back(ubior("laska1", "bron", 10, 0, "brak"));
	baza_przedmiotow.push_back(ubior("laska2", "bron", 15, 0, "brak"));
	baza_przedmiotow.push_back(ubior("laska3", "bron", 30, 9, "ogien"));
	baza_przedmiotow.push_back(ubior("laska4", "bron", 45, 13, "powietrze"));
	baza_przedmiotow.push_back(ubior("laska5", "bron", 60, 30, "ziemia"));
	baza_przedmiotow.push_back(ubior("laska6", "bron", 90, 40, "powietrze"));

	baza_przedmiotow.push_back(ubior("miecz1", "bron", 20, 0, "brak", "class Wojownik"));
	baza_przedmiotow.push_back(ubior("miecz2", "bron", 30, 0, "brak", "class Wojownik"));
	baza_przedmiotow.push_back(ubior("miecz3", "bron", 50, 15, "ogien", "class Wojownik"));
	baza_przedmiotow.push_back(ubior("miecz4", "bron", 90, 30, "powietrze", "class Wojownik"));
	baza_przedmiotow.push_back(ubior("miecz5", "bron", 150, 60, "ziemia", "class Wojownik"));
	baza_przedmiotow.push_back(ubior("miecz6", "bron", 300, 100, "powietrze", "class Wojownik"));

	baza_eliksirow.push_back(eliksir("maly   eliksir zycia", "HP", 40, 2, 0));
	baza_eliksirow.push_back(eliksir("sredni eliksir zycia", "HP", 80, 0, 0));
	baza_eliksirow.push_back(eliksir("duzy   eliksir zycia", "HP", 160, 0, 0));

	baza_eliksirow.push_back(eliksir("maly   eliksir wytrzymalosci", "wytrzymalosc", 40, 1, 0));
	baza_eliksirow.push_back(eliksir("sredni eliksir wytrzymalosci", "wytrzymalosc", 80, 0, 0));
	baza_eliksirow.push_back(eliksir("duzy   eliksir wytrzymalosci", "wytrzymalosc", 160, 0, 0));

	baza_eliksirow.push_back(eliksir("maly   eliksir mana", "mana", 40, 1, 0));
	baza_eliksirow.push_back(eliksir("sredni eliksir mana", "mana", 80, 0, 0));
	baza_eliksirow.push_back(eliksir("duzy   eliksir mana", "mana", 160, 0, 0));

	baza_eliksirow.push_back(eliksir("eliksir odpornosci", "fizyczne", 40, 0, 2));
	baza_eliksirow.push_back(eliksir("eliksir ataku", "atak", 40, 0, 2));
	baza_eliksirow.push_back(eliksir("eliksir na ogien", "ogien", 40, 0, 2));
	baza_eliksirow.push_back(eliksir("eliksir na powietrze", "powietrze", 40, 0, 2));
	baza_eliksirow.push_back(eliksir("eliksir na ziemie", "ziemia", 40, 1, 2));


}


string uzyj(int pozycja, postac * na_kim, vector<eliksir> & baza_eliksirow)
{
	string pomocniczy;
	if (baza_eliksirow[pozycja].ilosc > 0)
	{
		baza_eliksirow[pozycja].ilosc = baza_eliksirow[pozycja].ilosc - 1;	//pomniejszenie iloœci eliksirów

		if (baza_eliksirow[pozycja].typ == "atak")
			na_kim->zadane.fizyczne += baza_eliksirow[pozycja].wielkosc;	//dodanie ataku
		else if (baza_eliksirow[pozycja].typ == "HP")
			na_kim->HP += baza_eliksirow[pozycja].wielkosc;	//dodanie zdrowia
		else if (baza_eliksirow[pozycja].typ == "wytrzymalosc")
			na_kim->wytrzymalosc += baza_eliksirow[pozycja].wielkosc;	//dodanie wytrzymalosci
		else if (baza_eliksirow[pozycja].typ == "mana")
			na_kim->mana += baza_eliksirow[pozycja].wielkosc;	//dodanie many
		else														//dodania odpornosci
			na_kim->statystyka.dodaj(baza_eliksirow[pozycja].typ, baza_eliksirow[pozycja].wielkosc);




		if (baza_eliksirow[pozycja].czas != 0)
			na_kim->dzialajace_efekty.push_back(efekt(baza_eliksirow[pozycja].wielkosc, baza_eliksirow[pozycja].typ, baza_eliksirow[pozycja].czas));	//dodanie efektu czasowego
		return "uzyto eliksiru " + baza_eliksirow[pozycja].nazwa;
	}
	else
		return "brak eliksiru";
}

