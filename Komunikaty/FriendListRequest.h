#pragma once
#include "Komunikat.h"
class FriendListRequest :
	public Komunikat
{
	//idKomunikatu
	//idKomunikatu - dziedziczone z "Komunikat"
public:
	//serializacja
	std::string toString() const;

	//konstruktory
	FriendListRequest();
	~FriendListRequest();
};

