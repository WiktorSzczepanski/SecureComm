#include "FriendAdd.h"

//serializacja
std::string FriendAdd::toString()
{
	std::string ramka;
	ramka = std::to_string(this->getId()) + '#' + std::to_string(this->getIdDodawanego());
	return ramka;
}

//gettery
UserId FriendAdd::getIdDodawanego()
{
	return this->idDodawanego;
}

//settery
void FriendAdd::setIdDodawanego(const UserId &nowyDodawany)
{
	this->idDodawanego = nowyDodawany;
}

//konstruktory
FriendAdd::FriendAdd(const UserId nadawca, const UserId &nowyDodawany)
{
	this->setId(FRIEND_ADD);
	this->setIdNadawcy(nadawca);
	this->setIdDodawanego(nowyDodawany);
}


FriendAdd::~FriendAdd()
{
}
