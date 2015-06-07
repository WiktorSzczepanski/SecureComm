#include "Listener.h"

#include <sstream>

//using namespace ConnectionError;

//TODO remove cmnts
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

    // dowiaz serwer do gniazda
    //TODO getservbyname()
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(getPort());

    if (bind(bsdSocket, (struct sockaddr *) &address, sizeof(address)) == -1)
    {
        error("binding stream socket");
    }

    listen(bsdSocket,5);

    return;
}

/**
 * Glowne zadanie obiektu Listener - przyjmowanie i obsluga polaczen.
 */
void Listener::activityLoop()
{
    while (1)
    {
        fetchMessageConnectionless();
    }
}

void Listener::fetchMessageConnectionless()
{
    int messageSocket = setMessageSocket();
    fetchMessage(messageSocket);
    close(messageSocket);
    return;
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
    char buffer[256];
    bzero(buffer,256);
    int received;

    std::stringstream message;

    int loops = 0;

    do
    {
        //printf("%d",loops);
        if ( (received = read(messageSocket,buffer,255)) < 0 )
        {
            error("ERROR reading from socket");
        }
        for ( int i=0; i<received; ++i )
        {
            //TODO put
            message << buffer[i];
        }
        ++loops;
    } while ( received != 0 );
    message.put('\0');
    //TODO usun
    //printf("%s\n", message.str().c_str());
    //printf("Listening loops: %d\n", loops);

    passMessage(message.str());

    //processMessage(buffer);
    //answer(messageSocket);

    return;
}

/**
 * Do uzytkowania wewnatrz metody fetchListener.
 * Odpowiedzi niepotrzebnie blokuja obiekt Listener, odradza sie korzystanie.
 */
void Listener::answer(int messageSocket)
{
    char *answer = "Otrzymalem wiadomosc";
    if (write(messageSocket,answer,strlen(answer)*sizeof(char)) < 0)
    {
        error("ERROR writing to socket");
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

}

void Listener::passMessage(std::string message)
{
    bQueue.push(message);
    //TODO temp
    //printf("Otrzymalem wiadomosc: %s\n",message.c_str());
}
