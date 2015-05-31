#ifndef SECURECOMM_COMMUNICATIONNODE_H
#define SECURECOMM_COMMUNICATIONNODE_H

#include <string>
#include "Sender.h"
#include "Listener.h"
#include "BQueue.h"

class CommunicationNode
{
private:
    Sender sender;
    Listener listener;
    BQueue<std::string> bQueue;
    //odbieracz z kolejki

public:
    CommunicationNode();

protected:
    //TODO! wiadomosc, adres, [port]
    void sendMessage();
    virtual void react(Komunikat &komunikat) = 0;

private:
    void messageProcessingLoop();
};

#endif //SECURECOMM_COMMUNICATIONNODE_H
