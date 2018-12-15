#include"pch.h"


int main() {

	//Testirati sve implementirane funkcionalnosti programa.  
	//Kreirati najmanje jedan test sa 10 pitanja. 
	Pitanje* p1=new MCMAPitanje(1, "Koji je glavni grad Bosne i Hercegovine?", "Geografija", 12);
	p1->dodavanjeOdgovora("Sarajevo", true);
	p1->dodavanjeOdgovora("Zenica", false);
	p1->dodavanjeOdgovora("Mostar", true);
	p1->dodavanjeOdgovora("Kakanje", false);
	p1->print();

	Pitanje* p2 = new EsejskoPitanje(1, "Koji je glavni grad Srbije?", "Geografija", 10,"Beograd","Ruma");
	p2->print();

	system("pause");  
	return 0;
}