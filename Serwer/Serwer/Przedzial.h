#pragma once
#include <string>
class Przedzial
{
public:
	// pierwszy znak elementu
	std::string::iterator poczatek;
	// pozycja separatora ',' lub '#'
	std::string::iterator koniec;
	
	// konstruktory
	Przedzial();
	~Przedzial();
};

