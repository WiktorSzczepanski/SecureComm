#include "kontroler.hpp"


using namespace std;

Kontroler::Kontroler()
{
	model = new Model();
	wypelnijMapeAkcji();
}

void Kontroler::wypelnijMapeAkcji()
{
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranPowitalny",new SecureCommAction()));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranLogowania",new SecureCommAction()));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranRejestracji",new RejestrowanieAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranAutoryzacjiHaslem",new AutoryzacjaHaslemAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranAutoryzacjiKluczem",new SecureCommAction()));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranPowrotu",new SecureCommAction()));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranKomunikacji",new SecureCommAction()));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranDodaniaKontaktu",new DodanieZnajomegoAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranWyswietlaniaListyUzytkownikow",new WyswietlenieZnajomychAction(model)));
	mapaAkcji.insert(pair<string,SecureCommAction*>("EkranPoprawnejAutoryzacji",new SecureCommAction()));
	
}

void Kontroler::petlaAplikacji()
{
	
	ekran_pop = new Ekran();
	ekran_pop->czyscEkran();
	ekran_pop = new EkranPowitalny();
	
	int odp;
	
	while(true)
	{	
		ekran_pop->wyswietlTekst(ekran_pop->zwrocListeKomunikatow());
		odp = ekran_pop->oczekujNaOdpowiedz();
		
		it = mapaAkcji.find(ekran_pop->getNazwaKlasy());

		if (it == mapaAkcji.end()) 
		{
			cout<< "Upsss cos poszlo nie tak";
		} 
		else 
		{	if(ekran_pop->getNazwaKlasy()=="EkranAutoryzacjiHaslem")
			{
				cout<<((EkranAutoryzacjiHaslem*)ekran_pop)->getLogin()<<endl;
			}
			SecureCommAction* akcja = it->second;
			akcja->wykonajAkcje(ekran_pop);
		}
		
		
		if(ekran_pop->getNazwaKlasy() == "EkranPoprawnejAutoryzacji" && odp ==5)
		{
			ekran = ekran_pop->przejdzDoWybranegoEkranu(odp);
			ekran -> oczekujNaOdpowiedz();
			cout<< "Mam piatke"<<endl;
		//	model->polaczZSerwerem();
		//	model->wyslijWiadomoscPosrednio("login",Czesc(((EkranKomunikacji*) ekran)->getKomunikat()));
			cout<<(((EkranKomunikacji*) ekran)->getKomunikat());
		//	model->zakonczPolaczenieZSerwerem();
			ekran_pop = new EkranLogowania();
			ekran_pop->wyswietlTekst(ekran_pop->zwrocListeKomunikatow());
			odp = ekran_pop->oczekujNaOdpowiedz();
		}
		ekran = ekran_pop->przejdzDoWybranegoEkranu(odp);
		ekran->czyscEkran();
		ekran_pop = ekran;
		
		
		
	}
	
}
Kontroler::~Kontroler()
{
	delete model;
}
