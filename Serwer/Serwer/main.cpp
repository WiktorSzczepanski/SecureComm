#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BazaDanych.h"

using std::cout;
using std::endl;

int main()
{
	std::vector<unsigned int> wektor;
	wektor.push_back(0);
	ZnajomiIterator iter = wektor.begin();
	cout << "iter = " << *iter << endl;
	if (iter < wektor.end())	cout << "Mniejszy" << endl;

	cout << "MaxId = " << BazaDanych::getBazaDanych().getMaxId() << endl;

	//dodaje Stefana
	BazaDanych::getBazaDanych().dodajUsera(2, std::string("Stefan"), std::string("xoxoxo"));
	BazaDanych::getBazaDanych().dodajZnajomego(2, 1);

	cout << "MaxId = " << BazaDanych::getBazaDanych().getMaxId() << endl;

	BazaDanych::getBazaDanych().dodajZnajomego(1, 2);
	cout << BazaDanych::getBazaDanych().wyszukajPoId((*BazaDanych::getBazaDanych().wyszukajPoId(2).getZnajomi().begin())).toDbString() << endl;

	// usuwam i sprawdza, maxId
	BazaDanych::getBazaDanych().usunUsera(2);
	cout << BazaDanych::getBazaDanych().getMaxId() << endl;


	/*
	//BazaDanych mojaBaza = BazaDanych::getBazaDanych();
	//ZnajomiIterator it = BazaDanych::getBazaDanych().wyszukajPoId(0).getZnajomi().begin();
	User user = BazaDanych::getBazaDanych().wyszukajPoId(0);
	ZnajomiIterator it = user.getZnajomi().begin();
	std::vector<unsigned int> kumple = BazaDanych::getBazaDanych().wyszukajPoId(0).getZnajomi();
	cout << "Kumple.begin() = " << *kumple.begin() << endl;
	if (it < kumple.begin())	cout << "Tez mniejsze" << endl;
	cout << "it = " << *it << endl;
	//*/

	system("PAUSE");
	return 0;
}
