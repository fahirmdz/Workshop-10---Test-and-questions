#pragma once
#include"MCMAPitanje.h"
#include"EsejskoPitanje.h"

//Pojam je tip pitanja kod kojeg se definiše pojam zadat tekstom pitanja. Definicija/Opis pojma se tretira kao
//esejski dio pitanja, dok se karakteristike tog pojma postavljaju kroz MCMA tip pitanja.

class Pojam : public EsejskoPitanje, public MCMAPitanje {
	bool _slozen; //pojam moze biti prost ili slozen 

public:
	Pojam();
	Pojam(bool, int, const char*, double, const char*, const char*);
	Pojam(const Pojam&);
	virtual ~Pojam();

	Pojam& operator=(Pojam&);
	double brojOsvojenihBodova();
	bool postaviPitanje();
	bool odgovaranje(const char*, int)override final;


	//Jednostavno pitanje tipa Pojam nosi minimalno 3 boda, a ukoliko je rijec o složenom pojmu minimalno 5 bodova. 
	void print();
	//Dodati ostale potrebne funkcije za rad sa klasom. 
};