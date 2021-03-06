#pragma once
#include<cstring>
#include<iostream>
using namespace std;


class Pitanje {

protected:
	int _id;
	char* _oblast;
	char* _tekst;
	double _bodovi;

	char * AlocirajNizKarakteraa(const char * sadrzaj) {
		if (sadrzaj == nullptr)
			return nullptr;
		int vel = strlen(sadrzaj) + 1;
		char * temp = new char[vel];
		strcpy_s(temp, vel, sadrzaj);
		return temp;
	}

public:
	Pitanje() :_id(0), _oblast(nullptr), _tekst(nullptr), _bodovi(0) {
	}

	Pitanje(int id, const char* tekst, const char* oblast, double bodovi) : _id(id), _bodovi(bodovi), _oblast(AlocirajNizKarakteraa(oblast)),
		_tekst(AlocirajNizKarakteraa(tekst)) {
	}
	Pitanje(const Pitanje& p) {
		_id = p._id;
		_bodovi = p._bodovi;
		_oblast = AlocirajNizKarakteraa(p._oblast);
		_tekst = AlocirajNizKarakteraa(p._tekst);
	}

	Pitanje& operator=(const Pitanje& p) {
		if (&p == this)
			return *this;
		delete[] _tekst;
		delete[] _oblast;
		_tekst = AlocirajNizKarakteraa(p._tekst);
		_oblast = AlocirajNizKarakteraa(p._oblast);
		_bodovi = p._bodovi;
		_id = p._id;
		return *this;
	}

	virtual ~Pitanje() {

		delete[] _tekst;
		_tekst = nullptr;

		delete[] _oblast;
		_oblast = nullptr;
	}

	//PURE VIRTUAL FUNCTIONS
	virtual double brojOsvojenihBodova() = 0;

	virtual void dodavanjeOdgovora(const char*, bool) {
		return;
	} //dodavanje mogucih odgovora na pitanje od strane profesora

	virtual bool odgovaranje(const char*, int) = 0; //dodavanje odgovora studenta


	virtual bool postaviPitanje() = 0;

	//GET METHODS
	int getID()const { return _id; }
	char* getOblast()const { return _oblast; }
	char* getTekst()const { return _tekst; }
	double getBodovi()const { return _bodovi; }

	//SET METHODS
	void setID(int id) { _id = id; }
	void setOblast(const char* oblast) {
		delete[] _oblast;
		_oblast = AlocirajNizKarakteraa(oblast);
	}
	void setTekst(const char* tekst) {
		delete[] _tekst;
		_tekst = AlocirajNizKarakteraa(tekst);
	}
	void izmjenaPitanja() {
		int x;

		do {
			cout << "--IZMJENA PITANJA--\n";
			cout << "1 - NOVI TEKST\n2 - NOVA OBLAST\n3 - IZMJENA BODOVA\n0 - EXIT\nVas izbor: ";
			cin >> x;
			if (x < 0 || x>3)
				cout << "Greska! Ponovite unos..\n";
		} while ((x < 0 || x>3) && x != 0);
		cin.ignore();

		if (x == 0)
			return;
		if (x == 1) {
			char *noviTekst = new char[100];
			cout << "Unesite novi tekst: ";
			cin.getline(noviTekst, 100);
			setTekst(noviTekst);
		}
		else if (x == 2) {
			char* novaOblast = new char[100];
			cout << "Unesite novu oblast: ";
			cin.getline(novaOblast, 100);
			setOblast(novaOblast);
		}
		else if (x == 3) {
			double b;
			do {
				cout << "Unesite izmijenjen broj bodova: ";
				cin >> b;
				if (b < 0)
					cout << "Greska! Bodovi ne mogu biti negativni..\n";
			} while (b < 0);
			setBodovi(b);
		}
	}

	void setBodovi(double bodovi) { _bodovi = bodovi; }
	virtual void print() {
		if (_oblast == nullptr || _tekst == nullptr)
			return;
		cout << "ID: " << _id;
		cout << "\nOblast: " << _oblast;
		cout << "\nTekst: " << _tekst;
		cout << "\nBodovi: " << _bodovi << endl;
	}
};