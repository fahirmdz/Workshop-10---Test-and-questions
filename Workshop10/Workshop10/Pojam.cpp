#include"pch.h"

Pojam::Pojam() :_slozen(false) {
}
Pojam::Pojam(bool valid, int id, const char* oblast, double bodovi, const char* esejsko, const char* pojam) : Pitanje(id, esejsko, oblast, bodovi)
, MCMAPitanje(), EsejskoPitanje(pojam), _slozen(valid) {
	if (_slozen && _bodovi < 5)
		_bodovi = 5;
	else if (!_slozen && _bodovi < 3)
		_bodovi = 3;
}

Pojam::Pojam(const Pojam& p) :Pitanje(p), MCMAPitanje(*const_cast<Pojam*>(&p)), EsejskoPitanje(p), _slozen(p._slozen) {
}
Pojam:: ~Pojam() { }

Pojam& Pojam::operator=(Pojam& p) {
	if (&p == this)
		return *this;

	Pitanje::operator=(p);
	MCMAPitanje::operator=(p);
	EsejskoPitanje::operator=(p);
	_slozen = p._slozen;
	return *this;
}

double Pojam::brojOsvojenihBodova() {
	double bodoviEsejskog = EsejskoPitanje::brojOsvojenihBodova();
	bodoviEsejskog /= _bodovi;

	double bodoviMCMA = MCMAPitanje::brojOsvojenihBodova();
	bodoviMCMA /= _bodovi;

	bodoviEsejskog *= (_bodovi / 2);
	bodoviMCMA *= (_bodovi / 2);

	return bodoviEsejskog + bodoviMCMA;
}

bool Pojam::odgovaranje(const char* odg = nullptr, int x = 0) {
	if (odg == nullptr)
		MCMAPitanje::odgovaranje(nullptr, x);
	else
		EsejskoPitanje::odgovaranje(odg, 0);

	return true;
}
bool Pojam::postaviPitanje() {
	if (_tekst == nullptr)
		return false;
	cout << "Opis pojma: " << Pitanje::_tekst << endl << endl;
	cout << "--Karakteristika pojma-- (Odabrati koje su stvarne)\n";
	int x = _odgovori.GetTrenutno();
	if (x < 0)
		return false;
	for (int i = 0; i < x; i++) {
		char* temp = _odgovori[i];
		if (temp != nullptr)
			cout << i + 1 << ". " << temp << endl;
	}
	cout << endl;
	return true;
}


//Jednostavno pitanje tipa Pojam nosi minimalno 3 boda, a ukoliko je rijec o složenom pojmu minimalno 5 bodova. 
void Pojam::print() {
	cout << "\n---> PREGLED PITANJA <----\n";
	cout << "--Rjeseno pitanje tipa Pojam--\n";
	cout << "Pojam: " << EsejskoPitanje::_tacanOdgovor << endl;
	cout << "Opis: " << _tacanOdgovor << endl;
	cout << "Karakteristike: ";
	int x = _odgovori.GetTrenutno();
	if (x > 0)
		for (int i = 0; i < x; i++)
			if (_odgovori(i))
				cout << _odgovori[i] << " - ";
	cout << endl;
}