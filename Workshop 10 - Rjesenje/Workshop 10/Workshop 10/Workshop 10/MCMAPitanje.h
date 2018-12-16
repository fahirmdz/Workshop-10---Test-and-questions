#pragma once
#include"List.h"

//Pitanje koje može imati više tacnih odgovora. Student bira ponudene opcije. 
class MCMAPitanje : public Pitanje {
protected:
	List<char*, bool> _odgovori; //ponudeni odgovori sa oznakama tacnih odgovora  
	int* _oznaceniOdgovoriStudenta; //cuvaju se redni brojevi (npr. 1 - 3 - 5) ponudenih odgovora koje je odabrao student
	int _brojOznacenihOdgovora;
	bool _valid; //pitanje MCMA vrste je validno samo ako postoji >=2 tacnih odgovora

public:
	//Konstruktor i destruktor  
	MCMAPitanje();
	MCMAPitanje(int, const char*, const char*, double);
	MCMAPitanje(const MCMAPitanje&);
	MCMAPitanje(MCMAPitanje&&);
	virtual ~MCMAPitanje();

	virtual double brojOsvojenihBodova();
	virtual bool odgovaranje(const char*, int);

	virtual int brojTacnih();
 //Funkciju za dodavanje odgovora u listu koja treba da osigura da su najmanje 2 (od max) odgovora oznacena kao tacna. 
 // Dok se ne dodaju svi predvideni odgovori pitanje ne treba biti upotrebljivo ukoliko prethodni uslov nije ispunjen (ne prikazivati 
 //pitanja na ispisu). 
 //Napomena: Podatke o odgovorima cuvati u zasebnoj memoriji i istu dealocirati unutar same klase. 
   void dodavanjeOdgovora(const char*,bool);

 //Funkciju za uklanjanje odgovora na osnovu rednog broja u listi. Ukoliko se uklanja odgovor koji je oznacen kao tacan i 
 //pri tome u listi ostaje samo još jedan odgovor oznacen kao tacan, pitanje postaje neupotrebljivo dok se ne doda još jedan 
 //tacan odgovor. 
	MCMAPitanje& operator-=(int);

 //Funkciju za promjenu teksta odgovora na odredenom rednom broju. 
	virtual MCMAPitanje& operator()(int, const char*);

	virtual char* operator[](int); //tekst odgovora iz liste
	virtual bool operator()(int); //tacan/netacan odgovor iz liste
	virtual bool postaviPitanje();
	bool valid();
	virtual void print();
};