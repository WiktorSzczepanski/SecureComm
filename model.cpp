#include "model.hpp"

using namespace std;

int Model::polaczZSerwerem()
{
    return 0;
}
/*
int Model::wyslijWiadomoscPosrednio(WiadomoscPosrednia msg)
{
    sender.connectionlessSend("localhost", msg);
    
    return 0;
}*/

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
	sender.connectionlessSend("localhost",msg);
	return 0;
}

int Model::wyslijKomunikatRejestracji(RegistrationRequest msg)
{
	sender.connectionlessSend("localhost",msg);
	return 0;
}

int Model::wyslijKomunikatDodaniaZnajomego(FriendAdd msg)
{
	sender.connectionlessSend("localhost",msg);
	return 0;
}

int Model::wyslijKomunikatWyswietlaniaZnajomych(FriendListRequest msg)
{
	sender.connectionlessSend("localhost",msg);
	return 0;
}
