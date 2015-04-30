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


using namespace std;

class Model
{
	private:
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
	int wyslijWiadomoscPosrednio(string login,string tresc);
	// Metoda służąca do odbierania wiadomości od serwera.
	int odbierzWiadomoscOdSerwera();
	// Nawiązanie połączenia z serwerem.
	int polaczZSerwerem(int numer_portu, string nazwaHosta);
	// Zakończenie połączenia z serwerem.
	int zakonczPolaczenieZSerwerem();
	// Funkcja zwracająca informację o błędzie.
	void blad(const char *msg);
};

#endif
