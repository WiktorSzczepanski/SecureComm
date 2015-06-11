#include "WiadomoscPosrednia.h"


WiadomoscPosrednia::WiadomoscPosrednia(const UserId nadawca, const UserId &idOdbiorcy, const std::string &content)
{
	this->setId(WIAD_POSREDNIA);
	this->setIdNadawcy(nadawca);
	this->setIdOdbiorcy(idOdbiorcy);
	this->setContent(content);
}
WiadomoscPosrednia::WiadomoscPosrednia(const WiadomoscPosrednia &komunikat)
{
	this->setId(WIAD_POSREDNIA);
	this->setIdNadawcy(komunikat.getIdNadawcy());
	this->setIdOdbiorcy(komunikat.getIdOdbiorcy());
	this->setContent(komunikat.getContent());
}

WiadomoscPosrednia::~WiadomoscPosrednia()
{
}
