#pragma once
#include "Komunikat.h"
class LoginRequest :
	public Komunikat
{
	//idKomunikatu # nazwaUzytkownika # haslo
	//idKomunikatu - dziedziczone z "Komunikat"
private:
	std::string nazwaUzytkownika;
	std::string haslo;
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
	LoginRequest(std::string nazwa, std::string haslo);
	~LoginRequest();
};

