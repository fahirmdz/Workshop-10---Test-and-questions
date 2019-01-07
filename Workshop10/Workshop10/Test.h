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

	Test();
	Test(const char*);
	Test(const Test&);
	~Test();

	int getSlobodno()const;

	Test& operator=(const Test&);
	Test& operator+=(Pitanje&); //dodavanje novog Pitanja
	Pitanje* operator[](int);

	int izracunajOcjenu();

	int getOcjena()const;
	double getRezultat()const;
	double getOsvojeniBodovi()const;
	double getMaxBodova()const;
	char* getIndeks()const;


	void pokreniTest();
	void print();

};