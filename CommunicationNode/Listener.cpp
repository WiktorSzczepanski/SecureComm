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
        fetchMessage2();
    }
}

//TODO
void Listener::fetchMessage()
{
    //TODO to jest HACK
    static int messageSocket = setMessageSocket();
    fetchMessage(messageSocket);
    //close(messageSocket);
    return;
}

void Listener::fetchMessage2()
{
    //TODO pola klasy
    static fd_set ready;
    //bufory komunikatow
    //static ;

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
        //update liczby obserwowanych gniazd
        nfds = std::max(nfds, msgsock + 1);
        // TODO sprawdzenie czy msgsock>MAX_FDS
        socketTable[msgsock] = msgsock;
        //TODO usun linie
        printf("accepted...\n");
    }

    for (int socket = 0; socket < MAX_FDS; socket++)
    {
        // assert: msgsock == socketTable[socket]
        if ((msgsock = socketTable[socket]) > 0 && FD_ISSET(socketTable[socket], &ready))
        {
            memset(buffer, 0, sizeof(buffer));
            if ((received = recv(msgsock, buffer, BUFFER_SIZE, MSG_NOSIGNAL)) == -1)
            {
                //TODO obsluga rozlaczenia?
                error("reading stream message");
            }
            // rozlaczenie gniazda
            if (received == 0)
            {
                //TODO tmp
                printf("Mam zero\n");

                //TODO przerobka!
                printf("Ending connection\n");
                close( msgsock );
                /* usuń ze zbioru */
                socketTable[msgsock]=-1;

                //TODO HACK
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
                    concatenate(socket,buffer,j+1);
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
    }
}

void Listener::forwardMessage(int socket)
{
    std::stringstream *msgBuffer = msgStreams[socket];
    std::string komunikatStr = msgBuffer->str();
    printf("Podaje wiadomosc: %s\n", komunikatStr.c_str());
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

int Listener::setMessageSocket()
{
    int messageSocket = accept(bsdSocket,(struct sockaddr *) 0,(socklen_t *) 0);
    if (messageSocket < 0)
    {
        error("ERROR on accept");
    }
    return messageSocket;
}

//TODO podaj message
void Listener::fetchMessage(int messageSocket)
{
    //TODO stala!
    char buffer[BUFFER_SIZE];
    bzero(buffer,BUFFER_SIZE);
    int received;

    std::stringstream message;

    //TODO HACK
    int error_code = 0;
    socklen_t error_code_size = sizeof(error_code);
    int val = getsockopt(messageSocket, SOL_SOCKET, SO_ERROR, &error_code, &error_code_size);
    if (val != 0)
        return;

    do
    {
        if ( (received = read(messageSocket,buffer,BUFFER_SIZE)) < 0 )
        {
            error("ERROR reading from socket");
        }
        message.write(buffer,received);
        //TODO better
        //printf("Received: %d", received); //TODO timeout
        if ( received > 0 && buffer[received-1] == '\0' ) break;
    } while ( received != 0 );

    //TODO HACK
    if ( message.tellp() > 1 )
    {
        //printf( "tellp: %d ", message.tellp());
        //printf("Added element\n");
        passMessage(message.str());
    }
    return;
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

void Listener::passMessage(std::string message)
{
    bQueue.push(message);
}
