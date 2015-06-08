#include "CommunicationNode.h"

CommunicationNode::CommunicationNode(int portSend, int portListen)
        : bQueue(), sender(portSend), listener(portListen,bQueue)
{
    listener.setup();

    //watek nasluchiwania
    std::thread listenerThread(&Listener::activityLoop, &listener);
    listenerThread.detach();

    //watek reagowania na komunikaty
    std::thread messageProcessingThread(&CommunicationNode::messageProcessingLoop, this);
    messageProcessingThread.detach();
}

void CommunicationNode::messageProcessingLoop()
{
    while (stayActive)
    {
        std::string komunikatRaw = bQueue.pop();
        {
            std::unique_ptr <Komunikat> komunikat = createKomunikat(komunikatRaw);
            react(*komunikat.get());
        }
        //TODO delete
        sleep(1);
    }
}

void CommunicationNode::sendMessage(const std::string &address, const Komunikat &komunikat)
{
    sender._send(address, komunikat);
}

CommunicationNode::~CommunicationNode()
{
    stayActive = false;
    listener.shutdown();
    sleep(1);
}