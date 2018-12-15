#include"pch.h"


class Pitanje {
	int _id;
	char* _oblast;
	char* _tekst;
	double _bodovi;

public:
	Pitanje():_id(0),_oblast(nullptr),_tekst(nullptr),_bodovi(0){}

	Pitanje(int id, const char* tekst, const char* oblast, double bodovi) : _id(id), _bodovi(bodovi), _oblast(AlocirajNizKaraktera(oblast)),
		_tekst(AlocirajNizKaraktera(tekst)) {}
	Pitanje(const Pitanje& p):_oblast(AlocirajNizKaraktera(p._oblast)),_tekst(AlocirajNizKaraktera(p._tekst)),_bodovi(p._bodovi){}
	Pitanje(Pitanje&& p) :_bodovi(p._bodovi) {
		_tekst = p._tekst;
		_oblast = p._oblast;
		p._tekst = p._oblast = nullptr;
		cout << "MOVE CONSTRUCTOR POZVAN..\n";
	}
	virtual ~Pitanje(){
		delete[] _tekst;
		_tekst = nullptr;

		delete[] _oblast;
		_oblast = nullptr;
	}

	//GET METHODS
	int getID()const { return _id; }
	char* getOblast()const { return _oblast; }
	char* getTekst()const { return _tekst; }
	double getBodovi()const { return _bodovi; }

	//SET METHODS
	void setID(int id) { _id = id; }
	void setOblast(const char* oblast) {
		delete[] _oblast;
		_oblast = AlocirajNizKaraktera(oblast);
	}
	void setTekst(const char* tekst) {
		delete[] _tekst;
		_tekst = AlocirajNizKaraktera(tekst);
	}
	void setBodovi(double bodovi) { _bodovi = bodovi; }

	virtual ostream& operator<<(ostream&) = 0;
};
