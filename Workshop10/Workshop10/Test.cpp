#include"pch.h"

Test::Test() :_maksimalnoBodova(0), _osvojenoBodova(0), _rezultat(0), ocjena(5) {
	for (int i = 0; i < 30; i++)
		_pitanja[i] = nullptr;
}
Test::Test(const char* indeks) : ocjena(5), _osvojenoBodova(0), _maksimalnoBodova(0), _rezultat(0) {
	strncpy_s(_brojIndeksa, indeks, 8);
	for (int i = 0; i < 30; i++)
		_pitanja[i] = nullptr;
}
Test::Test(const Test& test) : _maksimalnoBodova(test._maksimalnoBodova), _osvojenoBodova(test._osvojenoBodova), _rezultat(test._rezultat), ocjena(test.ocjena) {
	strncpy_s(_brojIndeksa, test._brojIndeksa, _TRUNCATE);
	int x = test.getSlobodno();

	if (x != 0)
		for (int i = 0; i < x; i++)
			if (test._pitanja[i] != nullptr)
				(*this) += (*test._pitanja[i]);
}

Test::~Test() {
	int x = getSlobodno();
	if (x > 0)
		for (int i = 0; i < x; i++) {
			delete _pitanja[i];
			_pitanja[i] = nullptr;
		}
}

int Test::getSlobodno()const {
	for (int i = 0; i < 30; i++)
		if (_pitanja[i] == nullptr)
			return i;
	return 30;
}

Test& Test::operator=(const Test& test) {
	if (&test == this)
		return *this;
	strncpy_s(_brojIndeksa, test._brojIndeksa, 8);
	_maksimalnoBodova = test._maksimalnoBodova;
	_rezultat = test._rezultat;
	_osvojenoBodova = test._osvojenoBodova;
	ocjena = test.ocjena;
	int x = test.getSlobodno();

	if (x != 0)
		for (int i = 0; i < x; i++) {
			delete _pitanja[i];
			if (test._pitanja[i] != nullptr)
				(*this) += (*test._pitanja[i]);
		}
	return *this;
}

//dodavanje novog Pitanja
Test& Test::operator+=(Pitanje& p) {
	int prviSl = getSlobodno();

	if (prviSl == 30) {
		cout << "Ne mozete dodati vise pitanja..\n";
		return *this;
	}
	if (prviSl != 0)
		for (int i = 0; i < prviSl; i++)
			if (_pitanja[i] != nullptr && strcmp(_pitanja[i]->getTekst(), p.getTekst()) == 0) {
				cout << "Pitanje vec postoji!\n";
				return *this;
			}
	if (dynamic_cast<Pojam*>(&p) != nullptr)
		_pitanja[prviSl] = new Pojam(*dynamic_cast<Pojam*>(&p));
	else if (dynamic_cast<MCSAPitanje*>(&p) != nullptr)
		_pitanja[prviSl] = new MCSAPitanje(*dynamic_cast<MCSAPitanje*>(&p));
	else if (dynamic_cast<MCMAPitanje*>(&p) != nullptr)
		_pitanja[prviSl] = new MCMAPitanje(*dynamic_cast<MCMAPitanje*>(&p));
	else if (dynamic_cast<EsejskoPitanje*>(&p) != nullptr)
		_pitanja[prviSl] = new EsejskoPitanje(*dynamic_cast<EsejskoPitanje*>(&p));
	_maksimalnoBodova += p.getBodovi();
	cout << "Pitanje uspjesno dodano..\n";
	return *this;
}

Pitanje* Test::operator[](int index) {
	int x = getSlobodno();

	if (index<0 || index>x - 1 || x == 0)
		return nullptr;
	return _pitanja[index];
}

int Test::izracunajOcjenu() {
	int x = getSlobodno();
	if (x == 0)
		return 0;
	double ocj = 5;
	if (_maksimalnoBodova > 0 && _osvojenoBodova > 0)
		_rezultat = (_osvojenoBodova / _maksimalnoBodova) * 100;
	
	if (_rezultat > 0)
		ocj = (double)10 * ((double)_rezultat/100);
	if (ocj - (int)ocj > 0.49)
		return (int)ocj + 1;
	else
		return (int)ocj;
}

