#include "ZapytanieDostepnosc.h"

//serializacja
std::string ZapytanieDostepnosc::toString()
{
	std::string ramka;
	ramka = std::to_string(this->getId());
	return ramka;
}

//konstruktory
ZapytanieDostepnosc::ZapytanieDostepnosc(const UserId nadawca)
{
	this->setIdNadawcy(nadawca);
	this->setId(ZAPYTANIE_DOSTEPNOSC);
}


ZapytanieDostepnosc::~ZapytanieDostepnosc()
{
}
