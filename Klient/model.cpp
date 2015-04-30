#include "model.hpp"

using namespace std;

int Model::polaczZSerwerem(int numerPortu, string nazwaHosta)
{
	const int MAX_BUFOR = 512;
	int n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    const char *host = nazwaHosta.c_str();
    string wiad;
    char buffer[MAX_BUFOR];
    
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
    serv_addr.sin_port = htons(numerPortu);
    if (connect(socketSerwer,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        fprintf(stderr,"ERROR connecting");
    printf("Please enter the message: ");
    bzero(buffer,MAX_BUFOR);
    fgets(buffer,MAX_BUFOR - 1,stdin);
    n = write(socketSerwer,buffer,strlen(buffer));
    if (n < 0) 
         fprintf(stderr,"ERROR writing to socket");
    bzero(buffer,MAX_BUFOR);
    n = read(socketSerwer,buffer,MAX_BUFOR - 1);
    if (n < 0) 
         fprintf(stderr,"ERROR reading from socket");
    printf("%s\n",buffer);
    
    zakonczPolaczenieZSerwerem();
    
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
