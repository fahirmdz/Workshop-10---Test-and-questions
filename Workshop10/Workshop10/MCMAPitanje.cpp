#include"pch.h"

//Konstruktor i destruktor  
MCMAPitanje::MCMAPitanje() :_oznaceniOdgovoriStudenta(nullptr), _brojOznacenihOdgovora(0), _odgovori(5) {
}

MCMAPitanje::MCMAPitanje(int id, const char* tekst, const char* oblast, double bodovi) : Pitanje(id, tekst, oblast, bodovi),
_brojOznacenihOdgovora(0), _oznaceniOdgovoriStudenta(nullptr),_odgovori(5) {
}

MCMAPitanje::MCMAPitanje(MCMAPitanje& mp) :
	_brojOznacenihOdgovora(mp._brojOznacenihOdgovora) {
	_tekst = AlocirajNizKaraktera(mp._tekst);
	_oblast = AlocirajNizKaraktera(mp._oblast);
	_id = mp._id;
	_bodovi = mp._bodovi;
	int x = mp._odgovori.GetTrenutno();
	if (x > 0)
		for (int i = 0; i < x; i++)
			_odgovori(AlocirajNizKaraktera(mp._odgovori[i]), mp._odgovori(i));

	if (_brojOznacenihOdgovora > 0)
	{
		_oznaceniOdgovoriStudenta = new int[_brojOznacenihOdgovora];
		for (int i = 0; i < _brojOznacenihOdgovora; i++)
			_oznaceniOdgovoriStudenta[i] = mp._oznaceniOdgovoriStudenta[i];
	}
	else _oznaceniOdgovoriStudenta = nullptr;
}

//MCMAPitanje::MCMAPitanje(MCMAPitanje&& mp):_odgovori(mp._odgovori),_brojOznacenihOdgovora(mp._brojOznacenihOdgovora) {
//	_oznaceniOdgovoriStudenta = mp._oznaceniOdgovoriStudenta;
//	mp._oznaceniOdgovoriStudenta = nullptr;
//}

MCMAPitanje::~MCMAPitanje() {
	delete[] _oznaceniOdgovoriStudenta;	_oznaceniOdgovoriStudenta = nullptr;
	for (int i = 0; i < _odgovori.GetTrenutno(); i++) {
		delete[] _odgovori[i];
		_odgovori[i] = nullptr;
	}
}

int MCMAPitanje::brojTacnih() {
	int brOdg = _odgovori.GetTrenutno();
	if (brOdg <= 0)
		return 0;
	int brTacnih = 0;
	for (int i = 0; i < brOdg; i++)
		if (_odgovori(i))
			brTacnih++;
	return brTacnih;
}

double MCMAPitanje::brojOsvojenihBodova() {
	int brOdg = _odgovori.GetTrenutno();
	if (_oznaceniOdgovoriStudenta == nullptr || _brojOznacenihOdgovora <= 0 || brOdg <= 0)
		return 0;
	int brTacnih = brojTacnih();

	double bodovi = 0;
	for (int i = 0; i < _brojOznacenihOdgovora; i++) {
		if (_odgovori(_oznaceniOdgovoriStudenta[i] - 1))
			bodovi += _bodovi / brTacnih;
		else
			bodovi -= ((_bodovi / brTacnih)*0.2);//oduzima bodove za netacan odgovor (20% od tacnog)
	}
	if (bodovi < 0)
		bodovi = 0;
	return bodovi;
}

bool MCMAPitanje::odgovaranje(const char* a = nullptr, int x = 0) {
	int brodg = _odgovori.GetTrenutno();
	if (x <= 0 || x > brodg)
		return false;
	if (_brojOznacenihOdgovora >= brodg) {
		cout << "Ne mozete unijeti vise od " << brodg << " odgovora..\n";
		return false;
	}
	int* temp = new int[_brojOznacenihOdgovora + 1];
	if (_brojOznacenihOdgovora > 0)
		for (int i = 0; i < _brojOznacenihOdgovora; i++)
			temp[i] = _oznaceniOdgovoriStudenta[i];
	delete[] _oznaceniOdgovoriStudenta;
	_oznaceniOdgovoriStudenta = temp;
	_oznaceniOdgovoriStudenta[_brojOznacenihOdgovora++] = x;
	return true;
}

