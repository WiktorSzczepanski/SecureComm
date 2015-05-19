#include "Wiadomosc.h"

//serializacja
std::string Wiadomosc::toString()
{
	std::string ramka;
	ramka = std::to_string(this->getId()) + "#" + std::to_string(this->getIdOdbiorcy()) + "#" + this->getContent();
	return ramka;
}

//gettery
UserId Wiadomosc::getIdOdbiorcy()
{
	return this->idOdbiorcy;
}

std::string Wiadomosc::getContent()
{
	return this->content;
}

//settery
void Wiadomosc::setIdOdbiorcy(const UserId &nowyOdbiorca)
{
	this->idOdbiorcy = nowyOdbiorca;
}

void Wiadomosc::setContent(const std::string &nowyContent)
{
	this->content = nowyContent;
}

//konstruktory
Wiadomosc::Wiadomosc()
{
	this->setId(WIADOMOSC);
}

Wiadomosc::Wiadomosc(const UserId &idOdbiorcy, const std::string &content)
{
	this->setId(WIADOMOSC);
	this->setIdOdbiorcy(idOdbiorcy);
	this->setContent(content);
}


Wiadomosc::~Wiadomosc()
{
}
