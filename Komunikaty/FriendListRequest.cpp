#include "FriendListRequest.h"

//serializacja
std::string FriendListRequest::toString() const
{
	std::string ramka;
	ramka = std::to_string(this->getId());
	return ramka;
}

//konstruktory

FriendListRequest::FriendListRequest()
{
	this->setId(FRIEND_LIST_REQUEST);
}


FriendListRequest::~FriendListRequest()
{
}
