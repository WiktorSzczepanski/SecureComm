#pragma once
#include "Komunikat.h"
class FriendAdd :
	public Komunikat
{
	//idKomunikatu # idDodawanego
	//idKomunikatu - dziedziczone z "Komunikat"
private:
	std::string idDodawanego;
public:
	//serializacja
	std::string toString() const;

	//gettery
	std::string getIdDodawanego() const;

	//settery
	void setIdDodawanego(const std::string nowyDodawany);

	//konstruktory
	FriendAdd(const std::string nowyDodawany);
	~FriendAdd();
};

