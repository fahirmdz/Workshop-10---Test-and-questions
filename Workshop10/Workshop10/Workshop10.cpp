#include"pch.h"


int main() {

	//Testirati sve implementirane funkcionalnosti programa.  
	//Kreirati najmanje jedan test sa 10 pitanja. 

	//========MCMA pitanje provjera funkcionalnosti===========================
	cout << "\n=============TEST MCMA PITANJE================\n\n";
	Pitanje* p1 = new MCMAPitanje(1, "Koji je glavni grad Bosne i Hercegovine?", "Geografija", 12);
	p1->dodavanjeOdgovora("Sarajevo", true);
	p1->dodavanjeOdgovora("Zenica", false);
	p1->dodavanjeOdgovora("Mostar", true);
	p1->dodavanjeOdgovora("Kakanj", false);

	Pitanje *p1copy = new MCMAPitanje(*dynamic_cast<MCMAPitanje*>(p1));
	p1copy->print();
	if (p1->postaviPitanje()) {
		int x;
		bool loop;
		do {
			cout << "vas odgovor(0-kraj): ";
			cin >> x;
			loop = p1->odgovaranje(nullptr, x);
			cin.ignore();
		} while (loop);
		cout << "za prvo pitanje osvojili ste " << p1->brojOsvojenihBodova() << " bodova\n";
		p1->print();
	}
	cin.ignore();
	////=========================================================================


	////=============EsejskoPitanje provjera funkcionlanosti===================================
	cout << "\n=============TEST ESEJSKO PITANJE================\n\n";

	cout << endl << endl;
	Pitanje* p2 = new EsejskoPitanje(1, "Koji je glavni grad Srbije?", "Geografija", 10, "Beograd");
	Pitanje* p2copy = new EsejskoPitanje(*dynamic_cast<EsejskoPitanje*>(p2));
	p2->postaviPitanje();
	char *odg = new char[150];
	cout << "Vas odgovor: ";
	cin.getline(odg, 150);
	p2->odgovaranje(odg, 0);
	cin.ignore();
	cout << "Za drugo pitanje osvojili ste " << p2->brojOsvojenihBodova() << " bodova\n\n";
	//==============================================================================



	//=================MCSA Pitanje provjera funkcionalnosti=============================
	cout << "\n=============TEST MCSA PITANJE================\n\n";

	Pitanje* p3 = new MCSAPitanje(3, "Koji je glavni grad Belgije?", "Geografija", 20);
	p3->dodavanjeOdgovora("Gent", false);
	p3->dodavanjeOdgovora("Antwerpen", false);
	p3->dodavanjeOdgovora("Brisel", true);
	Pitanje* p3copy = new MCSAPitanje(*dynamic_cast<MCSAPitanje*>(p3));

	p3->postaviPitanje();
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
	cout << "Za trece pitanje osvojili ste " << p3->brojOsvojenihBodova() << " bodova\n";
	p3->print();
	cin.ignore();
	////=================================================================================

	////===================TESTIRANJE PITANJA TIPA POJAM===========================
	cout << "\n=============TEST POJMA================\n\n";

	Pitanje* p4 = new Pojam(false, 4, "Osobine", 30, "Obicno se kaze za covjeka koji puno radi i daje sve od sebe", "Vrijedan");
	p4->dodavanjeOdgovora("Svako to cijeni", true);
	p4->dodavanjeOdgovora("Puno napora se ulaze", true);
	p4->dodavanjeOdgovora("Vole mladi", false);
	Pitanje* p4copy = new Pojam(*dynamic_cast<Pojam*>(p4));

	p4->postaviPitanje();

	p4->odgovaranje(nullptr, 1); //DODAVANJE ODGOVORA ZA PONUDJENE KARAKTERISTIKE
	p4->odgovaranje(nullptr, 2); //--||--
    p4->odgovaranje("Vrijedan", 0); // DODAVANJE ODGOVORA ZA NAZIV POJMA (ESEJSKO)

	cout << "Student osvojio " << p4->brojOsvojenihBodova() << " bodova\n\n";
	//=================================================================================


	//=============TESTIRANJE KLASE TEST================================================
	cout << "\n=============TEST KLASE 'TEST'================\n\n";

	Test nekiTest("IB123456");

	//****dodatak "copy" u nazivu pitanja predstavlja kopiju pitanja koje je alocirano i prazno (nije odgovoreno), jer je originalno testirano
	// i sadrzi odgovore studenta (testirano iznad)**********
	nekiTest += (*p1copy);
	nekiTest += (*p2copy);
	nekiTest += (*p3copy);
	nekiTest += (*p4copy);
	nekiTest.pokreniTest();
	cout << "\n--Uspjeh studenta sa brojem indeksa " << nekiTest.getIndeks() << " na testu--\nUspjeh u procentima: " << nekiTest.getRezultat() << " %\nOcjena: "<<nekiTest.getOcjena()<<"\n";


	//=================================================================================

	//DEALOKACIJA OBJEKATA U DINAMICKOJ MEMORIJI

	
	
	delete p1copy, p2copy, p3copy, p4copy, p1, p2, p3, p4;
	p1copy = nullptr;
	p2copy = nullptr;
	p3copy = nullptr;
	p4copy = nullptr;
	p1 = nullptr;
	p2 = nullptr;
	p3 = nullptr;
	p4 = nullptr;
	
	system("PAUSE");
	return 0;
}