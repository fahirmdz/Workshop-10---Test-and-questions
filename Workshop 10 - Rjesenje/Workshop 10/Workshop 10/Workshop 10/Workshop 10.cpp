#include"pch.h"
#include<cstdlib>

void main() {

	//Testirati sve implementirane funkcionalnosti programa.  
	//Kreirati najmanje jedan test sa 10 pitanja. 

	//========MCMA pitanje provjera funkcionalnosti===========================
	Pitanje* p1=new MCMAPitanje(1, "Koji je glavni grad Bosne i Hercegovine?", "Geografija", 12);
	p1->dodavanjeOdgovora("Sarajevo", true);
	p1->dodavanjeOdgovora("Zenica", false);
	p1->dodavanjeOdgovora("Mostar", true);
	p1->dodavanjeOdgovora("Kakanj", false);

	if (p1->postaviPitanje()) {
		int x;
		bool loop;
		do {
			cout << "vas odgovor(0-kraj): ";
			cin >> x;
			loop = p1->odgovaranje(nullptr, x);

		} while (loop);
		cout << "za prvo pitanje osvojili ste " << p1->brojOsvojenihBodova() << " bodova\n";
		p1->print();
	}
	cin.ignore();
	////=========================================================================


	////=============EsejskoPitanje provjera funkcionlanosti===================================
	cout << endl << endl;
	Pitanje* p2 = new EsejskoPitanje(1, "Koji je glavni grad Srbije?", "Geografija", 10,"Beograd");
	p2->postaviPitanje();
	char *odg = new char[150];
	cout << "Vas odgovor: ";
	cin.getline(odg, 150);
	p2->odgovaranje(odg, 0);
	cout << "Za drugo pitanje osvojili ste " << p2->brojOsvojenihBodova() << " bodova\n\n";
	//==============================================================================


	
	//=================MCSA Pitanje provjera funkcionalnosti=============================
	
		Pitanje* p3 = new MCSAPitanje(3, "Koji je glavni grad Belgije?", "Geografija", 20);
		p3->dodavanjeOdgovora("Gent", false);
		p3->dodavanjeOdgovora("Antwerpen", false);
		p3->dodavanjeOdgovora("Brisel", true);
	
	
	bool loopp;
	int xx;
	if (p3->postaviPitanje()) {
		do {
			loopp = true;
			cout << "Vas odgovor(0-kraj): ";
			cin >> xx;
			loopp = p3->odgovaranje(nullptr, xx);
			cin.ignore();
			if (!loopp)
				cout << "Greska! Unijeli ste pogresan redni broj..\n";

		} while (!loopp);
	}
	cout << "za trece pitanje osvojili ste " << p3->brojOsvojenihBodova() << " bodova\n";
	p3->print();
	cin.ignore();
	//=================================================================================
	delete p2;
	p2 = nullptr;
	delete p1;
	p1 = nullptr;
	delete p3;
	p3 = nullptr;
}