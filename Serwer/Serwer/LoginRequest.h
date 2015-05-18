#pragma once
#include "Komunikat.h"
class LoginRequest :
	public Komunikat
{
private:
	std::string nazwaUzytkownika;
	std::string haslo;
public:
	//gettery
	std::string getNazwaUzytkownika();
	std::string getHaslo();

	//settery
	void setNazwaUzytkownika(std::string nowaNazwa);
	void setHaslo(std::string noweHaslo);

	//konstruktory
	LoginRequest(std::string login, std::string haslo);
	~LoginRequest();
};

