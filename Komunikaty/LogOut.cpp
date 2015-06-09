#include "LogOut.h"

//serializacja
std::string LogOut::toString() const
{
	std::string ramka;
	ramka = std::to_string(this->getId());
	return ramka;
}

//konstruktory
LogOut::LogOut()
{
	this->setId(LOGOUT);
}


LogOut::~LogOut()
{
}
