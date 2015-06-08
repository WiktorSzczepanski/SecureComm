#include "WiadomoscPosrednia.h"


WiadomoscPosrednia::WiadomoscPosrednia(const UserId nadawca, const UserId &idOdbiorcy, const std::string &content)
{
	this->setIdNadawcy(nadawca);
	this->setId(WIAD_POSREDNIA);
	this->setIdOdbiorcy(idOdbiorcy);
	this->setContent(content);
}


WiadomoscPosrednia::~WiadomoscPosrednia()
{
}
