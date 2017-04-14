#include<iostream>
#include"klasy.h"
#include"druzyna.h"
#include"postac.h"
#include"umiejetnosc.h"
#include"funkcje_ogolne.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <windows.h>
#include "menu.h"
#include "button.h"
#include "button_border.h"
#include "menu_nowa_gra.h"
#include "menu_postaci.h"
#include "menu_sklep.h"
#include "menu_walki.h"


using namespace std;

int main()
{
	srand(time(NULL));
//-------------------------------inicjalizacja gry---------------------------------------

	int poziom_druzyny = 0;		//poziom druzyny
	vector<ubior> baza_przedmiotow;	//baza przedmiotow
	vector<eliksir> baza_eliksirow;	//baza eliksirow
	inicjalizacja(baza_przedmiotow, baza_eliksirow);	//zapelnienie bazy eliksirow i przedmiotow
	vector<postac*> gracz;	//wektor z graczami
	//odczytanie danych z pliku
	bool czy_poprawnie_odczytano_z_pliku = odczyt_z_pliku(poziom_druzyny, gracz, baza_przedmiotow, baza_eliksirow);

	vector<postac*> przeciwnik; //wektor z przeciwnikami

//-----------------------------koniec inicjalizacji gry---------------------------------------
	
//-----------------------------tworzenie okna gry -------------------------------------------------
	sf::RenderWindow okno_glowne(sf::VideoMode(1000, 600), "GRA");	//utworzenie okna glownego
	
	//blok potrzeny do wypisania wspó³rzêdnych myszy
	sf::Text nowy;
	sf::Font czcionka;
	czcionka.loadFromFile("arial.ttf");
	nowy.setColor(sf::Color::Black);
	nowy.setCharacterSize(40);
	nowy.setPosition(840, 550);
	nowy.setFont(czcionka);
	string pozycja_myszy;
	sf::Vector2i pom;
	// koniec blok potrzeny do wypisania wspó³rzêdnych myszy
	
	//menu
	menu menu_glowne;
	nowa_gra menu_nowa_gra;
	menu_postaci menu_kontynuuj;
	sklep menu_sklep;
	walka menu_walki;

	while (okno_glowne.isOpen())	//petla glowna programu
	{
		pom = sf::Mouse::getPosition(okno_glowne);
		sf::Event event;	//zmienna przechowujaca zdarzenia
		while (okno_glowne.pollEvent(event))	//petla sprawdzajaca zdarzenia
		{

			if (event.type == sf::Event::Closed)	//zdarzenie zamkniecia okna
				okno_glowne.close();


			if (event.type == sf::Event::MouseMoved)	//zdarzenie ruszenia myszka
			{
				if (menu_glowne.poprzednio_zaznaczony != NULL)	//usuniecie zaznaczenia poprzednio najechanego przycisku
					menu_glowne.poprzednio_zaznaczony->text.setColor(sf::Color::Black);

				button * najechany_przycisk = znajdz_przycisk<button>(pom.x, pom.y,menu_glowne.przycisk);	//pobranie najechanego przycisku
				menu_glowne.poprzednio_zaznaczony = najechany_przycisk;	//zaisanie aktualnie zaznaczonego przycisku

				if (najechany_przycisk != NULL)	//jesli przycisk nie zostal by najechany
				{
					//sprawdza czy najechany przycisk nie oznacza "kontynuuj", i czy mozna go podswietlic
					if (najechany_przycisk->typ2 == 1 && czy_poprawnie_odczytano_z_pliku != true)
						break;

					najechany_przycisk->text.setColor(sf::Color::Red);	//zmiana koloru czcionki najechanego przycisku
					
					
				}
			}

			if (event.type == sf::Event::MouseButtonPressed)	//wcisniecie przycisku myszy
			{
				button * najechany_przycisk = znajdz_przycisk<button>(pom.x, pom.y, menu_glowne.przycisk);	//pobranie najechanego przycisku

				if (najechany_przycisk != NULL)	//jesli przycisk nie zostal by wcisniety
				{//akcja po wcisnieciu

					//w przypadku wcisniecia kontynuuj i braku zapisu gry
					if (najechany_przycisk->typ2 == 1 && czy_poprawnie_odczytano_z_pliku != true)
						break;

					
					bool czy_wyjsc = false;		//zmienna umozliwiajaca powrot do menu glownego


					

					switch (najechany_przycisk->typ2)
					{
					case 0: {
						//----------------------------Nowa gra---------------------------------------------------
						
						bool czy_zakonczono_tworzenie_druzyny = false;

						while (true)	//petla g³ówna nowej gry
						{
							while (okno_glowne.pollEvent(event))	//wychwycenie zdarzen
							{
								pom = sf::Mouse::getPosition(okno_glowne);
								if (event.type == sf::Event::Closed)	//zdarzenie zamkniecia okna
									czy_wyjsc = true;


								if (event.type == sf::Event::TextEntered)	//wprowadzenie imienia
								{
									string pom = menu_nowa_gra.przycisk[15]->text.getString();
									if ((event.text.unicode >= 'A' && event.text.unicode <= 'Z') || (event.text.unicode >= 'a' && event.text.unicode <= 'z') && pom.size() < 9)
										menu_nowa_gra.przycisk[15]->text.setString(menu_nowa_gra.przycisk[15]->text.getString() + event.text.unicode);

									if (event.text.unicode == 8 && pom.size() > 0) //formatowanie imienia
									{
										pom.pop_back();
										menu_nowa_gra.przycisk[15]->text.setString(pom);
									}
								}

								if (event.type == sf::Event::MouseMoved)	//zdarzenie ruszenia myszka
								{
									if (menu_nowa_gra.poprzednio_zaznaczony != NULL)	//usuniecie zaznaczenia poprzednio najechanego przycisku
										menu_nowa_gra.poprzednio_zaznaczony->ramka.setFillColor(sf::Color::Green);

									button_border * najechany_przycisk = znajdz_przycisk<button_border>(pom.x, pom.y, menu_nowa_gra.przycisk);	//pobranie najechanego przycisku
									menu_nowa_gra.poprzednio_zaznaczony = najechany_przycisk;	//zaisanie aktualnie zaznaczonego przycisku

									if (najechany_przycisk != NULL && najechany_przycisk->typ != typ_przycisku::pole_tekstowe)	//jesli przycisk nie zostal by najechany, badz wybrano pole tekstowe
									{
										najechany_przycisk->ramka.setFillColor(sf::Color::Red);
									}
								}

								if (event.type == sf::Event::MouseButtonPressed)	//wcisniecie przycisku myszy
								{
									button_border * najechany_przycisk = znajdz_przycisk<button_border>(pom.x, pom.y, menu_nowa_gra.przycisk);	//pobranie najechanego przycisku
									if (najechany_przycisk != NULL)	//jesli przycisk nie zostal by wcisniety
									{//akcja po wcisnieciu

										switch (najechany_przycisk->typ)
										{
										case typ_przycisku::slot:
											menu_nowa_gra.przycisk[menu_nowa_gra.ktora_postac + 1]->text.setColor(sf::Color::Black);	//odklikniecie poprzedniego przycisku postaci
											menu_nowa_gra.przycisk[menu_nowa_gra.ktora_postac + 1]->text.setString(menu_nowa_gra.przycisk[15]->text.getString());	//wpisanie imienia w slot
											menu_nowa_gra.imiona[menu_nowa_gra.ktora_postac] = menu_nowa_gra.przycisk[15]->text.getString(); //zapisanie imienia poprzedniej postaci
											menu_nowa_gra.klasy[menu_nowa_gra.ktora_postac] = menu_nowa_gra.ktora_klasa; //zapisanie klasy poprzedniej postaci
											menu_nowa_gra.przycisk[menu_nowa_gra.ktora_klasa + 8]->text.setColor(sf::Color::Black);
											menu_nowa_gra.ktora_postac = najechany_przycisk->typ2;	//zaznaczenie aktualnego przycisku
											menu_nowa_gra.ktora_klasa = menu_nowa_gra.klasy[menu_nowa_gra.ktora_postac]; //wczytanie klasy aktualnie zaznaczonej osoby
											najechany_przycisk->text.setColor(sf::Color::Blue);	//nacisniecie oktualnego przycisku, zmiana koloru
											menu_nowa_gra.przycisk[15]->text.setString(menu_nowa_gra.imiona[menu_nowa_gra.ktora_postac]);	//wczytanie do pola tekstowego imienia postaci
											menu_nowa_gra.przycisk[menu_nowa_gra.ktora_klasa + 8]->text.setColor(sf::Color::Blue);	//zaznaczenie altualnej klasy


											break;
										case typ_przycisku::nawigacja:
											if (najechany_przycisk->typ2)
											{//wroc
												czy_wyjsc = true;
											}
											else
											{//zatwierdz
												czysc_postac(gracz);
												//tworzenie druzyny
												for (int i = 0; i < 5; i++)
													switch (menu_nowa_gra.klasy[i])
													{
													case 0:
														gracz.push_back(new Mag(menu_nowa_gra.imiona[i]));
														break;
													case 1:
														gracz.push_back(new Wojownik(menu_nowa_gra.imiona[i]));
														break;
													case 2:
														gracz.push_back(new Lucznik(menu_nowa_gra.imiona[i]));
														break;
													case 3:
														gracz.push_back(new Kaplan(menu_nowa_gra.imiona[i]));
														break;
													case 4:
														gracz.push_back(new Lotr(menu_nowa_gra.imiona[i]));
														break;
													case 5:
														gracz.push_back(new Druid(menu_nowa_gra.imiona[i]));
														break;
													default:
														break;
													}
												czy_zakonczono_tworzenie_druzyny = true;
											}

											break;
										case typ_przycisku::osoba:	//wybor klasy
											menu_nowa_gra.przycisk[menu_nowa_gra.ktora_klasa + 8]->text.setColor(sf::Color::Black);	//odklikniecie poprzedniego przycisku
											najechany_przycisk->text.setColor(sf::Color::Blue);	//nacisniecie aktualnego przycisku, zmiana koloru
											menu_nowa_gra.ktora_klasa = najechany_przycisk->typ2;	//wczytanie klasy postaci
											break;
										default:
											break;
										}
									}
								}
							}
							if (czy_wyjsc) break;
							if (czy_zakonczono_tworzenie_druzyny) break;
							okno_glowne.clear(sf::Color::White);	//czyszczenie okna na bialo



							menu_nowa_gra.draw(okno_glowne);
							okno_glowne.display();	//wyswietlaniae okna
						}
						break;
					}
//----------------------------koniec Nowej gry----------------------------------------------
					case 1: {
						//----------------------------Kontynuuj---------------------------------------------------
						if (czy_wyjsc) break;	//w przypadku checi wyjsca do menu glownego
						int lista_ekwipunku = 0;

						
						pom = sf::Mouse::getPosition(okno_glowne);
						while (true)	//petla g³ówna menu kontynuuj
						{
							while (okno_glowne.pollEvent(event))	//wychwycenie zdarzen
							{
								pom = sf::Mouse::getPosition(okno_glowne);
								if (event.type == sf::Event::Closed)	//zdarzenie zamkniecia okna
									czy_wyjsc = true;

								if (event.type == sf::Event::MouseWheelMoved)	//poruszenie ku³ka myszy
								{
									if (event.mouseWheel.delta < 0)
									{
										int pomocnicza = gracz[menu_kontynuuj.ktora_postac]->ekwipunek.size() - 7;	
										if(lista_ekwipunku < pomocnicza)	//czy nie wychodzi po za zakres ekwipunku do wyœwietlenia
											lista_ekwipunku++;
									}
									else
									{
										if(lista_ekwipunku > 0)
											lista_ekwipunku--;
									}
								}

								if (event.type == sf::Event::MouseMoved)	//zdarzenie ruszenia myszka
								{
									if (menu_kontynuuj.poprzednio_zaznaczony != NULL)	//usuniecie zaznaczenia poprzednio najechanego przycisku
										menu_kontynuuj.poprzednio_zaznaczony->ramka.setFillColor(sf::Color::Green);

									button_border * najechany_przycisk = znajdz_przycisk<button_border>(pom.x, pom.y, menu_kontynuuj.przycisk);	//pobranie najechanego przycisku
									menu_kontynuuj.poprzednio_zaznaczony = najechany_przycisk;	//zaisanie aktualnie zaznaczonego przycisku

									if (najechany_przycisk != NULL )	//jesli przycisk nie zostal by najechany
									{
										najechany_przycisk->ramka.setFillColor(sf::Color::Red);
									}
								}

								if (event.type == sf::Event::MouseButtonPressed)	//wcisniecie przycisku myszy
								{
									button_border * najechany_przycisk = znajdz_przycisk<button_border>(pom.x, pom.y, menu_kontynuuj.przycisk);	//pobranie najechanego przycisku
									if (najechany_przycisk != NULL)	//jesli przycisk nie zostal by wcisniety
									{//akcja po wcisnieciu
										switch (najechany_przycisk->typ)
										{
										case typ_przycisku::lista:
										{
											menu_kontynuuj.numer_z_ekwipunku = najechany_przycisk->typ2;
											break;
										}
										case typ_przycisku::zarzadzanie_ekwipunkiem:
										{
											if (gracz[menu_kontynuuj.ktora_postac]->ekwipunek.size() != 0)	//sprawdzenie czy ekwipunek nie jest pusty
											if (najechany_przycisk->typ2)
											{//usuñ
												gracz[menu_kontynuuj.ktora_postac]->usun(menu_kontynuuj.numer_z_ekwipunku);
												if(lista_ekwipunku>0)
													lista_ekwipunku--;
												
											}
											else
											{//za³ó¿
												gracz[menu_kontynuuj.ktora_postac]->zaluz(menu_kontynuuj.numer_z_ekwipunku);
											}
											break;
										}
										case typ_przycisku::osoba:
										{
											menu_kontynuuj.przycisk[menu_kontynuuj.ktora_postac + 1]->text.setColor(sf::Color::Black);//odznaczenie poprzedniego przycisku
											menu_kontynuuj.ktora_postac = najechany_przycisk->typ2;
											menu_kontynuuj.przycisk[menu_kontynuuj.ktora_postac + 1]->text.setColor(sf::Color::Blue);//zaznaczenie wybranego przycisku
											menu_kontynuuj.numer_z_ekwipunku = 0;
											menu_kontynuuj.poprzednio_zaznaczony = NULL;
											break;
										}
										case typ_przycisku::nawigacja:
										{
											switch (najechany_przycisk->typ2)
											{
											case 1:	//wruc
												czy_wyjsc = true;
												break;
											case 2: //sklep
											{
												//--------------------------------------menu_sklep-------------------------
												bool czy_skonczono_zakupy = false;
												int lista_sklep = 0;
												menu_sklep.ktora_postac = menu_kontynuuj.ktora_postac;
												while (true)	//petla g³ówna menu sklep
												{
													while (okno_glowne.pollEvent(event))	//wychwycenie zdarzen
													{
														pom = sf::Mouse::getPosition(okno_glowne);
														if (event.type == sf::Event::Closed)	//zdarzenie zamkniecia okna
															czy_skonczono_zakupy = true;

														if (event.type == sf::Event::MouseWheelMoved)	//poruszenie ku³ka myszy
														{
															if (event.mouseWheel.delta < 0)
															{
																int pomocnicza = baza_przedmiotow.size() - 13;
																if (lista_sklep < pomocnicza)	//czy nie wychodzi po za zakres ekwipunku do wyœwietlenia
																	lista_sklep++;
															}
															else
															{
																if (lista_sklep > 0)
																	lista_sklep--;
															}
														}

														if (event.type == sf::Event::MouseMoved)	//zdarzenie ruszenia myszka
														{
															if (menu_sklep.poprzednio_zaznaczony != NULL)	//usuniecie zaznaczenia poprzednio najechanego przycisku
																menu_sklep.poprzednio_zaznaczony->ramka.setFillColor(sf::Color::Green);

															button_border * najechany_przycisk = znajdz_przycisk<button_border>(pom.x, pom.y, menu_sklep.przycisk);	//pobranie najechanego przycisku
															menu_sklep.poprzednio_zaznaczony = najechany_przycisk;	//zaisanie aktualnie zaznaczonego przycisku

															if (najechany_przycisk != NULL)	//jesli przycisk nie zostal by najechany
															{
																najechany_przycisk->ramka.setFillColor(sf::Color::Red);
															}
														}


														if (event.type == sf::Event::MouseButtonPressed)	//wcisniecie przycisku myszy
														{
															button_border * najechany_przycisk = znajdz_przycisk<button_border>(pom.x, pom.y, menu_sklep.przycisk);	//pobranie najechanego przycisku
															if (najechany_przycisk != NULL)	//jesli przycisk nie zostal by wcisniety
															{//akcja po wcisnieciu

																if (najechany_przycisk->typ == typ_przycisku::nawigacja)
																{
																	if (najechany_przycisk->typ2)
																	{//kup
																		if (menu_sklep.czy_mozna_kupic)
																		{	//pobranie zaplaty
																			gracz[menu_sklep.ktora_postac]->doswiadczenie -= menu_sklep.koszt;

																			switch (menu_sklep.typ_wcisnietego)
																			{
																			case typ_przycisku::lista:
																				gracz[menu_sklep.ktora_postac]->ekwipunek.push_back(baza_przedmiotow[menu_sklep.wcisniety]);
																				break;
																			case typ_przycisku::mikstura:
																				if (menu_sklep.wcisniety < 14)
																				{
																					baza_eliksirow[menu_sklep.wcisniety].ilosc++;
																				}
																				else
																				{
																					switch (menu_sklep.wcisniety)
																					{
																					case 14:
																						gracz[menu_sklep.ktora_postac]->maxzdrowie += 100;
																						break;
																					case 15:
																						gracz[menu_sklep.ktora_postac]->maxmana += 100;
																						break;
																					case 16:
																						gracz[menu_sklep.ktora_postac]->maxwytrzymalosc += 100;
																						break;
																					case 17:
																						gracz[menu_sklep.ktora_postac]->odnawianie_many += 20;
																						break;
																					case 18:
																						gracz[menu_sklep.ktora_postac]->odnawianie_wytrzymalosci += 20;
																						break;
																					default:
																						break;
																					}
																				}
																				
																				break;
																			case typ_przycisku::umiejet:
																				gracz[menu_sklep.ktora_postac]->ataki[menu_sklep.wcisniety].podnies_poziom();
																				break;
																			default:
																				break;
																			}
																		}
																	}
																	else
																	{//wroc
																		czy_skonczono_zakupy = true;
																	}
																}
																else
																{
																	menu_sklep.typ_wcisnietego = najechany_przycisk->typ;
																	menu_sklep.wcisniety = najechany_przycisk->typ2;
																}
															}
														}
														menu_sklep.zaladuj_postac(gracz[menu_kontynuuj.ktora_postac], lista_sklep, gracz,baza_przedmiotow,baza_eliksirow);
													}

													if (czy_skonczono_zakupy) break;
													okno_glowne.clear(sf::Color::White);	//czyszczenie okna na bialo

													okno_glowne.draw(nowy);
													menu_sklep.draw(okno_glowne);
													okno_glowne.display();	//wyswietlaniae okna
												}

												break;
												//--------------------------------------koniec menu sklep-------------------
											}
											case 0:	//walka
											{
												//---------------------------------------menu walka---------------------------
												//inicjalizacja walki
												bool czy_zakonczona_walke = false;
												vector<postac*> druzyna = gracz;	//skopiowanie wektora z graczami
												for (int i = 0; i < druzyna.size(); i++)
												{	//przywrocenie do pelna zdrowia many wytrzymalosci
													druzyna[i]->HP = druzyna[i]->maxzdrowie;
													druzyna[i]->mana = druzyna[i]->maxmana;
													druzyna[i]->wytrzymalosc = druzyna[i]->maxwytrzymalosc;
													druzyna[i]->czy_atakowac = true;
												}

												//tworzenie wrogow
												vector<postac*> wrogowie;	

												int ilosc_przeciwnikow = (rand() % 6) + 1;	//ilosc wrogow
												for (int i = 0; i < ilosc_przeciwnikow; i++)
												{
													int num_klasy = rand() % 6;
													switch (num_klasy)
													{
													case 0:
														wrogowie.push_back(new Mag("wrog " + to_string(i)));
														break;
													case 1:
														wrogowie.push_back(new Wojownik("wrog " + to_string(i)));
														break;
													case 2:
														wrogowie.push_back(new Lucznik("wrog " + to_string(i)));
														break;
													case 3:
														wrogowie.push_back(new Kaplan("wrog " + to_string(i)));
														break;
													case 4:
														wrogowie.push_back(new Lotr("wrog " + to_string(i)));
														break;
													case 5:
														wrogowie.push_back(new Druid("wrog " + to_string(i)));
														break;
													default:
														break;
													}
													wrogowie[wrogowie.size() - 1]->pozycja = 1;	//ustawienie wroga na 1 pozycji
													wrogowie[wrogowie.size() - 1]->mana = 1000;
													wrogowie[wrogowie.size() - 1]->wytrzymalosc = 1000;
												}

												while (true)	//petla g³ówna menu walki
												{
													while (okno_glowne.pollEvent(event))	//wychwycenie zdarzen
													{
														pom = sf::Mouse::getPosition(okno_glowne);
														if (event.type == sf::Event::Closed)	//zdarzenie zamkniecia okna
															czy_zakonczona_walke = true;

														if (event.type == sf::Event::MouseMoved)	//zdarzenie ruszenia myszka
														{
															if (menu_walki.poprzednio_zaznaczony != NULL)	//usuniecie zaznaczenia poprzednio najechanego przycisku
																menu_walki.poprzednio_zaznaczony->ramka.setFillColor(sf::Color::Green);

															button_border * najechany_przycisk = znajdz_przycisk<button_border>(pom.x, pom.y, menu_walki.przycisk);	//pobranie najechanego przycisku
															menu_walki.poprzednio_zaznaczony = najechany_przycisk;	//zaisanie aktualnie zaznaczonego przycisku

															if (najechany_przycisk != NULL)	//jesli przycisk nie zostal by najechany
															{
																najechany_przycisk->ramka.setFillColor(sf::Color::Red);
															}
														}

														if (event.type == sf::Event::MouseButtonPressed)	//wcisniecie przycisku myszy
														{
															button_border * najechany_przycisk = znajdz_przycisk<button_border>(pom.x, pom.y, menu_walki.przycisk);	//pobranie najechanego przycisku
															if (najechany_przycisk != NULL)	//jesli przycisk nie zostal by wcisniety
															{//akcja po wcisnieciu

																switch (najechany_przycisk->typ)
																{
																case typ_przycisku::mikstura:
																	menu_walki.przycisk[6 + menu_walki.ktory_elkisir]->text.setColor(sf::Color::Black);
																	menu_walki.ktory_elkisir = najechany_przycisk->typ2;
																	menu_walki.przycisk[6 + menu_walki.ktory_elkisir]->text.setColor(sf::Color::Blue);
																	break;
																case typ_przycisku::nawigacja:
																	if (najechany_przycisk->typ2)
																	{//wyjdz
																		czy_zakonczona_walke = true;
																	}
																	else
																	{//uzyj
																		if (druzyna[menu_walki.ktory_gracz]->czy_atakowac)	//sprawdza czy postac jeszcze moze wykonac ruch
																		{
																			uzyj(menu_walki.ktory_elkisir, druzyna[menu_walki.ktory_gracz], baza_eliksirow);
																			druzyna[menu_walki.ktory_gracz]->czy_atakowac = false;
																		}

																	}
																	break;
																case typ_przycisku::umiejet:
																	menu_walki.ktora_umiejetnosc = najechany_przycisk->typ2;
																	for (int i = 1; i <= 3; i++)	//zablokowanie poziomu umiejetnosci do kturych nie masz prawa
																	{
																		if (druzyna[menu_walki.ktory_gracz]->ataki[menu_walki.ktora_umiejetnosc].poziom >= i)
																			menu_walki.przycisk[31 + i]->text.setString(to_string(i) + " ");
																		else
																			menu_walki.przycisk[31 + i]->text.setString("");
																	}
																	break;
																case typ_przycisku::przycisk_pozyc:
																{
																	double * pozycja_p = &(druzyna[menu_walki.ktory_gracz]->pozycja);	//pobranie adresu komurki pozycji 
																	menu_walki.przycisk[62+ menu_walki.ktory_gracz*3 + *pozycja_p]->text.setString("");	//usuniecie zaznaczenia z poprzedniej pozycji
																	*pozycja_p = najechany_przycisk->typ2;
																	menu_walki.przycisk[62 + menu_walki.ktory_gracz * 3 + *pozycja_p]->text.setString("x");	//dodanie zaznaczenia na nowej pozycji
																	druzyna[menu_walki.ktory_gracz]->czy_atakowac = false;


																	break;
																}
																case typ_przycisku::wrog:
																	menu_walki.przycisk[75 + menu_walki.ktory_wrog]->text.setColor(sf::Color::Black);
																	menu_walki.ktory_wrog = najechany_przycisk->typ2;
																	menu_walki.przycisk[75 + menu_walki.ktory_wrog]->text.setColor(sf::Color::Blue);
																	break;
																case typ_przycisku::osoba:
																	//odznaczenie postaci poprzednio wybranej
																	menu_walki.przycisk[47 + menu_walki.ktory_gracz]->text.setColor(sf::Color::Black);
																	menu_walki.ktory_gracz = najechany_przycisk->typ2;
																	menu_walki.przycisk[47 + menu_walki.ktory_gracz]->text.setColor(sf::Color::Blue);

																	for (int i = 1; i <= 3; i++)	//zablokowanie poziomu umiejetnosci do kturych nie masz prawa
																	{
																		if (druzyna[menu_walki.ktory_gracz]->ataki[menu_walki.ktora_umiejetnosc].poziom >= i)
																			menu_walki.przycisk[31 + i]->text.setString(to_string(i) + " ");
																		else
																			menu_walki.przycisk[31 + i]->text.setString("");
																	}
																	break;
																case typ_przycisku::atakuj:
																	if (druzyna[menu_walki.ktory_gracz]->czy_atakowac)	//sprawdza czy postac jeszcze moze wykonac ruch
																	{
																		vector<string>  wynik = druzyna[menu_walki.ktory_gracz]->uzyj_umiejetnosci(menu_walki.ktora_umiejetnosc, druzyna, wrogowie, najechany_przycisk->typ2, menu_walki.ktory_wrog);
																		druzyna[menu_walki.ktory_gracz]->czy_atakowac = false;
																		string wynik_p;
																		for (vector<string>::iterator pom = wynik.begin(); pom != wynik.end(); pom++)
																		{
																			wynik_p += *pom + "\n";
																		}
																		menu_walki.przycisk[81]->text.setString(wynik_p);
																	}
																	break;
																default:
																	break;
																}


															}
														}
														menu_walki.zaladuj_postac(druzyna, wrogowie,  baza_przedmiotow, baza_eliksirow);
													}

													if (koniec_tury(druzyna))
													{
														//atak przeciwnika
														string wynik_p;
														vector<string> wynik;
														if (druzyna.size() != 0)	//atakuj jesli jest kogo atakowac
															for (vector<postac*>::iterator pom = wrogowie.begin(); pom != wrogowie.end(); pom++)
															{
																if ((*pom)->czy_obalony != true && (*pom)->czy_atakowac)
																{
																	wynik = (*pom)->uzyj_umiejetnosci(rand() % 7, wrogowie, druzyna, 1, rand() % druzyna.size());	//atak
																	(*pom)->mana += 50;
																	(*pom)->wytrzymalosc += 50;
																	for (vector<string>::iterator pom = wynik.begin(); pom != wynik.end(); pom++)	//zapisanie do stringa zadanych obrazen
																	{
																		wynik_p += *pom + "\n";
																	}
																	menu_walki.przycisk[81]->text.setString(wynik_p);
																	(*pom)->czy_atakowac = false;
																	Sleep(1000);
																	wynik.clear();
																	break;

																}




														}
													}
													//aktywacja druzyn i sprawdzenie efektow
													if (koniec_tury(wrogowie))
													{
														spr_efekty(druzyna);
														aktywuj_postacie(druzyna);
														spr_efekty(wrogowie);
														aktywuj_postacie(wrogowie);
													}

													if (wrogowie.size() == 0 || druzyna.size() == 0)
													{
														czy_zakonczona_walke = true;
														if (druzyna.size() != 0)
															nagroda(druzyna);
													}


													if (czy_zakonczona_walke) break;
													okno_glowne.clear(sf::Color::White);	//czyszczenie okna na bialo

													okno_glowne.draw(nowy);
													menu_walki.draw(okno_glowne);
													okno_glowne.display();	//wyswietlaniae okna
												}
												//czyszczenie po walce
												czysc_postac(wrogowie);
												druzyna.clear();	//czyszcze liste z kopiami
												break;
												//-------------------------------------koniec menu walka--------------------------
											}
											default:
												break;
											}
											break;
										}
										default:

											break;
										}
									}
								}

								menu_kontynuuj.zaladuj_postac(gracz[menu_kontynuuj.ktora_postac],lista_ekwipunku,gracz);
							}
							if (czy_wyjsc) break;
							okno_glowne.clear(sf::Color::White);	//czyszczenie okna na bialo
							
							okno_glowne.draw(nowy);
							menu_kontynuuj.draw(okno_glowne);
							okno_glowne.display();	//wyswietlaniae okna
						}

						//----------------------------koniec Kontynuuj----------------------------------------------
						break;
					}
					case 2: {
						//----------------------------Wyjdz---------------------------------------------------
												//czyszczenie
						zapis_do_pliku(0, gracz, baza_eliksirow);//zapisanie stanu gry
						okno_glowne.close();//zamkniecie okna

//----------------------------koniec Wyjdz----------------------------------------------	
						break;
					}
					default:
						break;
					}
				}
			}
		}

		okno_glowne.clear(sf::Color::White);	//czyszczenie okna na bialo

		//wyswietl menu g³ówne
		
		menu_glowne.draw(okno_glowne);
		

		okno_glowne.draw(nowy);

		okno_glowne.display();	//wyswietlaniae okna
	} //while
	
	
		
	czysc_menu<menu,button>(menu_glowne);	//czyszczenie menu
	czysc_menu<nowa_gra,button_border>(menu_nowa_gra);
	czysc_menu<menu_postaci, button_border>(menu_kontynuuj);
	czysc_menu<sklep, button_border>(menu_sklep);
	baza_eliksirow.clear();	//czyszczenie bazy eleksirów
	baza_przedmiotow.clear();	//czyszczenie bazy przedmiotów
	czysc_postac(gracz);	//czyszczenie postaci

	return 0;
}