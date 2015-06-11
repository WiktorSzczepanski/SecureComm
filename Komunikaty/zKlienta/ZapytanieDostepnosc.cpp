#include "ZapytanieDostepnosc.h"

//serializacja
std::string ZapytanieDostepnosc::toString() const
{
	std::string ramka;
	ramka = std::to_string(this->getId());
	return ramka;
}

//konstruktory
ZapytanieDostepnosc::ZapytanieDostepnosc(const UserId nadawca)
{
	this->setId(ZAPYTANIE_DOSTEPNOSC);
	this->setIdNadawcy(nadawca);
}
ZapytanieDostepnosc::ZapytanieDostepnosc(const ZapytanieDostepnosc &komunikat)
{
	this->setId(ZAPYTANIE_DOSTEPNOSC);
	this->setIdNadawcy(komunikat.getIdNadawcy());
}

ZapytanieDostepnosc::~ZapytanieDostepnosc()
{
}
