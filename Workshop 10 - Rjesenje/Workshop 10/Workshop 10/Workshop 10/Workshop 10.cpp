#include"pch.h"


int main() {

	//Testirati sve implementirane funkcionalnosti programa.  
	//Kreirati najmanje jedan test sa 10 pitanja. 
	Pitanje* p1=new MCMAPitanje(1, "Koji je glavni grad Bosne i Hercegovine?", "Geografija", 12);
	p1->dodavanjeOdgovora("Sarajevo", true);
	p1->dodavanjeOdgovora("Zenica", false);
	p1->dodavanjeOdgovora("Mostar", true);
	p1->dodavanjeOdgovora("Kakanj", false);
	p1->postaviPitanje();
	int x; 
	bool loop;
	do {
		cout << "Vas odgovor(0-KRAJ): ";
		cin >> x;
		loop=p1->odgovaranje(nullptr,x);

	} while (loop);
	cout << "Za prvo pitanje osvojili ste " << p1->brojOsvojenihBodova() << " bodova\n";
	p1->print();
	cin.ignore();
	cout << endl << endl;
	Pitanje* p2 = new EsejskoPitanje(1, "Koji je glavni grad Srbije?", "Geografija", 10,"Beograd","Ruma");
	p2->postaviPitanje();
	char *odg = new char[150];
	cout << "Vas odgovor: ";
	cin.getline(odg, 150);
	p2->odgovaranje(odg, 0);
	cout << "Za drugo pitanje osvojili ste " << p2->brojOsvojenihBodova() << " bodova\n\n";
	system("pause");  
	return 0;
}