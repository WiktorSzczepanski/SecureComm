#pragma once
#include "Deklaracje.h"
#include "User.h"
class Komunikat
{
private:
	int id;
protected:
	void setId(const int& newId);
public:
	//metoda do "serializacji" klasy do stringa.
	//Musi byc zaimplementowana w kazdej klasie pochodnej
	virtual std::string toString() = 0;
	//konstruktory
	Komunikat();
	virtual ~Komunikat();
	int getId();
};
