#include "CommunicationNode.h"

CommunicationNode::CommunicationNode(int portSend, int portListen)
        : bQueue(), sender(portSend), listener(portListen,bQueue)
{
    listener.setup();

    /*
    //watek nasluchiwania
    std::thread listenerThread(&Listener::activityLoop, &listener);
    listenerThread.detach();

    //watek reagowania na komunikaty
    std::thread messageProcessingThread(&CommunicationNode::messageProcessingLoop, this);
    messageProcessingThread.detach();
     */

    //watek nasluchiwania
    listenerThread = new std::thread(&Listener::activityLoop, &listener);
    listenerThread->detach();

    //watek reagowania na komunikaty
    messageProcessingThread = new std::thread(&CommunicationNode::messageProcessingLoop, this);
    messageProcessingThread->detach();
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
        //sleep(1);
    }
}

bool CommunicationNode::sendMessage(const std::string &address, const Komunikat &komunikat)
{
    return sender.sendKomunikat(address, komunikat);
}

bool CommunicationNode::disconnect(const std::string &address)
{
    return sender.disconnect(address);
}

CommunicationNode::~CommunicationNode()
{
    stayActive = false;
    listener.shutdown();

    sleep(1);

    //listenerThread->join();
    //messageProcessingThread->join();

    delete listenerThread;
    delete messageProcessingThread;

}