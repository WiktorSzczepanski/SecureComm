#define _CRT_SECURE_NO_WARNINGS
#include "BazaDanych.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
//#include <time.h>

bool pierwszy = false;
using std::endl;
using std::cout;

int main()
{
	//cout << BazaDanych::getBazaDanych().getMaxId() << endl;
	User user1 = BazaDanych::getBazaDanych().wyszukajPoId(0);
	User user2 = BazaDanych::getBazaDanych().wyszukajPoId(1);
	cout << "user1: " << user1.getId() << endl
		<< user1.getNazwa() << endl
		<< user1.getHaslo() << endl << endl;
	cout << "user2: " << user2.getId() << endl
		<< user2.getNazwa() << endl
		<< user2.getHaslo() << endl << endl;

	cout << "Liczba uzytkownikow: " << BazaDanych::getBazaDanych().getUserCount() << endl;
	
	cout << endl << "Dodanie nowego uzytkownika" << endl;
	User user(1, "Marian", "haslo123");
	BazaDanych::getBazaDanych().dodajUsera(user);

	user1 = BazaDanych::getBazaDanych().wyszukajPoId(0);
	user2 = BazaDanych::getBazaDanych().wyszukajPoId(1);
	cout << "user1: " << user1.getId() << endl
		<< user1.getNazwa() << endl
		<< user1.getHaslo() << endl << endl;
	cout << "user2: " << user2.getId() << endl
		<< user2.getNazwa() << endl
		<< user2.getHaslo() << endl << endl;

	cout << "Liczba uzytkownikow: " << BazaDanych::getBazaDanych().getUserCount() << endl;
		
	cout << endl << "Usuniecie uzytkownika" << endl;
	BazaDanych::getBazaDanych().usunUsera(1);

	user1 = BazaDanych::getBazaDanych().wyszukajPoId(0);
	user2 = BazaDanych::getBazaDanych().wyszukajPoId(1);
	cout << "user1: " << user1.getId() << endl
		<< user1.getNazwa() << endl
		<< user1.getHaslo() << endl << endl;
	cout << "user2: " << user2.getId() << endl
		<< user2.getNazwa() << endl
		<< user2.getHaslo() << endl << endl;

	cout << "Liczba uzytkownikow: " << BazaDanych::getBazaDanych().getUserCount() << endl;
	/*
	std::string string("0,JohnDoe,haslo,115,5,8#");
	std::string::iterator it = string.begin();
	cout << "*it: " << *it << endl;
	if (*it == '0')	cout << "*it == 0" << endl;
	else cout << "*it != 0" << endl;

	std::string pomocniczy;
	while (*it != ',' && *it != '#')
	{
		pomocniczy += *it;
		it++;
	}
	cout << pomocniczy << endl;
	//*/

	system("PAUSE");
	return 0;
}
