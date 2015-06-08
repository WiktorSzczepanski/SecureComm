#ifndef SECURECOMM_SENDER_H
#define SECURECOMM_SENDER_H

#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
//bzero
#include <strings.h>
//potrzebne m. in. do close()
#include <unistd.h>
#include <netdb.h>
#include "ConnectionError.h"
#include "Komunikaty/Komunikat.h"
#include <mutex>
#include <map>

class Sender
{
public:
    /* ctor ustawiajacy port nasluchiwania */
    Sender(const int port);
    /* dtor rozlaczajacy gniazda */
    ~Sender();
    /* ustanowienie polaczenia */
    void setConnection(const std::string &hostName);
    /* wyslanie komunikatu do adresata */
    bool sendKomunikat(const std::string &hostName, const Komunikat &komunikat);
    /* rozlaczenie polaczenia; @return: false - polaczenie nie bylo ustanowione */
    bool disconnect(const std::string &hostName);

private:
    /* sprawdzenie czy polaczenie zostalo nawiazane i czy nie zostalo zerwane */
    bool isConnected(const std::string &hostName);
    /* rozlaczenie polaczenia */
    void disconnect(int bsdSocket);
    /* sprawdzenie czy polaczenie nie zostalo zerwane */
    bool checkConnection(int bsdSocket) const;

private:
    /* wielkosc bufora jednorazowo przesylanej porcji komunikatu */
    static const int MAX_BUFOR = 512;
    /* port na ktorym odbywa sie wysylanie */
    const int port;
    /* muteks chroniacy przed jednoczesnym wysylaniem przez wiele watkow */
    std::mutex d_mutex;
    /* kolekcja gniazd dla polaczen z wieloma zdresatami */
    std::map<std::string,int> sockets;

    /* wyslanie komunikatu na konkretnym gniezdzie */
    int sendKomunikat(int bsdSocket, const Komunikat &komunikat);
    /* pobranie gniazda przypisanego adresatowi; jezeli nie istnieje, utworzyc je. */
    int getSocket(const std::string &hostName);
    /* delegacja obslugi bledu; docelowo jako wyjatki */
    inline void error(const char *msg) const
    {
        ConnectionError::error(msg);
    }
    /* getter portu */
    int getPort() const;
};

#endif //SECURECOMM_SENDER_H
