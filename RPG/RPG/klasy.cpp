#include <iostream>
#include "klasy.h"
#include"postac.h"

//--------------------------------------MAG----------------------------------------------------
Mag::Mag(string imie_) : postac(imie_)
{
	HP = 150;
	maxzdrowie = 10;
	mana = 300;
	maxmana = 100;
	odnawianie_many = 20;
	aktualnie_uzywane["bron"] = ubior("laska1", "bron", 10, 0, "brak", "Mag");
	zadane.fizyczne = aktualnie_uzywane["bron"].obrona;


	ataki[1].nazwa = "Kula ognia";
	ataki[2].nazwa = "Morze ognia";
	ataki[3].nazwa = "Trzesienie ziemi";
	ataki[4].nazwa = "Leczenie";
	ataki[5].nazwa = "Tarcza";
	ataki[6].nazwa = "Kontrola";

	
}

//----------------umiejetnosci-----------------------------

vector<string> Mag::kula_ognia(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> wynik;

	if (mana > poziom * 50)	//sprawdzenie czy mozna u¿yc
	{
		mana -= poziom * 50;

		obrazenia nowe;
		nowe.dodaj("ogien", zadane.laczny());
		wynik.push_back(atak(wrogowie[na_kim], nowe * 3 * poziom));

	}
	else
		wynik.push_back("za ma³o many");

	return wynik;
}
vector<string> Mag::morze_ognia(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> wynik;

	if (mana > poziom * 50)	//sprawdzenie czy mozna u¿yc
	{
		mana -= poziom * 50;

		obrazenia nowe;
		nowe.dodaj("ogien", zadane.laczny()*0.5*poziom);	//dodanie obrazen od ognia

		for (vector<postac*>::iterator pomocniczy = wrogowie.begin(); pomocniczy != wrogowie.end(); pomocniczy++)
		{//zadanie obrazeñ oraz dodanie komentarza o zadanych obrazeniach
			wynik.push_back(atak(*pomocniczy, nowe));
		}
	}
	else
		wynik.push_back("za ma³o many");

	return wynik;
}
vector<string> Mag::trzesienie_ziemi(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> wynik;

	if (mana > poziom * 50)	//sprawdzenie czy mozna u¿yc
	{
		mana -= poziom * 50;

		obrazenia nowe;
		nowe.dodaj("ziemia", zadane.laczny() * 2 * poziom);	//dodanie obrazen od ziemi

		for (vector<postac*>::iterator pomocniczy = wrogowie.begin(); pomocniczy != wrogowie.end(); pomocniczy++)
		{//zadanie obrazeñ oraz dodanie komentarza o zadanych obrazeniach
			wynik.push_back(atak(*pomocniczy, nowe));
		}

		//zadanie obrazeñ sprzymierzeñcom na pozycji przed atakuj¹cym
		for (vector<postac*>::iterator pomocniczy = sojusznicy.begin(); pomocniczy != sojusznicy.end(); pomocniczy++)
		{//zadanie obrazeñ oraz dodanie komentarza o zadanych obrazeniach
			if (((*pomocniczy)->pozycja < pozycja) && (*pomocniczy != this))
				wynik.push_back(atak(*pomocniczy, nowe));
		}


	}
	else
		wynik.push_back("za ma³o many");

	return wynik;
}
vector<string> Mag::leczenie(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> wynik;

	if (mana > poziom * 50)	//sprawdzenie czy mozna u¿yc
	{
		mana -= poziom * 50;

		HP += poziom * 200;		//dodanie zdrowia
		if (HP > maxzdrowie)	//zabezpieczenie przed wyjœciem po za skale
			HP = maxzdrowie;

		wynik.push_back(sojusznicy[na_kim]->imie + " uleczony");
	}
	else
		wynik.push_back("za ma³o many");

	return wynik;
}
vector<string> Mag::tarcza(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> wynik;

	if (mana > poziom * 50)	//sprawdzenie czy mozna u¿yc
	{
		mana -= poziom * 50;
		string typ;
		if (poziom == 1) typ = "powietrze";
		else if (poziom == 2) typ = "fizyczne";
		else typ = "ogien";

		for (vector<postac*>::iterator pomocniczy = sojusznicy.begin(); pomocniczy != sojusznicy.end(); pomocniczy++)
		{//zadanie obrazeñ oraz dodanie komentarza o zadanych obrazeniach
			(*pomocniczy)->dzialajace_efekty.push_back(efekt(50, typ, 1));	//dodanie efektu
			(*pomocniczy)->statystyka.dodaj(typ, 50);	//dodanie wlasciwosci
		}
		wynik.push_back("uzyto zaklecia tarczy");
	}
	else
		wynik.push_back("za ma³o many");

	return wynik;
}
vector<string> Mag::kontrola(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	srand(time(NULL));
	vector<string> wynik;

	if (mana > poziom * 50)	//sprawdzenie czy mozna u¿yc
	{
		mana -= poziom * 50;

		wynik.push_back("uzyto zaklecia kontrola");
		int los = rand() % wrogowie.size();		//wylosowanie przeciwnika

		if (wrogowie[na_kim] != wrogowie[los]) //nie mo¿e atakowaæ siebie
			wynik.push_back(wrogowie[na_kim]->atak(wrogowie[los], wrogowie[na_kim]->zadane*poziom));


	}
	else
		wynik.push_back("za ma³o many");

	return wynik;
}


