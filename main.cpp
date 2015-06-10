#include "kontroler.hpp"
#include "CommunicationNode/BQueue.h"

using namespace std;

int main()
{
	
	BQueue<string> *blockingQueue = new BQueue<string>();
	Model *model = new Model(blockingQueue);
	Kontroler kontroler = Kontroler(blockingQueue, model);
	
	kontroler.petlaAplikacji();
	
	return 0;
}
