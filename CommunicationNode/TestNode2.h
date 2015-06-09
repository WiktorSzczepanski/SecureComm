#ifndef SECURECOMM_TESTNODE_H
#define SECURECOMM_TESTNODE_H

#include "CommunicationNode.h"
//#include "Komunikaty/Komunikat.h"
#include "Czesc.h"
#include <random>
#include <mutex>
#include <iostream>
#include <string>


class Printer
{
    //static std::mutex mutex;
public:
    static void print(std::string string)
    {
        static std::mutex mutex;
        {
            std::unique_lock<std::mutex> lock(mutex);
            std::cout.flush();
            std::cout << string << std::endl;
        }
    }
};

/**
 * Test chaotycznej rozmowy. Pokazuje zdolnosc wezla do jednoczesnego nasluchiwania oraz wysylania komunikatow.
 * Kontrolowanie porzadku komunikacji jest w gestii wlasciwych potomkow klasy CommunicationNode
 * implementujacych logike klienta i serwera.
 */
class TestNode : public CommunicationNode
{
public:
    TestNode(int port0, int port1) : CommunicationNode(port0,port1) {}

protected:
    void react(Komunikat &komunikat)
    {
        Komunikat *answer = new Czesc("Zalogowany");
        Printer::print("Otrzymałem cos\n");
        sendMessage("localhost", *answer); //FIXME
        delete answer;
    }

    std::unique_ptr<Komunikat> createKomunikat(std::string string)
    {
        return std::unique_ptr<Komunikat>(new Czesc("Odpowiadam"));
    }

private:
    int getNastroj()
    {
        static std::default_random_engine generator;
        static std::bernoulli_distribution distribution(0.5);
        return distribution(generator);
    }

};

#endif //SECURECOMM_TESTNODE_H
