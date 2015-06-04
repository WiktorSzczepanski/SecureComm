#ifndef model_hpp
#define model_hpp
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <list>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <stdio.h>
#include "Sender.h"
#include "Listener.h"
#include "CommunicationNode.h"
#include "Komunikaty/Czesc.h"
#include "Komunikaty/LoginRequest.h"
#include "Komunikaty/RegistrationRequest.h"
#include "Komunikaty/FriendAdd.h"
#include "Komunikaty/FriendListRequest.h"
//#include "Komunikaty/LogOut.h"
/*#include "Komunikaty/WiadomoscPosrednia.h"*/



using namespace std;

class Model
{
	private:
	// Sender.
	Sender sender = Sender(22222);
	// Nazwa serwera.
	const string nazwaSerwera = "localhost";
	// Numer portu serwera.
	const int numerPortuSerwera = 22222;
	// Deskryptor gniazda połączenia z serwerem.
	int socketSerwer;
	// Deskryptory gniazd połączeń bezpośrednich.
	list<int> socketUzytkownicy;
	
	
	public:
	// Metoda służąca do wysyłania bezpośredniej wiadomości do 
	// innego użytkownika.
	int wyslijWiadomoscBezposrednio(string login, string tresc);
	// Metoda służąca do wysyłania pośredniej wiadomości do innego
	// użytkownika.
	//int wyslijWiadomoscPosrednio(WiadomoscPosrednia msg);
	// Metoda służąca do odbierania wiadomości od serwera.
	int odbierzWiadomoscOdSerwera();
	// Metoda służąca do wysłanie komunikatu logowania.
	int wyslijKomunikatLogowania(LoginRequest msg);
	// Metoda służąca do wysłanie komunikatu logowania.
	int wyslijKomunikatRejestracji(RegistrationRequest msg);
	// Metoda służąca do wysłania komunikatu dodania znajomego.
	int wyslijKomunikatDodaniaZnajomego(FriendAdd msg);
	// Metoda służąca do wysłania komunikatu pobrania listy znajomych.
	int wyslijKomunikatWyswietlaniaZnajomych(FriendListRequest msg);
	// Nawiązanie połączenia z serwerem.
	int polaczZSerwerem();
	// Zakończenie połączenia z serwerem.
	int zakonczPolaczenieZSerwerem();
	// Funkcja zwracająca informację o błędzie.
	void blad(const char *msg);
	
};

#endif
