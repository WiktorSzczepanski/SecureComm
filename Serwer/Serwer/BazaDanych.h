#pragma once
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include "User.h"
typedef std::vector<User>::iterator UserIterator;
typedef std::string::iterator StringIterator;
class BazaDanych
{
private:
	unsigned int maxId;
	std::vector<User> userVector;
public:
	//operacje na calej bazie
	bool zapiszBaze();
	bool wczytajBaze();
	bool inicjalizujBaze();

	//operacje na uzytkownikach
	User wyszukajPoId(unsigned int id); //gdy nie ma zwraca Usera "John Doe" o id=0
	User wyszukajPoNazwie(std::string nazwa); //gdy nie ma zwraca Usera "John Doe" o id=0
	bool usunUsera(unsigned int id);
	User dodajUsera(User user);

	//konstruktory
	BazaDanych();
	~BazaDanych();
};