int Test::getOcjena()const {
	return ocjena;
}
double Test::getRezultat()const
{
	return _rezultat;
}
double Test::getOsvojeniBodovi()const {
	return _osvojenoBodova;
}
double Test::getMaxBodova()const {
	return _maksimalnoBodova;
}
char* Test::getIndeks()const {
	return AlocirajNizKaraktera((char*)_brojIndeksa);
}

void Test::pokreniTest() {
	cout << "\n---Test pokrenut---\n\n ";
	int brojPitanja = getSlobodno();
	if (brojPitanja == 0)
		return;
	auto pomocnaOdgovoranje = [](MCMAPitanje& temp) {
		int z = temp.getBrojPonudjenih(), x;
		bool loop;
		do {
			loop = false;
			cin >> x;
			if (x >= 1 && x <= temp.getBrojPonudjenih())
				loop = temp.odgovaranje(nullptr, x);
		} while (loop);
		cin.ignore();
	};
	for (int i = 0; i < brojPitanja; i++) {
		if (_pitanja[i] != nullptr) {
			if (dynamic_cast<Pojam*>(_pitanja[i]) != nullptr) {
				Pojam* temp = dynamic_cast<Pojam*>(_pitanja[i]);
				int z = temp->getBrojPonudjenih();
				temp->postaviPitanje();
				cout << "Odaberite tacne karakteristike (1-" << z << ", 0-KRAJ): ";
				pomocnaOdgovoranje(*temp);
				cout << "Naziv pojma: ";
				char *odz = new char[50];
				cin.getline(odz, 50);
				temp->odgovaranje(odz, 0);
				odz = nullptr;
				temp = nullptr;

			}
			else if (dynamic_cast<MCSAPitanje*>(_pitanja[i]) != nullptr) {
				MCSAPitanje* temp = dynamic_cast<MCSAPitanje*>(_pitanja[i]);
				temp->postaviPitanje();
				int z = temp->getBrojPonudjenih();
				cout << "Odaberite tacan odgovor (1-" << z << ", 0-KRAJ): ";
				int x;
				do
				{
					cin >> x;
					if (x<0 || x>z)
						cout << "Greska! Ponovite unos!\n";

				} while (x<1 || x>z);
				temp->odgovaranje(nullptr, x);

				cin.ignore();
				temp = nullptr;
			}
			else if (dynamic_cast<MCMAPitanje*>(_pitanja[i]) != nullptr) {
				MCMAPitanje* temp = dynamic_cast<MCMAPitanje*>(_pitanja[i]);
				temp->postaviPitanje();
				int z = temp->getBrojPonudjenih();
				cout << "Odaberite tacne odgovore (1-" << z << ", 0-KRAJ): ";
				pomocnaOdgovoranje(*temp);
				temp = nullptr;
			}
			else if (dynamic_cast<EsejskoPitanje*>(_pitanja[i]) != nullptr) {
				EsejskoPitanje* temp = dynamic_cast<EsejskoPitanje*>(_pitanja[i]);
				temp->postaviPitanje();
				cout << "Naziv pojma: ";
				char *odg = new char[150];
				cin.getline(odg, 150);
				temp->odgovaranje(odg, 0);
				odg = nullptr;
				temp = nullptr;
			}
			_osvojenoBodova += _pitanja[i]->brojOsvojenihBodova();
		}
	}
	ocjena = izracunajOcjenu();
	cout << "\n\n--TEST ZAVRSEN---\n\n";
}


void Test::print() {
	int x = getSlobodno();
	if (x == 0) {
		cout << "\nSTUDENT JOS UVIJEK NIJE RADIO TEST!\n";
		return;
	}
	cout << "Broj indeksa: " << _brojIndeksa << endl;
	cout << "Maksimalan broj bodova: " << _maksimalnoBodova;
	cout << "\nOsvojeno bodova: " << _osvojenoBodova;
	cout << "\nRezultat u procentima: " << _rezultat << "%\n";
	cout << "Ocjena: " << ocjena << endl;

	cout << "---LISTA PITANJA SA ODGOVORIMA STUDENTA---\n";
	for (int i = 0; i < x; i++)
		if (_pitanja[i] != nullptr) {
			_pitanja[i]->print();
			cout << endl;
		}
	cout << endl;
}