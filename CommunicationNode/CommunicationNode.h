#ifndef SECURECOMM_COMMUNICATIONNODE_H
#define SECURECOMM_COMMUNICATIONNODE_H

#include <string>
#include <thread>
#include "Sender.h"
#include "Listener.h"
#include "BQueue.h"
#include "Komunikaty/Komunikat.h"

//#include <memory>
//#include <thread>

/**
 * Wezel komunikacji komunikatora;
 * Moduly komunikacji klienta i serwera powinny byc jego potomkami (!)
 */
class CommunicationNode
{
protected:
    /*
     * Reakcja na nadzchodzacy komunikat, implementacja grafu komunikacji;
     * Sugestie realizacji: potomek posiada stany, stan AND komunikat powoduje przejscie do nowego stanu;
     * przejscie skutkuje wywolaniem procedur w potomku zwiazanych z logika klienta/serwera oraz
     * ewentualne wywolanie sendMessage z komunikatem odpowiedzi.
     */
    virtual void react(Komunikat &komunikat) = 0;

    /*
     * Zbudowanie obiektu komunikatu na podstawie otrzymanego przez TCP kompletnego stringa komunikatu;
     * sugestia implementacyjna: fabryka komunikatow klienta lub serwera;
     * uwaga: potrzebna obsluga blednych komunikatow.
     */
    virtual std::unique_ptr<Komunikat> createKomunikat(std::string) = 0;


public:
    /*
     * Inicjalizacja pol klasy oraz przypisanie portow wysylania i nasluchiwania,
     * wywolanie osobnych watkow nasluchiwania oraz petli obslugi komunikatow
     */
    CommunicationNode(int portSend, int portListen);

    /*
     * Zakonczenie nieskonczonych petli w watku nasluchiwania oraz oblugi komunikatow
     */
    ~CommunicationNode();

    /*
     * Wysylanie komunikatow;
     * do stosowania:
     * - z inicjatywy uzytkownika oraz
     * - w implementacjach metody react do wyslania automatycznych odpowiedzi [np. na zapytania]
     * @return: czy udalo sie przeslac wiadomosc, false swiadczy o niedostepnosci adresata
     */
    bool sendMessage(const std::string &address, const Komunikat &komunikat);

    /*
     * Dobrowolne rozlaczenie polaczenia wysylania komunikatow z wybranym adresatem; uzycie niewymagane.
     * @return: false jezeli polaczenie nie bylo ustanowione
     */
    bool disconnect(const std::string &hostName);

private:
    /*
     * Metoda pobierajaca komunikat i wywolujaca dla niego kolejno metody createKomunikat i react;
     * CommunicationNode wywoluje ja w osobnym watku;
     * Metoda oczekuje na przyjscie komunikatu i gdy ten nadejdzie wybudza sie i obsluguje go.
     */
    void messageProcessingLoop();

private:
    /* Modul wysylania komunikatow */
    Sender sender;
    /* Modul nasluchiwania komunikatow */
    Listener listener;
    /* Kolejka blokujaca nadchodzacych komunikatow */
    BQueue<std::string> bQueue;
    /* Aktywnosc petli wewnatrz metody messageProcessingLoop */
    bool stayActive = true;

    std::thread *listenerThread;
    std::thread *messageProcessingThread;
};

#endif //SECURECOMM_COMMUNICATIONNODE_H
