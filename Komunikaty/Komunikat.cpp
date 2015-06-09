#include "Komunikat.h"


Komunikat::Komunikat()
{
}


Komunikat:: ~Komunikat()
{
}

int Komunikat::getId() const
{
	return id;
}

void Komunikat::setId(const int& newId)
{
	this->id = newId;
}
