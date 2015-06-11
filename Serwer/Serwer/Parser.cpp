#include "Parser.h"

void Parser::sprawdzCzyNiePusty(std::string &wejsciowy)
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
StringIterator Parser::znajdzSeparator(std::string &wejsciowy, const char separator)
{
	StringIterator it = wejsciowy.begin();
	while (*it != separator)
	{
		if (++it == wejsciowy.end())	break;
	}
	return it;
}
std::string Parser::pierwszyWyraz(std::string &wejsciowy, const char separator)
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
	wejsciowy.erase(przedzial.poczatek, przedzial.koniec + 1); // tu sie wysypie, jesli napotka niespodziewany koniec pliku z zapisem bazy. Musi byc '#' na koncu. Powyzej mozna by wstawic try-catch.

	return wynik;
}

Parser::Parser()
{
}


Parser::~Parser()
{
}
