#ifndef klientNode_hpp
#define klientNode_hpp
#include <map>
#include "CommunicationNode/CommunicationNode.h"
#include <stdio.h>
//#include "model.hpp"
#include "Komunikaty/Komunikat.h"
#include "Komunikaty/Czesc.h"

using namespace std;

class KlientNode : public CommunicationNode
{
	private:
	BQueue<string>* blockingQueue;
	
    protected:
    void react(Komunikat &komunikat)
    {
		int id = komunikat.getId();

		switch(id)
		{
			case 1: if(komunikat.getId() == 1)
					{ 
						blockingQueue->push("KomunikatPoprawnegoLogowania");
					}
					else
					{
						blockingQueue->push("KomunikatNiepoprawnegoLogowania");
					}
					break;
			case 2: if(komunikat.getId() == 2)
					{ 
						blockingQueue->push("KomunikatPoprawnejRejestracji");
					}
					else
					{
						blockingQueue->push("KomunikatNiepoprawnejRejestracji");
					}
					break;
			case 3: blockingQueue->push("KomunikatWiadomosciPosredniej");
					break;
			case 4: blockingQueue->push("KomunikatListyZnajomych");
					break;
			case 5: blockingQueue->push("KomunikatDodaniaZnajomego");
					break;
			case 6: blockingQueue->push("KomunikatPoprawnegoWylogowania");
					break;
			default: cout<<"jakis blad"<<endl;
					break;
		}
		
	}
    // utworz komunikat ze stringa, sugestia: potomek ma pole fabryki; uwaga: potrzebna obsluga blednych stringow
    unique_ptr<Komunikat> createKomunikat(string kom)
    {
		char ch = kom[0];
		unique_ptr<Komunikat> ptr;
		
		switch(ch)
		{
			case 1: ptr = unique_ptr<Komunikat>(new Czesc("1"));
					cout<< "1";
					break;
			case 2: ptr = unique_ptr<Komunikat>(new Czesc("2"));
					cout<< "2";
					break;
			case 3: ptr = unique_ptr<Komunikat>(new Czesc("3"));
					cout<< "3";
					break;
			case 4: ptr = unique_ptr<Komunikat>(new Czesc("4"));
					break;
			case 5: ptr = unique_ptr<Komunikat>(new Czesc("5"));
					break;
			case 6: ptr = unique_ptr<Komunikat>(new Czesc("6"));
					break;
			case 7: ptr = unique_ptr<Komunikat>(new Czesc("7"));
					break;
			default: cout << "JAKIS BLAD"<<endl;
					break;
		}
		
		
		return ptr;
		
	}
	
	public:
	KlientNode(int port0, int port1,BQueue<string> * blockingQueue) : CommunicationNode(port0,port1) 
	{
		this->blockingQueue = blockingQueue;
	}
};

#endif
