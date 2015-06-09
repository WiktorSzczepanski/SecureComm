#include "FriendAdd.h"

//serializacja
std::string FriendAdd::toString() const
{
	std::string ramka;
	ramka = std::to_string(this->getId()) + '#' + this->getIdDodawanego();
	return ramka;
}

//gettery
std::string FriendAdd::getIdDodawanego() const
{
	return this->idDodawanego;
}

//settery
void FriendAdd::setIdDodawanego(const std::string nowyDodawany)
{
	this->idDodawanego = nowyDodawany;
}

//konstruktory
FriendAdd::FriendAdd(const std::string nowyDodawany)
{
	this->setId(FRIEND_ADD);
	this->setIdDodawanego(nowyDodawany);
}


FriendAdd::~FriendAdd()
{
}
