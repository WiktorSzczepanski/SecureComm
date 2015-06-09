#pragma once
#include <string>
#include "Deklaracje.h"
//#include "../Serwer/Serwer/User.h"
class Komunikat
{
private:
	int id;
	UserId idNadawcy;
protected:
	//settery
	void setId(const int& newId);
public:
	//metoda do "serializacji" klasy do stringa.
	//Musi byc zaimplementowana w kazdej klasie pochodnej
	virtual std::string toString() const = 0;
	
	//settery
	void setIdNadawcy(UserId newId);

	//gettery
	int getId() const;
	UserId getIdNadawcy() const;

	//konstruktory
	Komunikat();
	virtual ~Komunikat();
};
