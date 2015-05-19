#pragma once
#include "Komunikat.h"
class FriendSeek :
	public Komunikat
{
	//idKomunikatu # nazwaSzukanego
	//idKomunikatu - dziedziczone z "Komunikat"
private:
	std::string nazwaSzukanego;
public:
	//serializacja
	std::string toString() override;
	//gettery
	std::string getNazwaSzukanego();
	//settery
	void setNazwaSzukanego(const std::string &nowySzukany);
	//konstruktory
	FriendSeek();
	~FriendSeek();
};

