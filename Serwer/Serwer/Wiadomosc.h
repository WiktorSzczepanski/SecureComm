#pragma once
#include "Komunikat.h"
class Wiadomosc :
	public Komunikat
{
	//idKomunikatu # idOdbiorcy # tresc
	//idKomunikatu - dziedziczone z "Komunikat"
private:
	UserId idOdbiorcy;
	std::string content;
public:
	//serializacja
	std::string toString() override;

	//gettery
	UserId getIdOdbiorcy();
	std::string getContent();

	//settery
	void setIdOdbiorcy(const UserId &nowyOdbiorca);
	void setContent(const std::string &nowyContent);

	//konstruktory
	Wiadomosc();
	Wiadomosc(const UserId &idOdbiorcy, const std::string &content);
	~Wiadomosc();
};

