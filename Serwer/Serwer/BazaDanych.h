#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "User.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
typedef std::vector<User>::iterator UserIterator;
typedef std::string::iterator StringIterator;
class BazaDanych
{
private:
	unsigned int maxId;
	std::vector<User> userVector;

	//settery
	void setMaxId(unsigned int newMaxId);
public:
	//singleton
	static BazaDanych & getBazaDanych()
	{
		static BazaDanych baza;
		return baza;
	}

	//operacje na calej bazie
	bool zapiszBaze(); // false gdy nie uda sie utworzys ofstreamu (np. problem z dostepem)
	bool wczytajBaze(); // false jesli brak pliku, lub jesli plik pusty. Wysypie sie jesli niepusty i brak '3' lub ',' na koncu.
	void inicjalizujBaze();

	//gettery
	unsigned int getMaxId() const;
	unsigned int getUserCount() const;

	//operacje na uzytkownikach
	UserIterator wskazId(unsigned int id); //gdy nie ma zwraca iterator Usera "JohnDoe" o id=0
	UserIterator wskazNazwe(std::string nazwa); //gdy nie ma zwraca iterator Usera "JohnDoe" o id=0
	User wyszukajPoId(unsigned int id); //gdy nie ma zwraca Usera "JohnDoe" o id=0
	User wyszukajPoNazwie(std::string nazwa); //gdy nie ma zwraca Usera "JohnDoe" o id=0
	bool usunUsera(unsigned int id);
	bool usunUsera(std::string nazwa);
	bool dodajUsera(User user);
	bool dodajUsera(unsigned int id, std::string nazwa, std::string haslo);
private:
	//konstruktory
	BazaDanych(); //probuje wczytac baze, jesli sie nie uda inicjalizuje nowa.
	BazaDanych(const BazaDanych &);
	~BazaDanych();
};
