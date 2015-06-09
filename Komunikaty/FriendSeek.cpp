#include "FriendSeek.h"

//serializacja
std::string FriendSeek::toString() const
{
	std::string ramka;
	ramka = std::to_string(this->getId()) + "#" + this->getNazwaSzukanego();
	return ramka;
}
//gettery
std::string FriendSeek::getNazwaSzukanego() const
{
	return this->nazwaSzukanego;
}

//settery
void FriendSeek::setNazwaSzukanego(const std::string &nowySzukany)
{
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
