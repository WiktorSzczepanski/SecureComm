#include "model.hpp"

using namespace std;

Model::Model(BQueue<string> *blockingQueue)
{
	this->blockingQueue = blockingQueue;
}

int Model::polaczZSerwerem()
{
    return 0;
}

int Model::wyslijWiadomoscPosrednio(WiadomoscPosrednia msg)
{
    klientNode->sendMessage(nazwaSerwera, msg);
    
    return 0;
}

int Model::wyslijWiadomoscBezposrednio(WiadomoscPosrednia msg)
{
    klientNodeBezposrednio->sendMessage(adresOdbiorcy, msg);
    
    return 0;
}

int Model::utworzPolaczenieBezposrednie()
{
	klientNodeBezposrednio = new KlientNode(numerPortuOdbiorcy,numerPortuNadawcy,blockingQueue);
}

int Model::zakonczPolaczenieZSerwerem()
{	
	return 0;
}

void Model::blad(const char *msg)
{
  //  perror(msg);
  //  exit(0);
}

int Model::wyslijKomunikatLogowania(LoginRequest msg)
{
	klientNode->sendMessage(nazwaSerwera, msg);
	return 0;
}

int Model::wyslijKomunikatRejestracji(RegistrationRequest msg)
{
	klientNode->sendMessage(nazwaSerwera, msg);
	return 0;
}

int Model::wyslijKomunikatDodaniaZnajomego(FriendAdd msg)
{
	klientNode->sendMessage(nazwaSerwera, msg);
	return 0;
}

int Model::wyslijKomunikatWyswietlaniaZnajomych(FriendListRequest msg)
{
	klientNode->sendMessage(nazwaSerwera, msg);
	return 0;
}

void Model::dodajKomunikacjeZeZnajomym(string id)
{
	for (list<pair<string,string> >::iterator it = komunikacjeZeZnajomymi.begin(); it != komunikacjeZeZnajomymi.end(); it++)
	{

	}
}

void Model::dodajKomunikacjeBezposredniaZeZnajomym(string adres)
{
	for (list<pair<string,string> >::iterator it = komunikacjeBezposrednieZeZnajomymi.begin(); it != komunikacjeBezposrednieZeZnajomymi.end(); it++)
	{

	}
}

void Model::setLoginUzytkownika(string login)
{
	loginUzytkownika = login;
}

string Model::getLoginUzytkownika()
{
	return loginUzytkownika;
}

void Model::setIdOdbiorcy(string id)
{
	idOdbiorcy = id;
}

string Model::getIdOdbiorcy()
{
	return idOdbiorcy;
}

void Model::setAdresOdbiorcy(string adres)
{
	adresOdbiorcy = adres;
}

string Model::getAdresOdbiorcy()
{
	return adresOdbiorcy;
}

void Model::dodajZdarzenieDoKolejki(string event)
{
	blockingQueue->push(event);
}
