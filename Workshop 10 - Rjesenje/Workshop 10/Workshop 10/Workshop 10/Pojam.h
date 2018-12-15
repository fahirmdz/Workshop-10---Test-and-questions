#pragma once
#include"MCMAPitanje.h"
#include"EsejskoPitanje.h"
//Pojam je tip pitanja kod kojeg se definiše pojam zadat tekstom pitanja. Definicija/Opis pojma se tretira kao
//esejski dio pitanja, dok se karakteristike tog pojma postavljaju kroz MCMA tip pitanja.
class Pojam : public EsejskoPitanje, public MCMAPitanje {
	bool _slozen; //pojam moze biti prost ili slozen 

public:
	//Konstruktor 
//Jednostavno pitanje tipa Pojam nosi minimalno 3 boda, a ukoliko je rijec o složenom pojmu minimalno 5 bodova. 

//Dodati ostale potrebne funkcije za rad sa klasom. 
};