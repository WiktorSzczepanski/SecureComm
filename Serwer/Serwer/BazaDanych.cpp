#include "BazaDanych.h"

//operacje na calej bazie
bool BazaDanych::zapiszBaze()
{
	std::ofstream doPliku("Baza.udb");
	for (UserIterator it = this->userVector.begin(); it != this->userVector.end() + 1; it++)
	{
		doPliku << it->toDbString();
	}
	doPliku.close();
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
