#pragma once
#include"Pitanje.h"

class Test {
	char _brojIndeksa[10]; //broj indeksa studenta za kojeg je formiran test 
	Pitanje* _pitanja[30]; // test studenta sadrži najviše 30 pitanja različitog tipa 
	double _maksimalnoBodova;
	double _osvojenoBodova;
	double _rezultat; //izražen u procentima
	int ocjena;

public:
	//Omogućiti formiranje testa sa različitim tipom pitanja, te dodati funkcije za unos, provjeru tačnih odgovora i ocjenu studenta.
	//Po potrebi dopuniti i prethodne klase novim atributima/funkcijama. 

};