//Funkciju za dodavanje odgovora u listu koja treba da osigura da su najmanje 2 (od max) odgovora oznacena kao tacna. 
// Dok se ne dodaju svi predvideni odgovori pitanje ne treba biti upotrebljivo ukoliko prethodni uslov nije ispunjen (ne prikazivati 
//pitanja na ispisu). 
//Napomena: Podatke o odgovorima cuvati u zasebnoj memoriji i istu dealocirati unutar same klase. 
void MCMAPitanje::dodavanjeOdgovora(const char* odg, bool tacan = false) {
	_odgovori(AlocirajNizKaraktera(odg), tacan);
}

MCMAPitanje& MCMAPitanje::operator=(MCMAPitanje& mp) {
	if (&mp == this)
		return *this;
	Pitanje::operator=(mp);

	delete[] _oznaceniOdgovoriStudenta;
	_brojOznacenihOdgovora = mp._brojOznacenihOdgovora;
	if (_brojOznacenihOdgovora > 0 && mp._oznaceniOdgovoriStudenta != nullptr) {
		_oznaceniOdgovoriStudenta = new int[_brojOznacenihOdgovora];
		for (int i = 0; i < _brojOznacenihOdgovora; i++)
			_oznaceniOdgovoriStudenta[i] = mp._oznaceniOdgovoriStudenta[i];
	}
	int brodg = mp._odgovori.GetTrenutno();
	if (brodg > 0)
		for (int i = 0; i < brodg; i++)
			_odgovori((AlocirajNizKaraktera(mp._odgovori[i]), mp._odgovori(i)));

	return *this;
}

//Funkciju za uklanjanje odgovora na osnovu rednog broja u listi. Ukoliko se uklanja odgovor koji je oznacen kao tacan i 
//pri tome u listi ostaje samo jo� jedan odgovor oznacen kao tacan, pitanje postaje neupotrebljivo dok se ne doda jo� jedan 
//tacan odgovor. 
MCMAPitanje& MCMAPitanje::operator-=(int index) {
	_odgovori -= index;
	return *this;
}

//Funkciju za promjenu odgovora na odredenom rednom broju. 
MCMAPitanje& MCMAPitanje::operator()(int index, const char* noviTekst) {
	char* odg = _odgovori[index];
	if (odg != nullptr) {
		delete[] odg;
		odg = AlocirajNizKaraktera(noviTekst);
	}
	return *this;
}

char* MCMAPitanje::operator[](int index) { return AlocirajNizKaraktera((char*)_odgovori[index]); }

bool MCMAPitanje::operator()(int index) { return _odgovori[index]; }
bool MCMAPitanje::postaviPitanje() {
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

bool MCMAPitanje::valid() {
	int bro = _odgovori.GetTrenutno();
	int brojac = brojTacnih();
	if (bro <= 0)
		return false;
	if (brojac < 2)
		return false;
	return true;
}

int MCMAPitanje::getBrojPonudjenih() {
	return _odgovori.GetTrenutno();
}

void MCMAPitanje::print() {
	Pitanje::print();
	int x = _odgovori.GetTrenutno();
	if (x < 0)
		return;
	cout << "\n---> PREGLED PITANJA <----\n";

	cout << "--PONUDJENI ODGOVORI--\n\n";
	for (int i = 0; i < x; i++) {
		cout << i + 1 << ". " << _odgovori[i] << "  -   ";
		if (_odgovori(i))
			cout << " TACNO\n";
		else
			cout << "NETACNO\n";
	}
	if (_oznaceniOdgovoriStudenta != nullptr) {
		cout << "--STUDENT OZNACIO ODGOVORE SA REDNIM BROJEVIMA: ";
		if (_brojOznacenihOdgovora > 0)
			for (int i = 0; i < _brojOznacenihOdgovora; i++)
				cout << _oznaceniOdgovoriStudenta[i] << " , ";
	}
	else cout << "**--NEMA OZNACENIH ODGOVORA--**\n";
	cout << endl;
}
