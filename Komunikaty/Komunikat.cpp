#include "Komunikat.h"

//gettery
int Komunikat::getId() const
{
	return id;
}
UserId Komunikat::getIdNadawcy() const
{
	return this->idNadawcy;
}

//settery
void Komunikat::setId(const int& newId)
{
	this->id = newId;
}
void Komunikat::setIdNadawcy(UserId newId)
{
	this->idNadawcy = newId;
}

//konstruktory
Komunikat::Komunikat()
{
}


Komunikat:: ~Komunikat()
{
}
