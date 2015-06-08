#include "Listener.h"

#include <sstream>

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
    while (stayActive)
    {
        fetchMessage();
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

}

void Listener::passMessage(std::string message)
{
    bQueue.push(message);
}
