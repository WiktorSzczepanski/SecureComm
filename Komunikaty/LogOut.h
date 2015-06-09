#pragma once
#include "Komunikat.h"
class LogOut :
	public Komunikat
{	
	//idKomunikatu
	//idKomunikatu - dziedziczone z "Komunikat"
public:
	//serializacja
	std::string toString() const;

	//konstruktory
	LogOut();
	~LogOut();
};

