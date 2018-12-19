#include"pch.h"

MCSAPitanje::MCSAPitanje() {}

MCSAPitanje::MCSAPitanje(int id, const char* tekst, const char* oblast, double bodovi) :MCMAPitanje(id, tekst, oblast, bodovi),Pitanje(id,tekst,oblast,bodovi) {}

MCSAPitanje::MCSAPitanje(const MCSAPitanje& x):MCMAPitanje(x) {}
MCSAPitanje::~MCSAPitanje() {}

double MCSAPitanje::brojOsvojenihBodova() {

	if (_oznaceniOdgovoriStudenta == nullptr || _brojOznacenihOdgovora <= 0)
		return 0;
	bool* odg = _odgovori((*_oznaceniOdgovoriStudenta)-1);
	if (odg!=nullptr && *odg)
		return _bodovi;
	else
		return 0;
}
bool MCSAPitanje::valid() {	return brojTacnih() == 1;}

//dodavanje mogucih odgovora na pitanje od strane profesora
void MCSAPitanje::dodavanjeOdgovora(const char* odg, bool tacan) {
	if (odg == nullptr)
		return;
	if (tacan && valid()) {
		cout << "Ne mozete dodati vise od jednog tacnog odgovora..\n";
		return;
	}
	_odgovori(AlocirajNizKaraktera(odg), tacan);
}

//dodavanje odgovora studenta
bool MCSAPitanje::odgovaranje(const char* odg=nullptr, int x=0) {
	int brodg = _odgovori.GetTrenutno();
	if (x<1 || x>brodg)
		return false;
	_oznaceniOdgovoriStudenta = new int(x);
	_brojOznacenihOdgovora = 1;
	return true;
}
bool MCSAPitanje::postaviPitanje() {
	if (_tekst == nullptr || !valid())
		return false;
	cout << "Pitanje: " << _tekst << endl;
	int x = _odgovori.GetTrenutno();
	if (x < 0)
		return false;
	cout << "--PONUDJENI ODGOVORI--\n";
	for (int i = 0; i < x; i++)
		cout << i + 1 << ". " << _odgovori[i] << endl;
	cout << endl;
	return true;
}

//uklanjanje odgovora
MCSAPitanje& MCSAPitanje::operator-=(int index) {
	_odgovori -= index;
	return *this;
}

void MCSAPitanje::print() {
	Pitanje::print();
	int x = _odgovori.GetTrenutno();
	if (x < 0)
		return;
	cout << "VALIDNO: ";
	if (valid())
		cout << "DA\n";
	else
		cout << "NE\n";
	cout << "--PONUDJENI ODGOVORI--\n\n";
	for (int i = 0; i < x; i++) {
		cout << i + 1 << ". " << _odgovori[i] << "  -   ";
		if (*_odgovori(i))
			cout << " TACNO\n";
		else
			cout << "NETACNO\n";
	}
	cout << "--STUDENT OZNACIO ODGOVOR SA REDNIM BROJEVIM: ";
	if (_brojOznacenihOdgovora > 0 || _oznaceniOdgovoriStudenta != nullptr)
		cout << *_oznaceniOdgovoriStudenta << endl;
	else
		cout << "--STUDENT NIJE OZNACIO NISTA--\n";
		
	cout << endl;
}