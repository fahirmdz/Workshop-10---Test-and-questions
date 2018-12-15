#pragma once
#include"pch.h"


	EsejskoPitanje::EsejskoPitanje() :_tacanOdgovor(nullptr), _odgovorStudenta(nullptr) {}

	EsejskoPitanje::EsejskoPitanje(int id, const char* oblast, const char* tekst, double bodovi, const char* tacanOdg, const char* odgStudenta) :
		Pitanje(id, tekst, oblast, bodovi), _tacanOdgovor(AlocirajNizKaraktera(tacanOdg)),_odgovorStudenta(AlocirajNizKaraktera(odgStudenta)){}

	EsejskoPitanje::EsejskoPitanje(const EsejskoPitanje& ep):Pitanje(ep._id,ep._tekst,ep._oblast,ep._bodovi),_tacanOdgovor(AlocirajNizKaraktera(ep._tacanOdgovor)),
	_odgovorStudenta(AlocirajNizKaraktera(ep._odgovorStudenta)){}

	EsejskoPitanje::EsejskoPitanje(EsejskoPitanje&& ep) {
		_tacanOdgovor = ep._tacanOdgovor;
		_odgovorStudenta = ep._odgovorStudenta;
		ep._odgovorStudenta = ep._tacanOdgovor;
	}
	EsejskoPitanje::~EsejskoPitanje() {
		delete[] _tacanOdgovor;
		delete[] _odgovorStudenta;
		_tacanOdgovor = _odgovorStudenta = nullptr;
	}
	 void EsejskoPitanje::dodavanjeOdgovora(const char* odg,bool tacan=false) {
		 _tacanOdgovor = AlocirajNizKaraktera(odg);
	}
	int EsejskoPitanje::getID()const {return _id;}

	char* EsejskoPitanje::getOdgStudenta()const { return _odgovorStudenta; }
	char* EsejskoPitanje::getTacanodg()const { return _tacanOdgovor; }

	//SET METHODS
	 void EsejskoPitanje::setTacanOdg(const char* to) {
		 delete[] _tacanOdgovor;
		 _tacanOdgovor = AlocirajNizKaraktera(to);
	}
	void EsejskoPitanje::setOdgovorStudenta(const char* odgS) {
		delete[] _odgovorStudenta;
		_odgovorStudenta = AlocirajNizKaraktera(odgS);
	}

	bool EsejskoPitanje::valid()const { return _odgovorStudenta != nullptr && _tacanOdgovor != nullptr && _tekst != nullptr && _oblast != nullptr; }

   void EsejskoPitanje::print()
	{
	   if (!valid())
		   return;

		 Pitanje::print();
		 cout << "Tacan odgovor: " << _tacanOdgovor;
		 cout << "\nOdgovor studenta: " << _odgovorStudenta << endl;
		 return;
	}