//----------------koniec umiejetnosc----------------------

vector<string> Mag::uzyj_umiejetnosci(int numer_umiejetnosci, vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim = 0)
{

	switch (numer_umiejetnosci)
	{
	case 0:
		return atak_podstawowy(sojusznicy, wrogowie, poziom, na_kim);
	case 1:
		return kula_ognia(sojusznicy, wrogowie, poziom, na_kim);
	case 2:
		return morze_ognia(sojusznicy, wrogowie, poziom, na_kim);
	case 3:
		return trzesienie_ziemi(sojusznicy, wrogowie, poziom, na_kim);
	case 4:
		return leczenie(sojusznicy, wrogowie, poziom, na_kim);
	case 5:
		return tarcza(sojusznicy, wrogowie, poziom, na_kim);
	case 6:
		return kontrola(sojusznicy, wrogowie, poziom, na_kim);

	default:
		vector<string> wynik;
		wynik.push_back("blad");
		return wynik;
	}
}
//---------------------------------------------koniec MAG-----------------------------------------


//---------------------------------------------Wojownik--------------------------------------------------
Wojownik::Wojownik(string imie_) : postac(imie_)
{
	HP = 250;
	maxzdrowie = 250;
	wytrzymalosc = 100;
	maxwytrzymalosc = 100;
	odnawianie_wytrzymalosci = 20;
	aktualnie_uzywane["bron"] = ubior("miecz1", "bron", 20, 0, "brak", "Wojownik");
	zadane.fizyczne = aktualnie_uzywane["bron"].obrona;

	ataki[1].nazwa = "Potezne uderzenie";
	ataki[2].nazwa = "Obalenie";
	ataki[3].nazwa = "Mlyn";
	ataki[4].nazwa = "Podwojne uderzenie";
	ataki[5].nazwa = "Modlitwa";
	ataki[6].nazwa = "nieczysty cios";
}

//----------------umiejetnosci-----------------------------

vector<string> Wojownik::potezne_uderzenie(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> pomocniczy;
	if ((wytrzymalosc > poziom * 50) && (pozycja != 3))	//sprawdzenie czy mozna u¿yc
	{
		wytrzymalosc -= poziom * 50;//pobranie wytrzymalosci

		double mnoznik;		//mnoznik zadawanych obrazen
		if (poziom == 1)	mnoznik = 2;
		else if (poziom == 2) mnoznik = 3;
		else mnoznik = 4;

		pomocniczy.push_back(atak(wrogowie[na_kim], zadane*mnoznik)); //informacja zwrotna
	}
	else
	{
		pomocniczy.push_back("za ma³o wytrzyma³oœci");
		pomocniczy.push_back("lub jestes za daleko");
	}


	return pomocniczy;
}

vector<string> Wojownik::obalenie(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> pomocniczy;

	if ((wytrzymalosc > poziom * 50)&&(pozycja == 1))	//sprawdzenie czy mozna u¿yc
	{
		wytrzymalosc -= poziom * 50;

		int czas = 1;	//czas obalenia dla 1 i 2 poziomu
		if (poziom == 3) czas = 2;	//czas oalenia dla 3 poziomu
		wrogowie[na_kim]->dzialajace_efekty.push_back(efekt(0, "obalenie", czas));	//dodanie efektu obalenia


		pomocniczy.push_back(atak(wrogowie[na_kim], zadane*0.3*poziom) + " obalenie na " + to_string(czas) + " rundy");
	}
	else {
		pomocniczy.push_back("za ma³o wytrzyma³oœci");
		pomocniczy.push_back("lub jestes za daleko");
	}

	return pomocniczy;	//zadanie obrazen
}

