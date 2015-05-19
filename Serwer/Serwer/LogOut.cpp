#include "LogOut.h"

//serializacja
std::string LogOut::toString()
{
	std::string ramka;
	ramka = std::to_string(this->getId());
	return ramka;
}

//konstruktory
LogOut::LogOut()
{
}


LogOut::~LogOut()
{
}
