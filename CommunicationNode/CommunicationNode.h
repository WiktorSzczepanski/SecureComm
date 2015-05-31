#ifndef SECURECOMM_COMMUNICATIONNODE_H
#define SECURECOMM_COMMUNICATIONNODE_H

#include <string>
#include <thread>
#include "Sender.h"
#include "Listener.h"
#include "BQueue.h"
#include "Komunikaty/Komunikat.h"

/**
 * Zarowno klient jak i serwer musza posiadac umiejetnosc wysylania jak i odbierania komunikatow
 * Klasa jest pomyslana jako ich wspolny przodek.
 */
class CommunicationNode
{
private:
    Sender sender;
    Listener listener;
    BQueue<std::string> bQueue;
    //odbieracz z kolejki

    //std::thread *listenerThread;
    //std::thread *messageProcessingThread;

public:
    CommunicationNode(int portSend, int portListen);
    void sendMessage(const std::string &address, const Komunikat &komunikat);

protected:
    // wywolanie procedur ktorych wymaga komunikat, sugestia: hashmapa
    //virtual void react(Komunikat &komunikat) = 0;
    // utworz komunikat ze stringa, sugestia: potomek ma pole fabryki; uwaga: potrzebna obsluga blednych stringow
    //virtual Komunikat createKomunikat(std::string) = 0;

private:
    void messageProcessingLoop();
};

#endif //SECURECOMM_COMMUNICATIONNODE_H
