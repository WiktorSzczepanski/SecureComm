#include "WiadomoscPosrednia.h"


WiadomoscPosrednia::WiadomoscPosrednia(const std::string &idOdbiorcy, const std::string &content)
{
	this->setId(WIAD_POSREDNIA);
	this->setIdOdbiorcy(idOdbiorcy);
	this->setContent(content);
}


WiadomoscPosrednia::~WiadomoscPosrednia()
{
}
