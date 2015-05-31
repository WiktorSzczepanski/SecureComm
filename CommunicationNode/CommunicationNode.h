#ifndef SECURECOMM_COMMUNICATIONNODE_H
#define SECURECOMM_COMMUNICATIONNODE_H

#include <string>
#include "Sender.h"
#include "Listener.h"

class CommunicationNode
{
private:
    Sender sender;
    Listener listener;
};

#endif //SECURECOMM_COMMUNICATIONNODE_H
