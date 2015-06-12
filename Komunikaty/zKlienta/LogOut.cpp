#include "LogOut.h"

//serializacja
std::string LogOut::toString() const
{
	std::string ramka;
	ramka = std::to_string(this->getId());
	return ramka;
}

//konstruktory
LogOut::LogOut(const UserId nadawca)
{
	this->setId(LOGOUT);
	this->setIdNadawcy(nadawca);
}
LogOut::LogOut(const LogOut &komunikat)
{
	this->setId(LOGOUT);
	this->setIdNadawcy(komunikat.getIdNadawcy());
}

LogOut::~LogOut()
{
}
