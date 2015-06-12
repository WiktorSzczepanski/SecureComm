#pragma once
#include "../../Komunikaty/WszystkieKomunikaty.h"
#include "Parser.h"
class Deserializer
{
public:
	static SharedKomunikatPtr rozpoznajZeStringa(std::string &);

	Deserializer();
	~Deserializer();
};