vector<string> Wojownik::mlyn(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> wynik;
	if ((wytrzymalosc > poziom * 50) && (pozycja != 3))	//sprawdzenie czy mozna u¿yc
	{
		wytrzymalosc -= poziom * 50;

		//petla przechodzaca po wszystkich wrogach
		for (vector<postac*>::iterator pomocniczy = wrogowie.begin(); pomocniczy != wrogowie.end(); pomocniczy++)
		{//zadanie obrazeñ oraz dodanie komentarza o zadanych obrazeniach
			wynik.push_back(atak(*pomocniczy, zadane*0.5*poziom));
		}
	}
	else
	{
		wynik.push_back("za ma³o wytrzyma³oœci");
		wynik.push_back("lub jestes za daleko");
	}
		
	return wynik;
}

vector<string> Wojownik::podwojne_uderzenie(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> wynik;

	if ((wytrzymalosc > poziom * 50) && (pozycja != 3))	//sprawdzenie czy mozna u¿yc
	{
		wytrzymalosc -= poziom * 50;

		//wypisanie i zadanie obrazeñ podanemu wrogowii
		wynik.push_back(atak(wrogowie[na_kim], zadane*poziom));
		//wypisanie i zadanie obrazen losowemu wrogowi
		wynik.push_back(atak(wrogowie[rand() % wrogowie.size()], zadane*poziom));
	}
	else
	{
		wynik.push_back("za ma³o wytrzyma³oœci");
		wynik.push_back("lub jestes za daleko");
	}
	return wynik;
}

vector<string> Wojownik::modlitwa(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> wynik;
	if ((wytrzymalosc > poziom * 50) && (pozycja == 1))	//sprawdzenie czy mozna u¿yc
	{
		wytrzymalosc -= poziom * 50;

		//dodanie efektu dla wroga, jesli po 2 turach osoba ktora zadala efekt istnieje zadaj obrazenia
		efekt pomocniczy(int((zadane * 5 * poziom).laczny()), "modlitwa", 4);
		wrogowie[na_kim]->dzialajace_efekty.push_back(pomocniczy);

		//dzodanie efektu sojusznikowi, wylancza go z walki na 2 tury
		dzialajace_efekty.push_back(efekt(0, "obalenie", 2));

		//info o uzytej umiejetnosci

		wynik.push_back(imie + " uzyl modlitwy");
	}
	else
	{
		wynik.push_back("za ma³o wytrzyma³oœci");
		wynik.push_back("lub jestes za daleko");
	}
	return wynik;
}

vector<string> Wojownik::nieczysty_cios(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> wynik;

	if ((wytrzymalosc > poziom * 50) && (pozycja == 1))	//sprawdzenie czy mozna u¿yc
	{
		wytrzymalosc -= poziom * 50;
		wrogowie[na_kim]->zadane = (wrogowie[na_kim]->zadane)*(1 - (poziom * 5) / 100);
		wynik.push_back(imie + " oslabil " + wrogowie[na_kim]->imie + " o " + to_string(poziom * 5) + " %");
	}
	else
	{
		wynik.push_back("za ma³o wytrzyma³oœci");
		wynik.push_back("lub jestes za daleko");
	}


	return wynik;
}


//----------------koniec umiejetnosc----------------------

vector<string> Wojownik::uzyj_umiejetnosci(int numer_umiejetnosci, vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim = 0)
{

	switch (numer_umiejetnosci)
	{
	case 0:
		return atak_podstawowy(sojusznicy, wrogowie, poziom, na_kim);
	case 1:
		return potezne_uderzenie(sojusznicy, wrogowie, poziom, na_kim);
	case 2:
		return obalenie(sojusznicy, wrogowie, poziom, na_kim);
	case 3:
		return mlyn(sojusznicy, wrogowie, poziom, na_kim);
	case 4:
		return podwojne_uderzenie(sojusznicy, wrogowie, poziom, na_kim);
	case 5:
		return modlitwa(sojusznicy, wrogowie, poziom, na_kim);
	case 6:
		return nieczysty_cios(sojusznicy, wrogowie, poziom, na_kim);
	
	default:
		vector<string> wynik;
		wynik.push_back("blad");
		return wynik;
	}
}

