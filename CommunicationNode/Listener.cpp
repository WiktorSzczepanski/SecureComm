#include "Listener.h"

#include <sstream>
//#include <string>
#include <map>
#include <sys/time.h>
#include <algorithm>

void Listener::setup()
{
    int length;
    struct sockaddr_in address;

    // blok socket
    bsdSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (bsdSocket == -1)
    {
        error("opening stream socket");
    }

    nfds = bsdSocket + 1;

    // dowiaz serwer do gniazda
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(getPort());

    if (bind(bsdSocket, (struct sockaddr *) &address, sizeof(address)) == -1)
    {
        error("binding stream socket");
    }

    //TODO przenies do activity loop
    listen(bsdSocket,5);

    return;
}

/**
 * Glowne zadanie obiektu Listener - przyjmowanie i obsluga polaczen.
 */
void Listener::activityLoop()
{
    while (stayActive)
    {
        fetchMessage();
    }
}

void Listener::fetchMessage()
{
    int nActive;
    int msgsock;
    int received;
    //bufor porcji komunikatu
    char buffer[BUFFER_SIZE];
    struct timeval to;

    FD_ZERO(&ready);
    FD_SET(bsdSocket, &ready);

    for (int i = 0; i < MAX_FDS; ++i)
    {
        if (socketTable[i] > 0)
        {
            FD_SET(socketTable[i], &ready);
        }
    }

    to.tv_sec = 5;
    to.tv_usec = 0;

    if ((nActive = select(nfds, &ready, (fd_set *) 0, (fd_set *) 0, &to)) == -1)
    {
        error("select");
        return;
    }

    //case: przyslo nowe polaczenie
    if (FD_ISSET(bsdSocket, &ready))
    {
        msgsock = accept(bsdSocket, (struct sockaddr *) 0, (socklen_t *) 0);
        if (msgsock == -1)
        {
            error("accept");
        }
        //update liczby deskryptorow
        nfds = std::max(nfds, msgsock + 1);
        // TODO sprawdzenie czy msgsock>MAX_FDS
        socketTable[msgsock] = msgsock;
        //printf("accepted...\n");
    }

    //TODO zamiast socketTable gniazda : std::set<int>
    for (int socket = 0; socket < MAX_FDS; socket++)
    {
        // assert: msgsock == socketTable[socket]
        if ((msgsock = socketTable[socket]) > 0 && FD_ISSET(socketTable[socket], &ready))
        {
            memset(buffer, 0, sizeof(buffer));
            if ((received = recv(msgsock, buffer, BUFFER_SIZE, MSG_NOSIGNAL)) == -1)
            {
                error("reading stream message");
            }
            // rozlaczenie gniazda
            if (received == 0)
            {
                //printf("Ending connection\n");
                close( msgsock );
                /* usuń ze zbioru */
                socketTable[msgsock]=-1;

                continue;
            }

            bool lastPortionOfMessage = false;
            // wyszukiwanie znaku dzielacego kolejne komunikaty
            for ( int j=0; j<received; ++j )
            {
                // odebrano ostatnia porcje komunikatu
                if ( buffer[j] == '\0' )
                {
                    //printf("Z zerem na %d vs received: %d.\n", j, received);
                    concatenate(socket,buffer,j);
                    forwardMessage(socket);
                    int remainder = received - j - 1;
                    if ( remainder > 0 )
                    {
                        concatenate(socket, buffer + j + 1, remainder);
                    }
                    lastPortionOfMessage = true;
                }
            }
            // odbior porcji komunikatu
            if (received>0 && !lastPortionOfMessage)
            {
                concatenate(socket,buffer,received);
                //printf("Otrzymano fragment komunikatu.\n\t%s\n",msgStreams[socket]->str().c_str());
            }
        }
        //printf("Nic do roboty.\n");
    }
}

void Listener::forwardMessage(int socket)
{
    std::stringstream *msgBuffer = msgStreams[socket];
    std::string komunikatStr = msgBuffer->str();
    //TODO remove line
    //printf("Podaje wiadomosc: %s\n", komunikatStr.c_str());
    msgStreams.erase(socket);
    delete msgBuffer;
    passMessage(komunikatStr);
}

void Listener::concatenate(int socket, char *buffer, int length)
{
    if (msgStreams.count(socket) == 0)
    {
        msgStreams[socket] = new std::stringstream();
    }
    msgStreams[socket]->write(buffer,length);
}

int Listener::getPort() const
{
    return port;
}

Listener::Listener(const int port, BQueue<std::string> &bQueue)
        : port(port), bQueue(bQueue)
{
    for (int i=0; i<MAX_FDS; ++i)
    {
        socketTable[i] = 0;
    }
    //TODO
    //setup();
}

//TODO dodaj do forwardMessage
void Listener::passMessage(std::string message)
{
    bQueue.push(message);
}
