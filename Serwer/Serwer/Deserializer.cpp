#include "Deserializer.h"


Deserializer::Deserializer()
{
}


Deserializer::~Deserializer()
{
}

// deserializacja
SharedKomunikatPtr Deserializer::rozpoznajZeStringa(std::string &wejsciowy)
{
	int id = std::stoi(Parser::pierwszyWyraz(wejsciowy, '#'));
	SharedKomunikatPtr wynik;

	switch (id)
	{
	case PING:

		break;
	case FRIEND_LIST_REQUEST_RESPONSE:

		break;
	case ZAPYTANIE_DOSTEPNOSC_ODPOWIEDZ:

		break;
	case FRIEND_ADD_FAILURE:

		break;
	case FRIEND_ADD_SUCCES:

		break;
	case FRIEND_SEEK_FAILURE:

		break;
	case FRIEND_SEEK_SUCCES:

		break;
	case LOGIN_DENIAL:

		break;
	case LOGIN_CONFIRMATION:

		break;
	case REGISTRATION_DENIAL:

		break;
	case REGISTRATION_CONFIRMATION:

		break;
	case REGISTRATION_REQUEST:
	{
		// 0
		std::shared_ptr<RegistrationRequest> regPtr;
		regPtr = std::make_shared<RegistrationRequest>(wejsciowy);
		wynik = std::dynamic_pointer_cast<Komunikat>(regPtr);
		break;
	}
	case LOGIN_REQUEST:

		break;
	case WIADOMOSC:

		break;
	case WIAD_POSREDNIA:

		break;
	case FRIEND_SEEK:

		break;
	case FRIEND_ID_SEEK:

		break;
	case FRIEND_ADD:

		break;
	case ZAPYTANIE_DOSTEPNOSC:

		break;
	case FRIEND_LIST_REQUEST:

		break;
	case LOGOUT:

		break;
	case PING_RESPONSE:

		break;
	default:

		break;
	}
	return wynik;
}
