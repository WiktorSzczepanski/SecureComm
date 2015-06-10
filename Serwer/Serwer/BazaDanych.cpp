#include "BazaDanych.h"

//settery
void BazaDanych::setMaxId(unsigned int newMaxId)
{
	this->maxId = newMaxId;
}

//operacje na calej bazie
bool BazaDanych::zapiszBaze()
{
	//w wyniku powstaje np. "1,Marian,haslo1234,2015,06,05,#" tyle, ¿e data wygl¹da inaczej, patrz std::tm
	std::ofstream doPliku("Baza.udb");
	if (doPliku)
	{
		UserIterator it = this->userVector.begin();
		for (UserIterator it = this->userVector.begin(); it < this->userVector.end(); it++)
		{
			doPliku << it->toDbString();
		}
	}
	else
	{
		return false;
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
void sprawdzCzyNiePusty(std::string &wejsciowy)
{
	try
	{
		if (wejsciowy.empty())	throw 1;
	}
	catch (...)
	{
		std::cout << "Wczytywanie nieudane. Nieoczekiwany koniec pliku.";
		exit(1);
	}
}
StringIterator znajdzSeparator(std::string &wejsciowy, const char separator)
{
	StringIterator it = wejsciowy.begin();
	while (*it != separator)
	{
		if (++it == wejsciowy.end())	break;
	}
	return it;
}
std::string pierwszyWyraz(std::string &wejsciowy, const char separator)
{
	sprawdzCzyNiePusty(wejsciowy);
	Przedzial przedzial;
	przedzial.poczatek = wejsciowy.begin();
	przedzial.koniec = znajdzSeparator(wejsciowy, separator);

	/*
	if (przedzial.poczatek == przedzial.koniec)
	{
		wejsciowy.erase(wejsciowy.begin());
		przedzial.poczatek = wejsciowy.begin();
		przedzial.koniec = znajdzSeparator(wejsciowy);
	}
	//*/

	std::string wynik = std::string(przedzial.poczatek, przedzial.koniec);
	wejsciowy.erase(przedzial.poczatek, przedzial.koniec+1); // tu sie wysypie, jesli napotka niespodziewany koniec pliku z zapisem bazy. Musi byc '#' na koncu. Powyzej mozna by wstawic try-catch.

	return wynik;
}
bool pierwszyUser(std::string &wejsciowy, User &wynik)
{
	if (wejsciowy.empty())	return false;
	
	std::string id = pierwszyWyraz(wejsciowy, ',');
	std::string nazwa = pierwszyWyraz(wejsciowy, ',');
	std::string haslo = pierwszyWyraz(wejsciowy, ',');
	std::string rok = pierwszyWyraz(wejsciowy, ',');
	std::string miesiac = pierwszyWyraz(wejsciowy, ',');
	std::string dzien = pierwszyWyraz(wejsciowy, ',');
	std::string znajomi = pierwszyWyraz(wejsciowy, '#');

	wynik = User(id, nazwa, haslo, rok, miesiac, dzien, znajomi);
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
			if (user.getId() > this->getMaxId())		this->setMaxId(user.getId()); //update maxId
		}
		if (this->getUserCount() == 0)	return false;
		return true;
	}
	else
	{
		return false;
	}
	zPliku.close();
}
/////////////////////////////////////////////////////////////////////////////////////////////
void BazaDanych::inicjalizujBaze()
{
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);

	User user(0, std::string("JohnDoe"), std::string("haslo"), *now, std::string("0"));
	this->userVector.push_back(user);

	this->setMaxId(0);
}
unsigned int BazaDanych::aktualizujMaxId()
{
	unsigned int newMaxId = 0;
	for (UserIterator it = this->userVector.begin(); it < this->userVector.end(); ++it)
	{
		if (newMaxId < it->getId())	newMaxId = it->getId();
	}
	this->maxId = newMaxId;
	return newMaxId;
}

