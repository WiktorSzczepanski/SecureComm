#include "Sender.h"
#include "Komunikaty/Czesc.h"
#include <stdlib.h>

void test1();
void test2();

int main()
{
    test2();
    return 0;
}


void test1()
{
    /*
    Sender sender = Sender("localhost", 22222);
    sender.setConnection();
    sender.send("Czesc");
    //TODO jednostka moze bys rozna?
    sleep(3);
    sender.send("Zyjesz?");
    sleep(3);
    sender.disconnect();
     */
}

void test2()
{
    Sender sender = Sender("localhost", 22222);
    Czesc msg = Czesc();
    sender.connectionlessSend(msg);
    /*
    sender.connectionlessSend("Czesc");
    sleep(3);
    sender.connectionlessSend("Zyjesz?");
     */
}
