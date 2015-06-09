#ifndef SECURECOMM_TESTNODE_H
#define SECURECOMM_TESTNODE_H

#include "CommunicationNode.h"
#include "Komunikaty/Komunikat.h"
#include <random>
#include <mutex>
#include <iostream>
#include <string>

class Czesc : public Komunikat
{
public:
    /* Test przeslania bardzo dlugiego komunikatu */
    std::string toString() const
    {
        return "Czesc";// Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc Czesc !!!!"
                ;
    }
    Czesc()
    {
        setId(0);
    }
};

class Idz : public Komunikat
{
public:
    std::string toString() const
    {
        return "A, idz pan";
    }
    Idz()
    {
        setId(1);
    }
};

class Uszanowanie : public Komunikat
{
public:
    std::string toString() const
    {
        return "Uszanowanie";
    }
    Uszanowanie()
    {
        setId(2);
    }
};

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
	bool success;
        Komunikat *answer;
        Printer::print("Otrzymałem: " + komunikat.toString());
        if ( komunikat.getId() != 0 )
        {
            return;
        }
        if (getNastroj() == 0)
        {
            answer = new Idz();
            Printer::print("\tMowie: \"" + answer->toString() +"\"");
            sendMessage("localhost", *answer);
        }
        else {
            answer = new Uszanowanie();
            Printer::print("\tMowie: \"" + answer->toString() + "\"");
            sendMessage("localhost", *answer);
        }
        delete answer;
    }

    std::unique_ptr<Komunikat> createKomunikat(std::string string)
    {
        if (string == Czesc().toString())
        {
            return std::unique_ptr<Komunikat>(new Czesc());
        }
        //if ( ch == 'A' )
        if (string == Idz().toString())
        {
            return std::unique_ptr<Komunikat>(new Idz());
        }
        //if ( ch == 'U' )
        if (string == Uszanowanie().toString())
        {
            return std::unique_ptr<Komunikat>(new Uszanowanie());
        }
        else
        {
            throw "Otrzymano smieci";
        }
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
