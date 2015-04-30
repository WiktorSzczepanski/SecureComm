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
	Ekran *ekran_pop = new EkranPowitalny();
	Ekran *ekran;
	int odp;
	
	while(true)
	{
		ekran_pop->wyswietlTekst(ekran_pop->zwrocListeKomunikatow());
		odp = ekran_pop->oczekujNaOdpowiedz();
		if(odp==5)
		{
			cout<< "Mam szostke"<<endl;
			model->polaczZSerwerem(10223,"localhost");
		//	model->zakonczPolaczenieZSerwerem();
		}
		ekran = ekran_pop->przejdzDoWybranegoEkranu(odp);
		ekran->czyscEkran();
		ekran_pop = ekran;
	}
	
}
