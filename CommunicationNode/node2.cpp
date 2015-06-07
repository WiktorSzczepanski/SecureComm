#include "CommunicationNode.h"
#include "TestNode.h"
#include <random>

int main()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,5);

    TestNode node1(22223,22222);
    sleep(distribution(generator));
    while (1)
    {
        //printf("Mowie \"Czesc\"\n");
        Printer::print("Mowie \"Czesc\"");
        node1.sendMessage("localhost", Czesc());
        sleep(distribution(generator));
    }
}
