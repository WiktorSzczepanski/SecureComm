#include "widok.hpp"
#include "widok.cpp"

using namespace std;

int main()
{
	Ekran *ekran_pop = new EkranPowitalny();
	Ekran *ekran;
	
	while(true)
	{
		ekran_pop->wyswietlTekst(ekran_pop->zwrocListeKomunikatow());
		ekran = ekran_pop->przejdzDoWybranegoEkranu(ekran_pop->oczekujNaOdpowiedz());
		ekran_pop = ekran;
	}
	
	return 0;
}
