#include "model.hpp"

using namespace std;

int Model::polaczZSerwerem()
{
    struct sockaddr_in serv_addr;
    struct hostent *server;
    const char *host = nazwaSerwera.c_str();
    string wiad;
    
    
    socketSerwer = socket(AF_INET, SOCK_STREAM, 0);
    // Sprawdzenie wartości deskryptora:
    if (socketSerwer < 0) 
    {
        fprintf(stderr,"ERROR opening socket");
	}
    // Sprawdzenie czy podany host istnieje:    
    server = gethostbyname(host);
    if (server == NULL) 
    {
        fprintf(stderr,"ERROR, no such host\n");
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(numerPortuSerwera);
    if (connect(socketSerwer,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        fprintf(stderr,"ERROR connecting");
    printf("Połączono z serwerem");
 
    
    return 0;
}

int Model::wyslijWiadomoscPosrednio(string login, string tresc)
{
	const int MAX_BUFOR = 512;
	int n;
	char buffer[MAX_BUFOR];
	bzero(buffer,MAX_BUFOR);
    strcpy(buffer, tresc.c_str());
    n = write(socketSerwer,buffer,strlen(buffer));
    if (n < 0) 
         fprintf(stderr,"ERROR writing to socket");
    bzero(buffer,MAX_BUFOR);
    n = read(socketSerwer,buffer,MAX_BUFOR - 1);
    if (n < 0) 
         fprintf(stderr,"ERROR reading from socket");
    printf("%s\n",buffer);
    
    return 0;
	
}

int Model::zakonczPolaczenieZSerwerem()
{
	close(socketSerwer);
	
	return 0;
}

void Model::blad(const char *msg)
{
  //  perror(msg);
  //  exit(0);
}
