#include "kontroler.hpp"
#include "widok.hpp"

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
			ekran = ekran_pop->przejdzDoWybranegoEkranu(odp);
			ekran -> oczekujNaOdpowiedz();
			cout<< "Mam piatke"<<endl;
			model->polaczZSerwerem();
			model->wyslijWiadomoscPosrednio("login",((EkranKomunikacji*) ekran)->getKomunikat());
			cout<<(((EkranKomunikacji*) ekran)->getKomunikat());
			model->zakonczPolaczenieZSerwerem();
			ekran_pop = new EkranLogowania();
			ekran_pop->wyswietlTekst(ekran_pop->zwrocListeKomunikatow());
			odp = ekran_pop->oczekujNaOdpowiedz();
		}
		ekran = ekran_pop->przejdzDoWybranegoEkranu(odp);
		ekran->czyscEkran();
		ekran_pop = ekran;
	}
}
