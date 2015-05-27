#include "kontroler.hpp"
#include "widok.hpp"
#include "widok.cpp"


using namespace std;

Kontroler::Kontroler()
{
	model = new Model();
}

void Kontroler::petlaAplikacji()
{
        //TODO najlepiej to zrobic na sprytnym wskazniku, by obiekt nie wisial bez potrzeby
	Ekran ekranPowitalny = EkranPowitalny();
	Ekran *ekranAktualny = &ekranPowitalny;
        //TODO ekranNastepny tez nie musi byc dynamicznie alokowany, zwrocenie przez wartosc wystarczy
	Ekran *ekranNastepny;
	int odp;
	
	while (true)
	{
		ekranAktualny->wyswietlTekst(ekranAktualny->zwrocListeKomunikatow());
		odp = ekranAktualny->oczekujNaOdpowiedz();
		if (odp==5)
		{
			cout<< "Mam szostke"<<endl;
			model->polaczZSerwerem(10223,"localhost");
		//	model->zakonczPolaczenieZSerwerem();
		}
		ekranNastepny = ekranAktualny->przejdzDoWybranegoEkranu(odp);
		ekranNastepny->czyscEkran();
		ekranAktualny = ekran;
	}
}
