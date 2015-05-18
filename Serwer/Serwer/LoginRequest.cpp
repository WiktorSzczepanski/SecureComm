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
void LoginRequest::setNazwaUzytkownika(std::string nowaNazwa)
{
	this->nazwaUzytkownika = nowaNazwa;
}
void LoginRequest::setHaslo(std::string noweHaslo)
{
	this->haslo = noweHaslo;
}

//konstruktory
LoginRequest::LoginRequest(std::string login, std::string haslo)
{
}


LoginRequest::~LoginRequest()
{
}
