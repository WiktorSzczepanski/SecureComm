#ifndef SECURECOMM_LISTENER_H
#define SECURECOMM_LISTENER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
//bzero
#include <strings.h>
//potrzebne m. in. do close()
#include <unistd.h>
#include <cstring>
#include <string>
#include "ConnectionError.h"
#include "BQueue.h"

#include <map>

class Listener
{
public:
    Listener(const int port, BQueue<std::string> &bQueue);
    /* ustawienie nasluchiwania */
    void setup();
    /* funkcjonalnosc odbierania komunikatow */
    void activityLoop();
    /* zlecenie zakonczenia petli metody activityLoop */
    inline void shutdown() {stayActive = false;}

private:
    /* funkcjonalnosc pobierania wiadomosci */
    void fetchMessage();
    void fetchMessage2();
    /* ustawienie gniazda komunikacji */
    int setMessageSocket();
    /* pobranie wiadomosci z gniazda */
    void fetchMessage(int communicationSocket);

private:
    int getPort() const;

private:
    /* gniazdo nasluchiwania */
    int bsdSocket;
    //TODO cmnt new
    static const int MAX_FDS = 10;
    int socketTable[MAX_FDS];
    int nfds;
    std::map<int,std::stringstream*> msgStreams;

    /* port nasluchiwania */
    const int port;
    /* kolejka blokujaca na ktora odkladane sa przychodzace kompletne komunikaty */
    BQueue<std::string> &bQueue;
    void passMessage(std::string message);
    /* utrzymanie aktywnosci petli metody activityLoop */
    bool stayActive = true;

    static const int BUFFER_SIZE = 256;

    inline void error(const char *msg) const
    {
        ConnectionError::error(msg);
    }
    void concatenate(int socket, char *buffer, int length);
    void forwardMessage(int socket);
};

#endif //SECURECOMM_LISTENER_H
