#pragma once
#include"MCMAPitanje.h"

//Pitanje koje može imati jedan tacan odgovor. Student bira jednu od ponudenih opcija.
class MCSAPitanje :public MCMAPitanje {
public:
	MCSAPitanje();
	MCSAPitanje(int, const char*, const char*, double);
	MCSAPitanje(const MCSAPitanje&);

	virtual ~MCSAPitanje();

	virtual double brojOsvojenihBodova();

	virtual void dodavanjeOdgovora(const char*, bool)final;//dodavanje mogucih odgovora na pitanje od strane profesora

	virtual bool odgovaranje(const char*, int)override final; //dodavanje odgovora studenta

	virtual bool postaviPitanje();

	MCSAPitanje& operator=(MCSAPitanje&);
	MCSAPitanje& operator-=(int); //uklanjanje odgovora

	virtual bool valid();

	virtual void print();

//Preklopljene verzije funkcija za dodavanje i uklanjanje odgovora koje dozvoljavaju da samo jedan odgovor bude oznacen kao tacan.  
//Svi prethodno navedeni uslovi trebaju biti ispunjeni, ali u ovom slucaju sa iskljucivo jednim tacnim odgovorom. 

};