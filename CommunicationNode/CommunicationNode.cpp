#include "CommunicationNode.h"

CommunicationNode::CommunicationNode()
{
    //TODO temp
    int port = "22222";

    bQueue = BQueue<std::string>();
    sender = Sender();
    listener = Listener(port, bQueue);

    // rozruch;
}
