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
void FriendSeek::setNazwaSzukanego(const std::string &nowySzukany)
{
	this->nazwaSzukanego = nowySzukany;
}

//konstruktory
FriendSeek::FriendSeek()
{
}


FriendSeek::~FriendSeek()
{
}
