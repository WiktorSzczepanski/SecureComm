#ifndef SECURECOMM_LISTENER_H
#define SECURECOMM_LISTENER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
//bzero
#include <strings.h>
//potrzebne m. in. do close()
#include <unistd.h>
#include <cstring>
#include "ConnectionError.h"

class Listener
{
public:
    Listener(const int port);
    void setup();
    void activityLoop();
    //TODO protected:
    void fetchMessageConnectionless();
    int setMessageSocket();
    void fetchMessage(int communicationSocket);

protected:
    int getPort() const;
    void answer(int communicationSocket);

private:
    int bsdSocket;
    const int port;
    inline void error(const char *msg) const
    {
        ConnectionError::error(msg);
    }
};

#endif //SECURECOMM_LISTENER_H
