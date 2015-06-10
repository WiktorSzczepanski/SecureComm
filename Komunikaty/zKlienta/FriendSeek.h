#pragma once
#include "../Komunikat.h"
class FriendSeek :
	public Komunikat
{
	//idKomunikatu # idNadawcy # nazwaSzukanego
	//idKomunikatu - dziedziczone z "Komunikat"
private:
	std::string nazwaSzukanego;
public:
	//serializacja
	std::string toString() const override;
	//gettery
	std::string getNazwaSzukanego() const;
	//settery
	void setNazwaSzukanego(const UserId nadawca, const std::string &nowySzukany);
	//konstruktory
	FriendSeek();
	~FriendSeek();
};

