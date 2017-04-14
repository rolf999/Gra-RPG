#pragma once
#ifndef DRUZYNA_H
#define DRUZYNA_H
#include "przedmioty.h"
#include "postac.h"
#include<iostream>
#include<vector>
#include"obrazenia.h"


//funkcja dodaj¹ca wszystkie mo¿liwe przedmioty w grze 
void inicjalizacja(vector<ubior> & baza_przedmiotow, vector<eliksir> & baza_eliksirow);

//funkcja umo¿liwiaj¹ca u¿ycie danego eliksiru
string uzyj(int pozycja, postac * na_kim, vector<eliksir> & baza_eliksirow);




#endif