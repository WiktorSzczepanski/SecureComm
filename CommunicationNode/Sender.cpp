#include "Sender.h"

void Sender::setConnection(const std::string &hostName)
{
    struct sockaddr_in address;
    struct hostent *hostDescription;

    int bsdSocket;

    std::string message;

    //TODO temp, do usuniecia przy przejsciu na wyjatki
    int noAttempts = 5;
    tryAgain:

    // blok socket : tworzenie gniazda
    bsdSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (bsdSocket < 0)
    {
        error("ERROR opening socket");
    }

    // Sprawdzenie czy podany host istnieje:
    hostDescription = gethostbyname(hostName.c_str());
    if (hostDescription == NULL)
    {
        error("ERROR, no such host\n");
    }

    bzero((char *) &address, sizeof(address));
    address.sin_family = AF_INET;
    bcopy((char *) hostDescription->h_addr,
          (char *) &address.sin_addr.s_addr,
          hostDescription->h_length);
    address.sin_port = htons(getPort());

    //TODO usun skoki
    // blok connect : zestawienie polaczenia
    if (connect(bsdSocket,(struct sockaddr *) &address,sizeof(address)) < 0)
    {
        if (--noAttempts > 0)
        {
            sleep(1);
            goto tryAgain;
        }
        error("ERROR connecting");
    }

    sockets[hostName] = bsdSocket;

    return;
}

bool Sender::sendKomunikat(const std::string &hostName, const Komunikat &komunikat)
{
    int result;
    {
        std::unique_lock<std::mutex> lock(this->d_mutex);
        int socket = getSocket(hostName);
        result = sendKomunikat(socket, komunikat);
        //disconnect();
    }
    if (result != 0)
    {
        //printf("ERROR writing to socket: %s\n", strerror(result));
        return false;
    }
    return true;
}

int Sender::getSocket(const std::string &hostName)
{
    if ( !isConnected(hostName) )
    {
        setConnection(hostName);
    }
    return sockets[hostName];
}

bool Sender::isConnected(const std::string &hostName)
{
    return sockets.count(hostName) == 1 && checkConnection(sockets[hostName]); //TODO delete redundancy
}

int Sender::sendKomunikat(int bsdSocket, const Komunikat &komunikat)
{
    //TODO HACK
    char memory[MAX_BUFOR+1];
    char *buffer;// = _buffer;

    int sent;
    int result = 0;

    std::string message = komunikat.toString();
    for (int i=0; i<message.size(); i += MAX_BUFOR)
    {
        buffer = memory;
        bzero(buffer,MAX_BUFOR+1);
        message.copy(buffer,MAX_BUFOR,i);
        int bufferLength = strlen(buffer);
        do
        {
            if ( (sent = send(bsdSocket,buffer,bufferLength,MSG_NOSIGNAL)) < 0 )
            {
                result = errno;
                errno = 0;
                return result;
                //error("ERROR writing to socket");
            }
            buffer += sent;
            bufferLength -= sent;
            //TODO lepszy warunek
        } while ( sent != 0 );
    }

    buffer = memory;
    bzero(buffer,MAX_BUFOR+1);
    sent = write(bsdSocket,buffer,1);
    //printf("Sent: %d\n",sent);

    return result;
}


bool Sender::checkConnection(int bsdSocket) const
{
    int error_code = 0;
    socklen_t error_code_size = sizeof(error_code);
    int val = getsockopt(bsdSocket, SOL_SOCKET, SO_ERROR, &error_code, &error_code_size);
    return (val == 0);
}

bool Sender::disconnect(const std::string &hostName)
{
    bool result = isConnected(hostName);
    if (result)
    {
        disconnect(sockets[hostName]);
        sockets.erase(hostName);
    }
    return result;
}

void Sender::disconnect(int bsdSocket)
{
    close(bsdSocket);
    return;
}


int Sender::getPort() const
{
    return port;
}

Sender::Sender(const int port) : port(port)
{
    // celowo puste
}

//TODO
Sender::~Sender()
{
    for (std::map<std::string,int>::iterator iterator = sockets.begin(); iterator != sockets.end(); ++iterator)
    {
        disconnect(iterator->second);
    }
}