//---------------------------------------------------koniec Wojownik-------------------------------------


//---------------------------------------------------Lucznik-------------------------------------------------
Lucznik::Lucznik(string imie_) : postac(imie_)
{
	HP = 200;
	maxzdrowie = 200;
	wytrzymalosc = 250;
	maxwytrzymalosc = 100;
	odnawianie_wytrzymalosci = 20;
	aktualnie_uzywane["bron"] = ubior("luk1", "bron", 15, 0, "brak", "Lucznik");
	zadane.fizyczne = aktualnie_uzywane["bron"].obrona;

	ataki[1].nazwa = "Strzala zapalajaca";
	ataki[2].nazwa = "Potepienie";
	ataki[3].nazwa = "Grad strzal";
	ataki[4].nazwa = "Strzala wybuchajca";
	ataki[5].nazwa = "Zwiad";
	ataki[6].nazwa = "Strzala w noge";

}

//----------------umiejetnosci-----------------------------

vector<string> Lucznik::strzala_zapalajaca(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> wynik;
	if (wytrzymalosc > poziom * 50)	//sprawdzenie czy mozna u¿yc
	{
		wytrzymalosc -= poziom * 50;

		obrazenia nowe = zadane;
		nowe = nowe*poziom;		//podwyzszenie obrazen w zaleznosci od poziomu
		nowe.dodaj("ogien", zadane.laczny() + 0.5*poziom);	//dodanie obrazen od podpalenia
		wynik.push_back(atak(wrogowie[na_kim], nowe));
		//zadanie obrazeñ
		wrogowie[na_kim]->dzialajace_efekty.push_back(efekt(zadane.laczny()*0.5*poziom, "podpalenie", (poziom == 3 ? 2 : 1)));	//dodanie efektu
	}
	else
		wynik.push_back("za ma³o wytrzyma³oœci");

	return wynik;
}
vector<string> Lucznik::potepienie(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> wynik;
	if (wytrzymalosc > poziom * 30)	//sprawdzenie czy mozna u¿yc
	{
		wytrzymalosc -= poziom * 50;

		HP -= HP*0.32*poziom;
		wynik.push_back(atak(wrogowie[na_kim], zadane * 3 * poziom));
	}
	else
		wynik.push_back("za ma³o wytrzyma³oœci");
	return wynik;
}
vector<string> Lucznik::grad_strzal(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> wynik;
	if (wytrzymalosc > poziom * 50)	//sprawdzenie czy mozna u¿yc
	{
		wytrzymalosc -= poziom * 50;

		obrazenia nowe;
		nowe.dodaj("powietrze", zadane.laczny()*0.5*poziom);	//dodanie obrazen od powietrza

		for (vector<postac*>::iterator pomocniczy = wrogowie.begin(); pomocniczy != wrogowie.end(); pomocniczy++)
		{//zadanie obrazeñ oraz dodanie komentarza o zadanych obrazeniach
			wynik.push_back(atak(*pomocniczy, nowe));
		}
	}
	else
		wynik.push_back("za ma³o wytrzyma³oœci");
	return wynik;
}
vector<string> Lucznik::strzala_wybuchowa(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> wynik;
	if (wytrzymalosc > poziom * 50)	//sprawdzenie czy mozna u¿yc
	{
		wytrzymalosc -= poziom * 50;

		//ustalenie sasiadow
		int sasiad1, sasiad2;
		sasiad1 = na_kim - 1;
		sasiad2 = na_kim + 1;

		//zadanie obrazen sasiadom
		if (sasiad1 >= 0)
			wynik.push_back(atak(wrogowie[sasiad1], zadane*0.5*poziom));
		if (sasiad2 < int(wrogowie.size()))
			wynik.push_back(atak(wrogowie[sasiad2], zadane*0.5*poziom));
		//zadanie obrazen wrogowi
		wynik.push_back(atak(wrogowie[na_kim], zadane*poziom));
	}
	else
		wynik.push_back("za ma³o wytrzyma³oœci");
	return wynik;
}
vector<string> Lucznik::zwiad(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> wynik;
	if (wytrzymalosc > poziom * 50)	//sprawdzenie czy mozna u¿yc
	{
		wytrzymalosc -= poziom * 50;

		wynik.push_back(wrogowie[na_kim]->imie);
		if (poziom == 1)
		{
			wynik.push_back("HP : " + to_string(int(wrogowie[na_kim]->HP)));
		}
		else
		{
			obrazenia nowe;
			if (poziom == 2)
			{
				nowe = wrogowie[na_kim]->zadane;
				wynik.push_back("ataki");
				wynik.push_back("fizyczne  :" + to_string(int(nowe.fizyczne)));
			}
			else
			{
				nowe = wrogowie[na_kim]->statystyka;
				wynik.push_back("odpornosc");
				wynik.push_back("obrona    :" + to_string(int(nowe.fizyczne)));
			}

			wynik.push_back("ogien     :" + to_string(int(nowe.ogien)));
			wynik.push_back("powietrze :" + to_string(int(nowe.powietrze)));
			wynik.push_back("ziemia    :" + to_string(int(nowe.ziemia)));
		}
	}
	else
		wynik.push_back("za ma³o wytrzyma³oœci");
	return wynik;
}
vector<string> Lucznik::strzal_w_noge(vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim)
{
	vector<string> wynik;
	if ((wytrzymalosc > poziom * 50)&&(pozycja ==1))	//sprawdzenie czy mozna u¿yc
	{
		wytrzymalosc -= poziom * 50;

		wynik.push_back(atak(wrogowie[na_kim], zadane*0.5));	//zadane obrazenia
		wynik.push_back(wrogowie[na_kim]->imie + "oslabienie");
		//oslabienie przeciwnika
		wrogowie[na_kim]->statystyka = wrogowie[na_kim]->statystyka*(1 - 0.2*poziom);

	}
	else
	{
		wynik.push_back("za ma³o wytrzyma³oœci");
		wynik.push_back("lub jestes za daleko");
	}
	return wynik;
}


