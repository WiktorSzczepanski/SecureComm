#include "Sender.h"

void Sender::setConnection()
{
    struct sockaddr_in address;
    struct hostent *hostDescription;
    std::string message;

    // blok socket : tworzenie gniazda
    bsdSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (bsdSocket < 0)
    {
        error("ERROR opening socket");
    }

    // Sprawdzenie czy podany host istnieje:
    hostDescription = gethostbyname(getHostName().c_str());
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

    // blok connect : zestawienie polaczenia
    if (connect(bsdSocket,(struct sockaddr *) &address,sizeof(address)) < 0)
    {
        error("ERROR connecting");
    }

    return;
}

void Sender::connectionlessSend(std::string message)
{
    setConnection();
    send(message);
    disconnect();
    return;
}

//(string login, string tresc)
//TODO komunikat
void Sender::send(std::string message)
{
    //const int MAX_BUFOR = 512;

    char buffer[MAX_BUFOR];

    bzero(buffer,MAX_BUFOR);
    strcpy(buffer, message.c_str());

    // blok write
    if (write(bsdSocket,buffer,strlen(buffer)) < 0)
    {
        error("ERROR writing to socket");
    }

    //fetchAnswer(buffer);

    return;
}

//TODO
void Sender::fetchAnswer(char *buffer)
{
    bzero(buffer,MAX_BUFOR);
    if (read(bsdSocket,buffer,MAX_BUFOR - 1) < 0)
    {
        error("ERROR reading from socket");
    }
    //TODO !zwroc odpowiedz, a to usun
    printf("Listener: %s\n",buffer);
    return;
}

int Sender::checkConnection() const
{
    int error_code = 0;
    socklen_t error_code_size = sizeof(error_code);
    int val = getsockopt(bsdSocket, SOL_SOCKET, SO_ERROR, &error_code, &error_code_size);
    return (int)(val == 0);
}

void Sender::disconnect()
{
    close(bsdSocket);
    return;
}

const std::string& Sender::getHostName() const
{
    return hostName;
}

int Sender::getPort() const
{
    return port;
}

Sender::Sender(const std::string &hostName, const int port) : hostName(hostName), port(port)
{
    // celowo puste
}