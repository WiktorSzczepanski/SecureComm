#include "Komunikat.h"


Komunikat::Komunikat()
{
}


Komunikat:: ~Komunikat()
{
}

int Komunikat::getId()
{
	return id;
}

void Komunikat::setId(const int& newId)
{
	this->id = newId;
}
