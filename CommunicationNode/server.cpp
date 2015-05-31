#include "Listener.h"

void test1();
void test2();

int main()
{
    test1();
    return 0;
}

void test1()
{
    Listener listener = Listener(22222);
    listener.setup();
    listener.activityLoop();
}

void test2()
{
    Listener listener = Listener(22222);
    listener.setup();
    int socket = listener.setMessageSocket();
    listener.fetchMessage(socket);
    listener.fetchMessage(socket);
}
