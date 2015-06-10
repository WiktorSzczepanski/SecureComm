#pragma once
#include "C:\Home\GitLocalRepo\SecureComm\Komunikaty\Komunikat.h"
class RegistrationConfirmation :
	public Komunikat
{
	//idKomunikatu # idUzytkownika # nazwaUzytkownika # haslo
	//idKomunikatu - dziedziczone z "Komunikat"
private:
	UserId userId;
	std::string nazwaUzytkownika;
	std::string haslo;
	
	// settery
	void setUserId(UserId newId);
	void setNazwaUzytkownika(std::string nazwa);
	void setHaslo(std::string haslo);
public:
	// serializacja
	std::string toString() const override;

	// gettery
	UserId getUserId() const;
	std::string getNazwaUzytkownika() const;
	std::string getHaslo() const;

	// konstruktory
	RegistrationConfirmation(const UserId userId, std::string nazwa, std::string haslo);
	~RegistrationConfirmation();
};