//gettery
unsigned int BazaDanych::getMaxId() const
{
	return this->maxId;
}
unsigned int BazaDanych::getUserCount() const
{
	return this->userVector.size();
}

//operacje na uzytkownikach
UserIterator BazaDanych::wskazId(unsigned int id)
{
	// operacja User == int zwroci true, gdy user.id == int. Dlatego std::find tu dziala.
	UserIterator it = std::find(this->userVector.begin(), this->userVector.end(), id);
	if (it == this->userVector.end())		it = this->userVector.begin();//jeœli nie znalazl zwroci pierwszy element. std::find zwraca wtedy ostatni
	return it;
}
UserIterator BazaDanych::wskazNazwe(std::string nazwa)
{
	// operacja User == string zwroci true, gdy user.nazwa == string. Dlatego std::find tu dziala.
	UserIterator it = std::find(this->userVector.begin(), this->userVector.end(), nazwa);
	if (it == this->userVector.end())		it = this->userVector.begin();
	return it;
}
User BazaDanych::wyszukajPoId(unsigned int id)
{
	return *(wskazId(id));
}
User BazaDanych::wyszukajPoNazwie(std::string nazwa)
{
	return *(wskazNazwe(nazwa));
}
bool BazaDanych::usunUsera(unsigned int id)
{
	if (id == 0)	return false;//wprowadzono id=0, wskazujace na pierwszy wpis w bazie, ktorego nie mozna usuwac.
	UserIterator it = wskazId(id);//jesli nie znajdzie zwraca uzytkownika 0
	if (it->getId() == 0)		return false;//nie znaleziono podanego id
	this->userVector.erase(it);
	this->aktualizujMaxId();
	return true;
}
bool BazaDanych::usunUsera(std::string nazwa)
{
	if (nazwa == "JohnDoe")	return false;//wprowadzono nazwe zerowego uzytkownika, jest to pierwszy wpis w bazie, ktorego nie mozna usuwac.
	UserIterator it = wskazNazwe(nazwa);//jesli nie znajdzie zwraca uzytkownika 0
	if (it->getId() == 0)		return false;//nie znaleziono podanego id
	this->userVector.erase(it);
	this->aktualizujMaxId();
	return true;
}
bool BazaDanych::dodajUsera(User user)
{
	UserIterator it = wskazId(user.getId());//sprawdz, czy id unikalne
	if (it->getId() != 0)	return false;

	it = wskazNazwe(user.getNazwa());//sprawdz, czy nazwa unikalna
	if (it->getId() != 0)	return false; //to nie jest blad

	this->userVector.push_back(user);
	this->aktualizujMaxId();
	return true;
}
bool BazaDanych::dodajUsera(unsigned int id, std::string nazwa, std::string haslo)
{
	UserIterator it = wskazId(id);//sprawdz, czy id unikalne
	if (it->getId() != 0)	return false;

	it = wskazNazwe(nazwa);//sprawdz, czy nazwa unikalna
	if (it->getId() != 0)	return false; //to nie jest blad

	User nowyUser(id, nazwa, haslo);
	this->userVector.push_back(nowyUser);
	this->aktualizujMaxId();
	return true;
}
bool BazaDanych::dodajZnajomego(unsigned int komu, unsigned int kogo)
{
	UserIterator itKomu = wskazId(komu);
	UserIterator itKogo = wskazId(kogo);

	if (komu == 0 || kogo == 0)	return false;

	return itKomu->dodajZnajomego(*itKogo);
}
bool BazaDanych::usunZnajomego(unsigned int komu, unsigned int kogo)
{
	UserIterator itKomu = wskazId(komu);
	UserIterator itKogo = wskazId(kogo);

	if (komu == 0 || kogo == 0)	return false;

	return itKomu->usunZnajomego(*itKogo);
}
std::vector<unsigned int> BazaDanych::dajListeZnajomych(unsigned int id)
{
	UserIterator it = wskazId(id);

	return it->getZnajomi();
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
