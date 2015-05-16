#pragma once
#include "Komunikat.h"
class RegistrationRequest :
	public Komunikat
{
public:
	RegistrationRequest(const User &user);
	~RegistrationRequest();
};

