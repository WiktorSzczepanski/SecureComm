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
	Komunikat();
	~Komunikat();
	int getId();
};
