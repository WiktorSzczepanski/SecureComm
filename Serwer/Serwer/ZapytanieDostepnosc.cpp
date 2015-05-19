#include "ZapytanieDostepnosc.h"

//serializacja
std::string ZapytanieDostepnosc::toString()
{
	std::string ramka;
	ramka = std::to_string(this->getId());
	return ramka;
}

//konstruktory
ZapytanieDostepnosc::ZapytanieDostepnosc()
{
	this->setId(ZAPYTANIE_DOSTEPNOSC);
}


ZapytanieDostepnosc::~ZapytanieDostepnosc()
{
}
