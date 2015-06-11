#include "RegistrationConfirmation.h"

// settery
void RegistrationConfirmation::setUserId(UserId newId)
{
	this->userId = newId;
}
void RegistrationConfirmation::setNazwaUzytkownika(std::string nazwa)
{
	this->nazwaUzytkownika = nazwa;
}
void RegistrationConfirmation::setHaslo(std::string haslo)
{
	this->haslo = haslo;
}

// serializacja
std::string RegistrationConfirmation::toString() const
{
	std::string ramka;
	ramka = std::to_string(this->getId()) + '#' +
		std::to_string(this->getUserId()) + '#' +
		this->getNazwaUzytkownika() + '#' + 
		this->getHaslo();
	return ramka;
}

// gettery
UserId RegistrationConfirmation::getUserId() const
{
	return this->userId;
}
std::string RegistrationConfirmation::getNazwaUzytkownika() const
{
	return this->nazwaUzytkownika;
}
std::string RegistrationConfirmation::getHaslo() const
{
	return this->haslo;
}

// konstruktory
RegistrationConfirmation::RegistrationConfirmation(const UserId userId, std::string nazwa, std::string haslo)
{
	this->setId(REGISTRATION_CONFIRMATION);
	this->setIdNadawcy(userId);
	this->setNazwaUzytkownika(nazwa);
	this->setHaslo(haslo);
}
RegistrationConfirmation::RegistrationConfirmation(const RegistrationConfirmation &komunikat)
{
	this->setId(REGISTRATION_CONFIRMATION);
	this->setIdNadawcy(komunikat.getUserId());
	this->setNazwaUzytkownika(komunikat.getNazwaUzytkownika());
	this->setHaslo(komunikat.getHaslo());
}

RegistrationConfirmation::~RegistrationConfirmation()
{
}


