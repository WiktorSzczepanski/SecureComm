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
	std::string toString() const;

	//gettery
	std::string getNazwaUzytkownika() const;
	std::string getHaslo() const;

	//settery
	void setNazwaUzytkownika(const std::string &nowaNazwa);
	void setHaslo(const std::string &noweHaslo);

	//konstruktory
	RegistrationRequest(const std::string nazwa,const std::string haslo);
	~RegistrationRequest();
};

