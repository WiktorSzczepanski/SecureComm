#pragma once
#include "Komunikat.h"
class ZapytanieDostepnosc :
	public Komunikat
{
	//idKomunikatu
	//idKomunikatu - dziedziczone z "Komunikat"
public:
	//serializacja
	std::string toString() const;

	//konstruktory
	ZapytanieDostepnosc();
	~ZapytanieDostepnosc();
};