//----------------koniec umiejetnosc----------------------

vector<string> Lucznik::uzyj_umiejetnosci(int numer_umiejetnosci, vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim = 0)
{

	switch (numer_umiejetnosci)
	{
	case 0:
		return atak_podstawowy(sojusznicy, wrogowie, poziom, na_kim);
	case 1:
		return strzala_zapalajaca(sojusznicy, wrogowie, poziom, na_kim);
	case 2:
		return potepienie(sojusznicy, wrogowie, poziom, na_kim);
	case 3:
		return grad_strzal(sojusznicy, wrogowie, poziom, na_kim);
	case 4:
		return strzala_wybuchowa(sojusznicy, wrogowie, poziom, na_kim);
	case 5:
		return zwiad(sojusznicy, wrogowie, poziom, na_kim);
	case 6:
		return strzal_w_noge(sojusznicy, wrogowie, poziom, na_kim);

	default:
		vector<string> wynik;
		wynik.push_back("blad");
		return wynik;
	}
}

//-----------------------------------------------koniec lucznik----------------------------------------------


//-------------------------------------------------kaplan------------------------------------------------
Kaplan::Kaplan(string imie_) : postac(imie_)
{
	
	HP = 200;
	maxzdrowie = 200;
	wytrzymalosc = 100;
	maxwytrzymalosc = 100;
	mana = 100;
	maxmana = 100;
	odnawianie_wytrzymalosci = 20;
	odnawianie_many = 20;
	aktualnie_uzywane["bron"] = ubior("laska1", "bron", 10, 0, "brak", "Mag");
	zadane.fizyczne = aktualnie_uzywane["bron"].obrona;

	ataki[1].nazwa = "Kula ognia";
	ataki[2].nazwa = "Potezne uderzenie";
	ataki[3].nazwa = "Obalenie";
	ataki[4].nazwa = "Morze ognia";
	ataki[5].nazwa = "Mlyn";
	ataki[6].nazwa = "Tarcza";
}

vector<string> Kaplan::uzyj_umiejetnosci(int numer_umiejetnosci, vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim = 0)
{

	switch (numer_umiejetnosci)
	{
	case 0:
		return atak_podstawowy(sojusznicy, wrogowie, poziom, na_kim);
	case 1:
		return kula_ognia(sojusznicy, wrogowie, poziom, na_kim);
	case 2:
		return potezne_uderzenie(sojusznicy, wrogowie, poziom, na_kim);
	case 3:
		return obalenie(sojusznicy, wrogowie, poziom, na_kim);
	case 4:
		return morze_ognia(sojusznicy, wrogowie, poziom, na_kim);
	case 5:
		return modlitwa(sojusznicy, wrogowie, poziom, na_kim);
	case 6:
		return tarcza(sojusznicy, wrogowie, poziom, na_kim);

	default:
		vector<string> wynik;
		wynik.push_back("blad");
		return wynik;
	}
}

