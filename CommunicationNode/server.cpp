#include "Listener.h"

#include "BQueue.h"
#include <string>

void test1();
void test2();
void test3();

int main()
{
    test3();
    return 0;
}

void test1()
{
    /*
    Listener listener = Listener(22222);
    listener.setup();
    listener.activityLoop();
     */
}

void test2()
{
    /*
    Listener listener = Listener(22222);
    listener.setup();
    int socket = listener.setMessageSocket();
    listener.fetchMessage(socket);
    listener.fetchMessage(socket);
     */
}

void test3()
{
    BQueue<std::string> bQueue = BQueue<std::string>();
    Listener listener = Listener(22222,bQueue);
    listener.setup();
    listener.activityLoop();
}