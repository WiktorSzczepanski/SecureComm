#pragma once
#include "Przedzial.h"
#include <iostream>
//#include <string>
typedef std::string::iterator StringIterator;
class Parser
{
public:
	static void sprawdzCzyNiePusty(std::string &wejsciowy);
	static StringIterator znajdzSeparator(std::string &wejsciowy, const char separator);
	static std::string pierwszyWyraz(std::string &wejsciowy, const char separator);

	// konstruktory
	Parser();
	~Parser();
};

