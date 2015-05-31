#include "CommunicationNode.h"
#include "TestNode.h"

int main()
{
    TestNode node1(22223,22222);
    sleep(1);
    while (1)
    {
        printf("Mowie \"Czesc\"\n");
        node1.sendMessage("localhost", Czesc());
        sleep(1);
    }
}
