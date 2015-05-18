#pragma once
#include "Komunikat.h"
class RegistrationRequest :
	public Komunikat
{
private:
	//wybrana nazwa uzytkownika
	std::string nazwaUzytkownika;

	//haslo do logowania do klienta
	std::string haslo; //@TODO moze nie string i plain text?
public:
	//idKomunikatu # nazwaUzytkownika # haslo
	//idKomunikatu - dziedziczone z "Komunikat"
	
	//gettery
	std::string getNazwaUzytkownika();
	std::string getHaslo();

	//settery
	void setNazwaUzytkownika(std::string nowaNazwa);
	void setHaslo(std::string noweHaslo);

	//konstruktory
	RegistrationRequest(const User &user);
	~RegistrationRequest();
};

