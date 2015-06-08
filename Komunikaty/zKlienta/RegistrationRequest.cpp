#include "RegistrationRequest.h"

//serializacja
std::string RegistrationRequest::toString()
{
	std::string ramka;
	ramka = std::to_string(this->getId()) + '#' + this->getNazwaUzytkownika() + '#' + this->getHaslo();
	return ramka;
}

//gettery
std::string RegistrationRequest::getNazwaUzytkownika()
{
	return this->nazwaUzytkownika;
}

std::string RegistrationRequest::getHaslo()
{
	return this->haslo;
}

//settery
void RegistrationRequest::setNazwaUzytkownika(const std::string &nowaNazwa)
{
	this->nazwaUzytkownika = nowaNazwa;
}

void RegistrationRequest::setHaslo(const std::string &noweHaslo)
{
	this->haslo = noweHaslo;
}

//konstruktory
RegistrationRequest::RegistrationRequest(std::string nazwa, std::string haslo)
{
	this->setId(REGISTRATION_REQUEST);
	this->setNazwaUzytkownika(nazwa);
	this->setHaslo(haslo);
}


RegistrationRequest::~RegistrationRequest()
{
}