//------------------------------------------------------koniec kaplan---------------------------------------------

//---------------------------------------------------lotr--------------------------------------------------------
Lotr::Lotr(string imie_) : postac(imie_)
{
	
	HP = 200;
	maxzdrowie = 200;
	wytrzymalosc = 100;
	maxwytrzymalosc = 100;
	odnawianie_wytrzymalosci = 20;
	aktualnie_uzywane["bron"] = ubior("luk1", "bron", 15, 0, "brak", "Lucznik");
	zadane.fizyczne = aktualnie_uzywane["bron"].obrona;

	ataki[1].nazwa = "Potezne uderzenie";
	ataki[2].nazwa = "Podwojne uderzenie";
	ataki[3].nazwa = "Strzala wybuchajaca";
	ataki[4].nazwa = "Grad strzal";
	ataki[5].nazwa = "Nieczysty cios";
	ataki[6].nazwa = "Zwiad";
}

vector<string> Lotr::uzyj_umiejetnosci(int numer_umiejetnosci, vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim = 0)
{

	switch (numer_umiejetnosci)
	{
	case 0:
		return atak_podstawowy(sojusznicy, wrogowie, poziom, na_kim);
	case 1:
		return potezne_uderzenie(sojusznicy, wrogowie, poziom, na_kim);
	case 2:
		return podwojne_uderzenie(sojusznicy, wrogowie, poziom, na_kim);
	case 3:
		return strzala_wybuchowa(sojusznicy, wrogowie, poziom, na_kim);
	case 4:
		return grad_strzal(sojusznicy, wrogowie, poziom, na_kim);
	case 5:
		return nieczysty_cios(sojusznicy, wrogowie, poziom, na_kim);
	case 6:
		return zwiad(sojusznicy, wrogowie, poziom, na_kim);

	default:
		vector<string> wynik;
		wynik.push_back("blad");
		return wynik;
	}
}


//-------------------------------------------koniec lotr------------------------------------------------------

//--------------------------------------------druid---------------------------------------------------
Druid::Druid(string imie_) : postac(imie_)
{
	
	HP = 180;
	maxzdrowie = 180;
	wytrzymalosc = 100;
	maxwytrzymalosc = 100;
	mana = 80;
	maxmana = 80;
	odnawianie_wytrzymalosci = 20;
	odnawianie_many = 20;
	aktualnie_uzywane["bron"] = ubior("laska1", "bron", 10, 0, "brak", "Mag");
	zadane.fizyczne = aktualnie_uzywane["bron"].obrona;

	ataki[1].nazwa = "Strzala zapalajaca";
	ataki[2].nazwa = "Strzala w noge";
	ataki[3].nazwa = "Trzesienie ziemi";
	ataki[4].nazwa = "Potepienie";
	ataki[5].nazwa = "Leczenie";
	ataki[6].nazwa = "Kontrola";
}

vector<string> Druid::uzyj_umiejetnosci(int numer_umiejetnosci, vector<postac*> sojusznicy, vector<postac*> wrogowie, double poziom, int na_kim = 0)
{

	switch (numer_umiejetnosci)
	{
	case 0:
		return atak_podstawowy(sojusznicy, wrogowie, poziom, na_kim);
	case 1:
		return strzala_zapalajaca(sojusznicy, wrogowie, poziom, na_kim);
	case 2:
		return strzal_w_noge(sojusznicy, wrogowie, poziom, na_kim);
	case 3:
		return trzesienie_ziemi(sojusznicy, wrogowie, poziom, na_kim);
	case 4:
		return potepienie(sojusznicy, wrogowie, poziom, na_kim);
	case 5:
		return leczenie(sojusznicy, wrogowie, poziom, na_kim);
	case 6:
		return kontrola(sojusznicy, wrogowie, poziom, na_kim);

	default:
		vector<string> wynik;
		wynik.push_back("blad");
		return wynik;
	}
}

//-------------------------------------------------koniec druid------------------------------------------------------