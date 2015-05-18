#pragma once
#include "Komunikat.h"
class RegistrationRequest :
	public Komunikat
{
	//idKomunikatu # nazwaUzytkownika # haslo
	//idKomunikatu - dziedziczone z "Komunikat"
private:
	//wybrana nazwa uzytkownika
	std::string nazwaUzytkownika;

	//haslo do logowania do klienta
	std::string haslo; //@TODO moze nie string i plain text?
public:
	//serializacja
	std::string toString() override;

	//gettery
	std::string getNazwaUzytkownika();
	std::string getHaslo();

	//settery
	void setNazwaUzytkownika(const std::string &nowaNazwa);
	void setHaslo(const std::string &noweHaslo);

	//konstruktory
	RegistrationRequest(User &user);
	~RegistrationRequest();
};

