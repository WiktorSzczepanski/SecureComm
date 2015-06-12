#pragma once
#include "Przedzial.h"
#include <iostream>
#include <memory>
//#include <string>
typedef std::string::iterator StringIterator;
class Parser
{
public:
	// rzuca wyjatek i zamyka program z wartoscia wyjscia: 1
	static void sprawdzCzyNiePusty(std::string &wejsciowy);
	
	// zwraca iterator na pierwszy od lewej znaleziony separator, podany w argumencie.
	// jesli nie znajdzie to zwraca wejsciowy.end().
	static StringIterator znajdzSeparator(std::string &wejsciowy, const char separator);
	
	// zwraca string bedacy podciagiem stringu wejsciowego i obcina poczatek wejsciowego. Jest to pierwszy wyraz, czyli znaki od poczatku do pierwszego separatora, bez samego separatora.
	// przy separatorze '#' i ciagu "marian#haslo#115#2" zwroci "marian" a ciag wejsciowy zostanie obciety do "haslo#115#2"
	static std::string pierwszyWyraz(std::string &wejsciowy, const char separator); 

	// konstruktory
	Parser();
	~Parser();
};

