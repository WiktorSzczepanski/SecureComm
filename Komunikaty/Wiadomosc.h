#pragma once
#include "Komunikat.h"
class Wiadomosc :
	public Komunikat
{
	//idKomunikatu # idOdbiorcy # tresc
	//idKomunikatu - dziedziczone z "Komunikat"
private:
	std::string idOdbiorcy;
	std::string content;
public:
	//serializacja
	std::string toString() const;

	//gettery
	std::string getIdOdbiorcy() const;
	std::string getContent() const;

	//settery
	void setIdOdbiorcy(const std::string &nowyOdbiorca);
	void setContent(const std::string &nowyContent);

	//konstruktory
	Wiadomosc();
	Wiadomosc(const std::string &idOdbiorcy, const std::string &content);
	~Wiadomosc();
};

