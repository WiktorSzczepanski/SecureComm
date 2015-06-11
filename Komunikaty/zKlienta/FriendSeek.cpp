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
void FriendSeek::setNazwaSzukanego(const std::string nowySzukany)
{
	this->nazwaSzukanego = nowySzukany;
}

//konstruktory
FriendSeek::FriendSeek(const UserId nadawca, const std::string nowySzukany)
{
	this->setId(FRIEND_SEEK);
	this->setIdNadawcy(nadawca);
	this->setNazwaSzukanego(nowySzukany);
}
FriendSeek::FriendSeek(const FriendSeek &komunikat)
{
	this->setId(FRIEND_SEEK);
	this->setIdNadawcy(komunikat.getIdNadawcy());
	this->setNazwaSzukanego(komunikat.getNazwaSzukanego());
}

FriendSeek::~FriendSeek()
{
}
