#ifndef SECURECOMM_LR_H
#define SECURECOMM_LR_H
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
	std::string toString() const;

	//gettery
	std::string getNazwaUzytkownika() const;
	std::string getHaslo() const;

	//settery
	void setNazwaUzytkownika(const std::string &nowaNazwa);
	void setHaslo(const std::string &noweHaslo);

	//konstruktory
	LoginRequest(std::string nazwa, std::string haslo);
	~LoginRequest();
};
#endif
