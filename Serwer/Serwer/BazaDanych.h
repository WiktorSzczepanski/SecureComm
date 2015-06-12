#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Parser.h"
#include "User.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
// typedef std::string::iterator StringIterator; jest w Users.h
// typedef std::vector<User>::iterator UserIterator; jest w User.h
class BazaDanych
{
private:
	unsigned int maxId; // najwyzsza wartosc ID sposrod uzytkownikow w bazie
	std::vector<User> userVector; // tu sa wczytywane wpisy z bazy i z tego sie kozysta podczas dzialania programu. przy zamykaniu z tad zapisuje sie do pliku

	//settery
	void setMaxId(unsigned int newMaxId);
	
	//operacje na calej bazie
	bool zapiszBaze(); // false gdy nie uda sie utworzys ofstreamu (np. problem z dostepem)
	bool wczytajBaze(); // false jesli brak pliku, lub jesli plik pusty. Wysypie sie jesli niepusty i brak '3' lub ',' na koncu.
	void inicjalizujBaze(); // tworzy zerowego uzytkownika id=0, nazwa=JohnDoe, haslo=haslo, data rejestracji=czas obecny
	unsigned int aktualizujMaxId();
public:
	//singleton
	static BazaDanych & getBazaDanych() // tym pobieramy instancje bazy. Wszelkie dzialaniana bazie maja postac typu: BazaDanych::getBazaDanych().metodaX();
	{
		static BazaDanych baza;
		return baza;
	}

	//gettery
	unsigned int getMaxId() const; // nowy uzytkownik powinien miec maxId + 1
	unsigned int getUserCount() const; // zwraca liczbe wpisow w bazie

	//operacje na uzytkownikach
	UserIterator wskazId(unsigned int id); //gdy nie ma zwraca iterator Usera "JohnDoe" o id=0
	UserIterator wskazNazwe(std::string nazwa); //gdy nie ma zwraca iterator Usera "JohnDoe" o id=0
	User wyszukajPoId(unsigned int id); //gdy nie ma zwraca Usera "JohnDoe" o id=0
	User wyszukajPoNazwie(std::string nazwa); //gdy nie ma zwraca Usera "JohnDoe" o id=0
	bool usunUsera(unsigned int id); // usuwa usera o podanym id. Zwraca true, gdy sukces. Zwraca falsz, gdy nie znajdzie lub gdy proba usuniecia usera o id=0;
	bool usunUsera(std::string nazwa); // jak wyzej, ale szukanie po zanwie. Uzytkownik o id=0 i nazwie JohnDoe nie moze byc usuniety
	// @TODO dodawanie usera bez podanego id. Baza sama przydzieli
	bool dodajUsera(User user); // dodaje uzytkownika czytajac dane z obiektu klasu User z User.h
	bool dodajUsera(unsigned int id, std::string nazwa, std::string haslo); // dodaje uzytkownika, ale bezposrednio przyjmuje dane
	bool dodajZnajomego(unsigned int komu, unsigned int kogo); // dodaje uzytkownikowi o id = komu do vektora przyjaciol uzytkownika o id = kogo
	bool usunZnajomego(unsigned int komu, unsigned int kogo); // usuwa uzytkownikowi o id = komu z vektora przyjaciol uzytkownika o id = kogo
	std::vector<unsigned int> dajListeZnajomych(unsigned int id); // zwraca kopie wekrora znajomych uzytkownika o podanym id
private:
	//konstruktory
	BazaDanych(); //probuje wczytac baze, jesli sie nie uda inicjalizuje nowa.
	BazaDanych(const BazaDanych &);
	~BazaDanych();
};
