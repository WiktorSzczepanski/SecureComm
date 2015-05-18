#include "LoginRequest.h"

//gettery
std::string LoginRequest::getNazwaUzytkownika()
{
	return this->nazwaUzytkownika;
}
std::string LoginRequest::getHaslo()
{
	return this->haslo;
}

//settery
void LoginRequest::setNazwaUzytkownika(const std::string &nowaNazwa)
{
	this->nazwaUzytkownika = nowaNazwa;
}
void LoginRequest::setHaslo(const std::string &noweHaslo)
{
	this->haslo = noweHaslo;
}

//konstruktory
LoginRequest::LoginRequest(std::string nazwa, std::string haslo)
{
	this->setId(LOGIN_REQUEST);
	this->setNazwaUzytkownika(nazwa);
	this->setHaslo(haslo);
}


LoginRequest::~LoginRequest()
{
}
