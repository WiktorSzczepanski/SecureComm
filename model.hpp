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
#include "KlientNode.hpp"
#include "Komunikaty/Czesc.h"
#include "Komunikaty/LoginRequest.h"
#include "Komunikaty/RegistrationRequest.h"
#include "Komunikaty/FriendAdd.h"
#include "Komunikaty/FriendListRequest.h"
#include "Komunikaty/LogOut.h"
#include "Komunikaty/WiadomoscPosrednia.h"
#include "Komunikaty/FriendSeek.h"


using namespace std;


class SecureCommReaction
{
	public:
	SecureCommReaction(){};
	virtual void wykonajReakcje()
	{
			
	};
	virtual ~SecureCommReaction(){};
};


class Model
{
	private:
	BQueue<string> *blockingQueue;
	// Numer portu serwera.
	const int numerPortuSerwera = 22222;
	// Numer portu klienta.
	const int numerPortuKlienta = 22233;
	// Numer portu odbiorcy.
	const int numerPortuOdbiorcy = 22244;
	// Numer portu nadawcy.
	const int numerPortuNadawcy = 22245;
	// Wezel komunikacji
	KlientNode* klientNode = new KlientNode(numerPortuSerwera, numerPortuKlienta,blockingQueue);
	// Nazwa serwera.
	const string nazwaSerwera = "localhost";
	// Deskryptor gniazda połączenia z serwerem.
	int socketSerwer;
	// Deskryptory gniazd połączeń bezpośrednich.
	list<pair<string,string> > komunikacjeZeZnajomymi;
	// Deskryptory gniazd połączeń bezpośrednich.
	list<pair<string,string> > komunikacjeBezposrednieZeZnajomymi;
	KlientNode* klientNodeBezposrednio;
	// Nazwa użytkownika.
	string loginUzytkownika;
	string idOdbiorcy;
	string adresOdbiorcy;
	
	public:
	Model(BQueue<string> *blockingQueue);
	// Metoda służąca do wysyłania bezpośredniej wiadomości do 
	// innego użytkownika.
	int wyslijWiadomoscBezposrednio(WiadomoscPosrednia msg);
	int utworzPolaczenieBezposrednie();
	// Dodaje komunikacje ze znajomym.
	void dodajKomunikacjeZeZnajomym(string id);
	// Dodaje komunikacje ze znajomym.
	void dodajKomunikacjeBezposredniaZeZnajomym(string adres);
	// Metoda służąca do wysyłania pośredniej wiadomości do innego
	// użytkownika.
	int wyslijWiadomoscPosrednio(WiadomoscPosrednia msg);
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
	void setLoginUzytkownika(string login);
	string getLoginUzytkownika();
	void setIdOdbiorcy(string id);
	string getIdOdbiorcy();
	void setAdresOdbiorcy(string adres);
	string getAdresOdbiorcy();
	void dodajZdarzenieDoKolejki(string event);
	
};



#endif
