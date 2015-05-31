#include "CommunicationNode.h"
#include "Komunikaty/Czesc.h"
#include <thread>

void agent1();
void agent2();

int main()
{
    std::thread a1(agent1);
    a1.detach();
    std::thread a2(agent2);
    a2.detach();
    sleep(30);
    return 0;
}

void agent1()
{
    CommunicationNode node1(22222,22223);
    const Komunikat &komunikat = Czesc();
    sleep(3);
    node1.sendMessage("localhost",komunikat);
    sleep(30);
}

void agent2()
{
    CommunicationNode node2(22223,22222);
    sleep(30);
}
