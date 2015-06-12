#pragma once
// komunikaty o id < 0 s¹ komunikatami wychodzacymi z Serwera. Te o id >= 0 wychodza z Klienta.
enum rodzajKomunikatu
{
	PING = -11,
	FRIEND_LIST_REQUEST_RESPONSE = -10,
	ZAPYTANIE_DOSTEPNOSC_ODPOWIEDZ = -9,
	FRIEND_ADD_FAILURE = -8,
	FRIEND_ADD_SUCCES = -7,
	FRIEND_SEEK_FAILURE = -6,
	FRIEND_SEEK_SUCCES = -5,
	LOGIN_DENIAL = -4,
	LOGIN_CONFIRMATION = -3,
	REGISTRATION_DENIAL = -2,
	REGISTRATION_CONFIRMATION = -1,
	REGISTRATION_REQUEST = 0,
	LOGIN_REQUEST = 1,
	WIADOMOSC = 2,
	WIAD_POSREDNIA = 3,
	FRIEND_SEEK = 4,
	FRIEND_ID_SEEK = 5,
	FRIEND_ADD = 6,
	ZAPYTANIE_DOSTEPNOSC = 7,
	FRIEND_LIST_REQUEST = 8,
	LOGOUT = 9,
	PING_RESPONSE = 10
};

typedef unsigned int UserId;
class Komunikat;
typedef std::shared_ptr<Komunikat> SharedKomunikatPtr;
