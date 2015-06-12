#include <iostream>
//#include "Deserializer.h"
#include "BazaDanych.h"

using std::cout;
using std::endl;

int main()
{
	cout << "Najwieksze id w bazie: " << BazaDanych::getBazaDanych().getMaxId() << endl
		<< "Liczba uzytkownikow w bazie: " << BazaDanych::getBazaDanych().getUserCount() << endl
		<< "Uzytkownik o najwiekszym id w bazie: " << endl;
	int maxid = BazaDanych::getBazaDanych().getMaxId();
	User najstarszy = BazaDanych::getBazaDanych().wyszukajPoId(maxid);
	cout << "    id: " << najstarszy.getId() << endl
		<< "    nazwa: " << najstarszy.getNazwa() << endl
		<< "    haslo: " << najstarszy.getHaslo() << endl
		<< "    pierwszy znajomy: " << BazaDanych::getBazaDanych().wyszukajPoId(*najstarszy.getZnajomi().begin()).getNazwa() << endl;

	cout << endl << "Dodanie uzytkownikow" << endl;
	BazaDanych::getBazaDanych().dodajUsera(1, std::string("Marian"), std::string("has1234lo"));
	BazaDanych::getBazaDanych().dodajUsera(2, std::string("Stefan"), std::string("xaxaxaxa"));
	BazaDanych::getBazaDanych().dodajUsera(3, std::string("Juliusz"), std::string("iTyBrutusie..."));
	cout << "Liczba uzytkownikow: " << BazaDanych::getBazaDanych().getUserCount() << endl;
	User marian = BazaDanych::getBazaDanych().wyszukajPoId(1);
	User stefan = BazaDanych::getBazaDanych().wyszukajPoNazwie(std::string("Stefan"));
	User juliusz = BazaDanych::getBazaDanych().wyszukajPoId(3);
	cout << "Dodani uzytkownicy" << endl 
		<< "(zserializowani, jak do zapisu bazy, dla oszczednosci miejsca)" << endl
		<< marian.toDbString() << endl
		<< stefan.toDbString() << endl
		<< juliusz.toDbString() << endl;

	cout << endl << "Usuniecie uzytkownika" << endl;
	BazaDanych::getBazaDanych().usunUsera(std::string("Juliusz")); // dodawanie i usuwanie jest po id lub po nazwie
	juliusz = BazaDanych::getBazaDanych().wyszukajPoNazwie(std::string("Juliusz")); // wyszukanie zwraca kopie uzytkownika z bazy. 
																					// Jesli nie znajdzie zwraca kopie uzytkownika 0
	cout << "Liczba uzytkownikow w bazie: " << BazaDanych::getBazaDanych().getUserCount() << endl;
	cout << "Uzytkownik bedacy wynikiem wyszukiwania usunietego uzytkownika:" << endl
		<< juliusz.toDbString() << endl;

	cout << endl << "Dodanie znajomego" << endl;
	BazaDanych::getBazaDanych().dodajZnajomego(2, 1);
	stefan = BazaDanych::getBazaDanych().wyszukajPoId(2);
	cout << "uzytkownik: " << stefan.toDbString() << endl
		<< "ma teraz za znajomego: " << BazaDanych::getBazaDanych().wyszukajPoId(*stefan.getZnajomi().begin()).toDbString() << endl;

	system("PAUSE");
	return 0;
}
