#include "User.h"


User::User(std::string nazwa, std::tm dataRejestracji)
{
	this->nazwa = nazwa;
	this->dataOstatniegoLogowania = dataOstatniegoLogowania;
}


User::~User()
{
}
