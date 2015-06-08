#ifndef SECURECOMM_SENDER_H
#define SECURECOMM_SENDER_H

#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
//bzero
#include <strings.h>
//potrzebne m. in. do close()
#include <unistd.h>
// gethostbyname
#include <netdb.h>
#include "ConnectionError.h"
#include "Komunikaty/Komunikat.h"
#include <mutex>
#include <map>

class Sender
{
public:
    Sender(const int port);
    ~Sender();
    void setConnection(const std::string &hostName);
    // de facto zbedne
    //void send(const std::string &recipient, const Komunikat &komunikat);
    bool _send(const std::string &hostName, const Komunikat &komunikat);
    void fetchAnswer(char *buffer);
    void disconnect(const std::string &hostName);

protected:
    //const std::string& getHostName() const;
    int getPort() const;
    bool isConnected(const std::string &hostName);
    void disconnect(int bsdSocket);
    bool checkConnection(int bsdSocket) const;

private:
    //const std::string hostName;
    static const int MAX_BUFOR = 512;
    const int port;
    //int bsdSocket;
    std::mutex d_mutex;
    std::map<std::string,int> sockets;

    int _send(int bsdSocket, const Komunikat &komunikat);
    int getSocket(const std::string &hostName);
    inline void error(const char *msg) const
    {
        ConnectionError::error(msg);
    }
};

#endif //SECURECOMM_SENDER_H
