#pragma once
#include "Komunikat.h"
class Message :
	public Komunikat
{
private:
	unsigned int idOdbiorcy;
	std::string content;
public:
	//gettery
	int getIdOdbiorcy();
	std::string getContent();

	//settery
	void setIdOdbiorcy(const int &nowyOdbiorca);
	void setContent(const std::string &nowyContent);

	//konstruktory
	Message(const std::string &content);
	~Message();
};

