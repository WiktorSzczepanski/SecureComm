#include "RegistrationRequest.h"

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
void RegistrationRequest::setNazwaUzytkownika(std::string nowaNazwa)
{
	this->nazwaUzytkownika = nowaNazwa;
}

void RegistrationRequest::setHaslo(std::string noweHaslo)
{
	this->haslo = noweHaslo;
}

//konstruktory
RegistrationRequest::RegistrationRequest(const User &user)
{
	this->setId(REGISTRATION_REQUEST);
	this->setNazwaUzytkownika(user.getNazwa);
	this->setHaslo(user.getHaslo);
}


RegistrationRequest::~RegistrationRequest()
{
}
