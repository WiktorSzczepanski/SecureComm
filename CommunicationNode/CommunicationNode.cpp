#include "CommunicationNode.h"

CommunicationNode::CommunicationNode(int portSend, int portListen)
        : bQueue(), sender(portSend), listener(portListen,bQueue)
{
    listener.setup();

    //watek nasluchiwania
    std::thread listenerThread(&Listener::activityLoop, &listener);
    listenerThread.detach();

    //watek reagowania na komunikaty
    std::thread messageProcessingThread //= std::thread
    //std::thread t
            (&CommunicationNode::messageProcessingLoop, this);
    messageProcessingThread.detach();

    //sleep(15);
}

void CommunicationNode::messageProcessingLoop()
{
    while (1)
    {
        std::string komunikatBare = bQueue.pop();
        //printf("%s\n", komunikatBare.c_str()); //usunac
        std::unique_ptr<Komunikat> komunikat = createKomunikat(komunikatBare);
        react(*komunikat.get());

        sleep(1);
        //printf("1\n");
    }
}

void CommunicationNode::sendMessage(const std::string &address, const Komunikat &komunikat)
{
    sender.connectionlessSend(address, komunikat);
}
