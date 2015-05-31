#ifndef SECURECOMM_TESTNODE_H
#define SECURECOMM_TESTNODE_H

#include "CommunicationNode.h"
#include <random>

class Czesc : public Komunikat
{
public:
    std::string toString() const
    {
        return "Czesc";
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
        if ( komunikat.getId() == 0 )
        {
            if (getNastroj() == 0)
            {
                printf("Mowie \"Idz\"\n");
                sendMessage("localhost", Idz());
            }
            else {
                printf("Mowie \"Uszanowanie\"\n");
                sendMessage("localhost", Uszanowanie());
            }
        }
    }

    std::unique_ptr<Komunikat> createKomunikat(std::string string)
    {
        char ch = string[0];
        if ( ch == 'C' )
        {
            return std::unique_ptr<Komunikat>(new Czesc());
        }
        if ( ch == 'A' )
        {
            return std::unique_ptr<Komunikat>(new Idz());
        }
        //if ( ch == 'U' )
        else
        {
            return std::unique_ptr<Komunikat>(new Uszanowanie());
        }
        // throw

    }

private:
    int getNastroj()
    {
        static std::default_random_engine generator;
        static std::bernoulli_distribution distribution(0.5);
        /*
        static int i = 0;
        i = (i+1)%2;
        return i;
         */
        return distribution(generator);
    }

};

#endif //SECURECOMM_TESTNODE_H
