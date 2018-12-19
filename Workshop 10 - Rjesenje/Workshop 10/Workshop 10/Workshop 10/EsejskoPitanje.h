#pragma once

#include"Pitanje.h"

class EsejskoPitanje :virtual public Pitanje {
protected:
	char* _tacanOdgovor;
	char* _odgovorStudenta;
public:
	EsejskoPitanje();
	EsejskoPitanje(int, const char*, const char*, double, const char*);
	EsejskoPitanje(const EsejskoPitanje&);
	EsejskoPitanje(EsejskoPitanje&&);
	virtual ~EsejskoPitanje();


	virtual double brojOsvojenihBodova();
	virtual bool odgovaranje(const char*, int);

	//GET METHODS
	char* getOdgStudenta()const;
	char* getTacanodg()const;

	EsejskoPitanje& operator=(EsejskoPitanje&);

	virtual bool postaviPitanje();
	//SET METHODS
	void setTacanOdg(const char*);
	void setOdgovorStudenta(const char*);
	bool valid()const;
	
	virtual void print();
};