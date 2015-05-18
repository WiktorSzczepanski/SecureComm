#include "User.h"

//gettery
std::string User::getNazwa()
{
	return this->nazwa;
}
std::string User::getHaslo()
{
	return this->haslo;
}

//settery
void User::setNazwa(std::string nowaNazwa)
{
	this->nazwa = nowaNazwa;
}
void User::setHaslo(std::string noweHaslo)
{
	this->haslo = noweHaslo;
}

//konstruktory
User::User(std::string nazwa, std::string haslo, std::tm dataRejestracji)
{
	this->nazwa = nazwa;
	this->haslo = haslo;
	this->dataOstatniegoLogowania = dataOstatniegoLogowania;
}


User::~User()
{
}
