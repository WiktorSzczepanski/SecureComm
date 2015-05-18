#pragma once
enum rodzajKomunikatu
{
	REGISTRATION_REQUEST = 0,
	LOGIN_REQUEST = 1,
	WIADOMOSC = 2,
	WIAD_POSREDNIA = 3,
	FRIEND_SEEK = 4
};

typedef unsigned int UserId;