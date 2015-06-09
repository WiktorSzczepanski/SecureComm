#include "LoginRequest.h"

//serializacja
std::string LoginRequest::toString() const
{
	std::string ramka;
	ramka = std::to_string(getId()) + '#' + getNazwaUzytkownika() + '#' + getHaslo();
	return ramka;
}

//gettery
std::string LoginRequest::getNazwaUzytkownika() const
{
	return this->nazwaUzytkownika;
}
std::string LoginRequest::getHaslo() const
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
