#include "CommunicationNode.h"
#include "TestNode.h"

int main()
{
    TestNode node1(22222,22223);
    sleep(3);
    while (1)
    {
        printf("Mowie \"Czesc\"\n");
        node1.sendMessage("localhost", Czesc());
        sleep(1);
    }
}
