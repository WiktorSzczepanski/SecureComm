#include "FriendSeek.h"

//serializacja
std::string FriendSeek::toString()
{
	std::string ramka;
	ramka = std::to_string(this->getId()) + "#" + this->getNazwaSzukanego();
	return ramka;
}
//gettery
std::string FriendSeek::getNazwaSzukanego()
{
	return this->nazwaSzukanego;
}

//settery
void FriendSeek::setNazwaSzukanego(const UserId nadawca, const std::string &nowySzukany)
{
	this->setIdNadawcy(nadawca);
	this->nazwaSzukanego = nowySzukany;
}

//konstruktory
FriendSeek::FriendSeek()
{
	this->setId(FRIEND_SEEK);
}


FriendSeek::~FriendSeek()
{
}
