#include "kontroler.hpp"

using namespace std;

Kontroler::Kontroler(BQueue<string> *blockingQueue, Model *model)
{
	this->model = model;
	this->blockingQueue = blockingQueue;
	wypelnijMapeAkcji();
	blockingQueue->push("EkranPowitalny");
}

void Kontroler::wypelnijMapeAkcji()
{
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranPowitalny",new EkranPowitalnyAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranLogowania",new EkranLogowaniaAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranRejestracji",new RejestrowanieAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranAutoryzacjiHaslem",new AutoryzacjaHaslemAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranAutoryzacjiKluczem",new SecureCommAction()));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranPowrotu",new SecureCommAction()));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranWyboruZnajomego",new WyborZnajomegoAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranKomunikacji",new KomunikacjaAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranDodaniaKontaktu",new DodanieZnajomegoAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranWyswietlaniaListyUzytkownikow",new WyswietlenieZnajomychAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranPoprawnejAutoryzacji",new SecureCommAction()));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranWyboruZnajomegoBezposrednia",new WyborZnajomegoBezposredniaAction(model)));	
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranKomunikacjiBezposredniej",new KomunikacjaBezposredniaAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("KomunikatPoprawnegoLogowania",new PoprawneLogowanieAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("KomunikatNiepoprawnegoLogowania",new NiepoprawneLogowanieAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("KomunikatPoprawnejRejestracji",new PoprawnaRejestracjaAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("KomunikatNiepoprawnejRejestracji",new NiepoprawnaRejestracjaAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("KomunikatWiadomosciPosredniej",new WiadomoscPosredniaAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("KomunikatListyZnajomych",new ListaZnajomychAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("KomunikatDodaniaZnajomego",new PoprawneDodanieZnajomego(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("KomunikatPoprawnegoWylogowania",new PoprawneWylogowanie(model)));
}

void Kontroler::petlaAplikacji()
{
	Ekran *ekran_pop;
	Ekran *ekran;
	ekran_pop = new Ekran();
	ekran_pop->czyscEkran();
	ekran_pop = new EkranPowitalny();
	
	int odp;
	
	while(true)
	{	
		ekran_pop->wyswietlTekst(ekran_pop->zwrocListeKomunikatow());
		odp = ekran_pop->oczekujNaOdpowiedz();
		
		string event = blockingQueue->pop();
		it = mapaAkcji.find(event);
		
		
		if (it == mapaAkcji.end()) 
		{
			cout<< "Upsss cos poszlo nie tak";
		} 
		else 
		{	
			SecureCommAction* akcja = it->second;
			odp = akcja->wykonajAkcje(ekran_pop,odp);
		}
		ekran = ekran_pop->przejdzDoWybranegoEkranu(odp);
		
		if(ekran->getNazwaKlasy() != "EkranOczekiwaniaNaSerwer")
		{
			model->dodajZdarzenieDoKolejki(ekran->getNazwaKlasy());
		}
			
		ekran_pop = ekran;
		
		
	/*	ekran_pop->wyswietlTekst(ekran_pop->zwrocListeKomunikatow());
		odp = ekran_pop->oczekujNaOdpowiedz();
		
		it = mapaAkcji.find(ekran_pop->getNazwaKlasy());

		if (it == mapaAkcji.end()) 
		{
			cout<< "Upsss cos poszlo nie tak";
		} 
		else 
		{	
			SecureCommAction* akcja = it->second;
			akcja->wykonajAkcje(ekran_pop);
		}
		
		ekran = ekran_pop->przejdzDoWybranegoEkranu(odp);
		ekran_pop = ekran;*/
	}
	
}
Kontroler::~Kontroler()
{
	delete model;
}
