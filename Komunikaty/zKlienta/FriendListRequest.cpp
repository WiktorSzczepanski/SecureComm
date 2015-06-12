#include "FriendListRequest.h"

//serializacja
std::string FriendListRequest::toString() const
{
	std::string ramka;
	ramka = std::to_string(this->getId());
	return ramka;
}

//konstruktory

FriendListRequest::FriendListRequest(const UserId nadawca)
{
	this->setIdNadawcy(nadawca);
	this->setId(FRIEND_LIST_REQUEST);
}
FriendListRequest::FriendListRequest(const FriendListRequest &komunikat)
{
	this->setId(FRIEND_LIST_REQUEST);
	this->setIdNadawcy(komunikat.getIdNadawcy());
}

FriendListRequest::~FriendListRequest()
{
}
