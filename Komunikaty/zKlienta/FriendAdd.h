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
	std::string toString() const override;

	//gettery
	UserId getIdDodawanego() const;

	//settery
	void setIdDodawanego(const UserId &nowyDodawany);

	//konstruktory
	FriendAdd(const UserId nadawca, const UserId &nowyDodawany);
	~FriendAdd();
};
