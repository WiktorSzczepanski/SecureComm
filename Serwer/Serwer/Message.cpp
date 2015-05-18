#include "Message.h"

//gettery
int Message::getIdOdbiorcy()
{
	return this->idOdbiorcy;
}

std::string Message::getContent()
{
	return this->content;
}

//settery
void Message::setIdOdbiorcy(const int &nowyOdbiorca)
{
	this->idOdbiorcy = nowyOdbiorca;
}

void Message::setContent(const std::string &nowyContent)
{
	this->content = nowyContent;
}

//konstruktory
Message::Message(const std::string &content)
{
	this->setId(MESSAGE);
	this->content = content;
}


Message::~Message()
{
}
