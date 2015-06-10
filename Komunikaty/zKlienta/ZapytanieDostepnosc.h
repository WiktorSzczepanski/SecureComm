#pragma once
#include "../Komunikat.h"
class ZapytanieDostepnosc :
	public Komunikat
{
	//idKomunikatu # idNadawcy 
	//idKomunikatu - dziedziczone z "Komunikat"
public:
	//serializacja
	std::string toString() const override;

	//konstruktory
	ZapytanieDostepnosc(const UserId nadawca);
	~ZapytanieDostepnosc();
};

