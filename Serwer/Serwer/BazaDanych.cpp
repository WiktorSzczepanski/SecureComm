#include "BazaDanych.h"

//operacje na calej bazie
bool BazaDanych::zapiszBaze()
{
	//w wyniku powstaje np. "1,Marian,haslo1234,2015,06,05#" tyle, ¿e data wygl¹da inaczej, patrz std::tm
	std::ofstream doPliku("Baza.udb");
	for (UserIterator it = this->userVector.begin(); it != this->userVector.end() + 1; it++)
	{
		doPliku << it->toDbString();
	}
	doPliku.close();

	return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////
class Przedzial
{
public:
	//pierwszy znak elementu
	std::string::iterator poczatek;
	//pozycja separatora ',' lub '#'
	std::string::iterator koniec;
};

StringIterator znajdzSeparator(std::string &wejsciowy)
{
	StringIterator it = wejsciowy.begin();
	while (*it != ',' || *it != '#')
	{
		it++;
	}
	return it;
}

void sprawdzCzyNiePusty(std::string &wejsciowy)
{
	try
	{
		if (wejsciowy.empty())	throw 1;
	}
	catch (int e)
	{
		std::cout << "Wczytywanie nieudane. Nieoczekiwany koniec pliku.";
		exit(1);
	}
}

std::string pierwszyWyraz(std::string &wejsciowy)
{
	sprawdzCzyNiePusty(wejsciowy);
	Przedzial przedzial;
	przedzial.poczatek = wejsciowy.begin();
	przedzial.koniec = znajdzSeparator(wejsciowy);

	std::string wynik = std::string(przedzial.poczatek, przedzial.koniec);
	wejsciowy.erase(przedzial.poczatek, przedzial.koniec);

	return wynik;
}

bool pierwszyUser(std::string &wejsciowy, User &wynik)
{
	if (wejsciowy.empty())	return false;
	
	std::string id = pierwszyWyraz(wejsciowy);
	std::string nazwa = pierwszyWyraz(wejsciowy);
	std::string haslo = pierwszyWyraz(wejsciowy);
	std::string rok = pierwszyWyraz(wejsciowy);
	std::string miesiac = pierwszyWyraz(wejsciowy);
	std::string dzien = pierwszyWyraz(wejsciowy);

	wynik = User(id, nazwa, haslo, rok, miesiac, dzien);
	return true;
}

bool BazaDanych::wczytajBaze()
{
	std::ifstream zPliku("Baza.udb");
	if (zPliku)
	{
		std::string zawartoscPliku;
		zPliku >> zawartoscPliku;
		
		User user;
		while (pierwszyUser(zawartoscPliku, user))
		{
			userVector.push_back(user);
		}

		return true;
	}
	else
	{
		return false;
	}
	zPliku.close();
}
/////////////////////////////////////////////////////////////////////////////////////////////
bool BazaDanych::inicjalizujBaze()
{
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);

	User user(0, std::string("John Doe"), std::string("haslo"), *now);
	this->userVector.push_back(user);
}

//konstruktory
BazaDanych::BazaDanych()
{
	if (this->wczytajBaze() == false)
	{
		this->inicjalizujBaze();
	}
}


BazaDanych::~BazaDanych()
{
	this->zapiszBaze();
}
