#pragma once
enum rodzajKomunikatu
{
	REGISTRATION_REQUEST = 0,
	LOGIN_REQUEST = 1,
	WIADOMOSC = 2,
	WIAD_POSREDNIA = 3,
	FRIEND_SEEK = 4,
	FRIEND_ADD = 5,
	ZAPYTANIE_DOSTEPNOSC = 6,
	FRIEND_LIST_REQUEST = 7,
	LOGOUT = 8
};

typedef unsigned int UserId;

