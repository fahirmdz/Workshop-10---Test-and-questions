#pragma once

#include"Pitanje.h"

class EsejskoPitanje : public Pitanje {
	char* _tacanOdgovor;
	char* _odgovorStudenta;
public:
	EsejskoPitanje();
	EsejskoPitanje(int, const char*, const char*, double, const char*, const char*);
	EsejskoPitanje(const EsejskoPitanje&);
	EsejskoPitanje(EsejskoPitanje&&);
	virtual ~EsejskoPitanje();

	//GET METHODS
	virtual int getID()const;
	virtual char* getOdgStudenta()const;
	virtual char* getTacanodg()const;
	virtual void dodavanjeOdgovora(const char*,bool);
	//SET METHODS
	virtual void setTacanOdg(const char*);
	virtual void setOdgovorStudenta(const char*);
	bool valid()const;
	virtual void print();
};