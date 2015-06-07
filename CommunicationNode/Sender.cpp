#include "Sender.h"

//TODO socketTab
void Sender::setConnection(const std::string &hostName)
{
    struct sockaddr_in address;
    struct hostent *hostDescription;
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

    return;
}

//TODO bez rozlaczania
void Sender::connectionlessSend(const std::string &hostName, const Komunikat &komunikat)
{
    {
        std::unique_lock<std::mutex> lock(this->d_mutex);
        setConnection(hostName);
        send(komunikat);
        disconnect();
    }
    return;
}

//TODO
void Sender::send(const std::string &recipient, const Komunikat &komunikat)
{

}

//(string login, string tresc)
void Sender::send(const Komunikat &komunikat)
{
    //const int MAX_BUFOR = 512;

    //TODO HACK
    char _buffer[MAX_BUFOR];
    char *buffer;// = _buffer;

    int sent;
    std::string message = komunikat.toString();
    for (int i=0; i<message.size(); i += MAX_BUFOR-1)
    {
        //printf("%d/\n",i); //TODO usun
        buffer = _buffer;
        bzero(buffer,MAX_BUFOR);
        message.copy(buffer,MAX_BUFOR-1,i);
        //for(int j=0; j<MAX_BUFOR-1; ++j) printf("%c",buffer[j]); printf("\n");
        int bufferLength = strlen(buffer);
        do
        {
            //for(int j=0; j<bufferLength; ++j) printf("%c",buffer[j]); printf(" vs %d\n",bufferLength);
            //printf("\t%s vs %d",buffer,bufferLength);
            if ( (sent = write(bsdSocket,buffer,bufferLength)) < 0 )
            {
                error("ERROR writing to socket");
            }
            buffer += sent;
            bufferLength -= sent;
            //TODO lepszy warunek
        } while ( sent != 0 );
    }

    return;
}

//TODO usun
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


int Sender::getPort() const
{
    return port;
}

Sender::Sender(const int port) : port(port)
{
    // celowo puste
}