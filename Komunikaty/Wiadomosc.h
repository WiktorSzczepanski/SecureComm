#pragma once
#include "Komunikat.h"
class Wiadomosc :
	public Komunikat
{
	//idKomunikatu # idNadawcy # idOdbiorcy # tresc
	//idKomunikatu - dziedziczone z "Komunikat"
private:
	UserId idOdbiorcy;
	std::string content;
public:
	//serializacja
	std::string toString() const override;

	//gettery
	UserId getIdOdbiorcy() const;
	std::string getContent() const;

	//settery
	void setIdOdbiorcy(const UserId &nowyOdbiorca);
	void setContent(const std::string &nowyContent);

	//konstruktory
	Wiadomosc();
	Wiadomosc(const UserId nadawca, const UserId &idOdbiorcy, const std::string &content);
	~Wiadomosc();
};

