#pragma once
#include "Wiadomosc.h"
class WiadomoscPosrednia :
	public Wiadomosc
{
	//idKomunikatu # idOdbiorcy # tresc
	//idKomunikatu - dziedziczone z "Komunikat"
	//od wiadomosci rozni sie tylko identyfikatorem
public:
	WiadomoscPosrednia(const WiadomoscPosrednia &);
	WiadomoscPosrednia(const UserId nadawca, const UserId &idOdbiorcy, const std::string &content);
	~WiadomoscPosrednia();
};

