#ifndef SECURECOMM_SENDER_H
#define SECURECOMM_SENDER_H

#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
//TODO ^delete
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
//TODO ? bzero
#include <strings.h>
//potrzebne m. in. do close()
#include <unistd.h>
// gethostbyname
#include <netdb.h>
#include "ConnectionError.h"

class Sender
{
public:
    Sender(const std::string &hostName, const int port);
    void setConnection();
    int checkConnection() const;
    void send(std::string);
    void connectionlessSend(std::string);
    void fetchAnswer(char *buffer);
    void disconnect();

protected:
    const std::string& getHostName() const;
    int getPort() const;

private:
    const std::string hostName;
    static const int MAX_BUFOR = 512;
    const int port;
    int bsdSocket;
    inline void error(const char *msg) const
    {
        ConnectionError::error(msg);
    }
};

#endif //SECURECOMM_SENDER_H
