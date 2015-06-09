#pragma once
#include "../Komunikat.h"
class FriendAdd :
	public Komunikat
{
	//idKomunikatu # idDodawanego
	//idKomunikatu - dziedziczone z "Komunikat"
private:
	UserId idDodawanego;
public:
	//serializacja
	std::string toString() override;

	//gettery
	UserId getIdDodawanego();

	//settery
	void setIdDodawanego(const UserId &nowyDodawany);

	//konstruktory
	FriendAdd(const UserId nadawca, const UserId &nowyDodawany);
	~FriendAdd();
};
