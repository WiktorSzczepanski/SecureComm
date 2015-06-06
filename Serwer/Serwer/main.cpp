#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include "../../CommunicationNode/BQueue.h"

using std::endl;
using std::cout;
////////////////////////////////////////////////////////////////////////////////////
bool kA = false, kB = false, dot = true;
std::mutex mutex;
////////////////////////////////////////////////////////////////////////////////////
class queueWriter
{
private:
	BQueue<std::string> taskQueue;
public:
	void writingLoop();
	void push(std::string toWrite);
}queueWriter;

void queueWriter::push(std::string toWrite)
{
	this->taskQueue.push(toWrite);
}

void queueWriter::writingLoop()
{
	while (dot)
	{
		cout << taskQueue.pop();
	}
}
////////////////////////////////////////////////////////////////////////////////////
void funA()
{
	//cout << "A " << endl;
	queueWriter.push("A \n");
	std::chrono::seconds sec(5);
	std::this_thread::sleep_for(sec);
	//cout << "A2 " << endl;
	queueWriter.push("A2 \n");
	kA = true;
	if (kB && kA)	dot = false;
}
////////////////////////////////////////////////////////////////////////////////////
void funB()
{
	//cout << "B " << endl;
	queueWriter.push("B \n");
	std::chrono::seconds sec(2);
	std::this_thread::sleep_for(sec);
	//cout << "B2 " << endl;
	queueWriter.push("B2 \n");
	kB = true;
	if (kB && kA)	dot = false;
}
////////////////////////////////////////////////////////////////////////////////////
void dotta()
{
	while (dot)
	{
		//cout << ". " << endl;
		queueWriter.push(". \n");
		std::chrono::milliseconds sec(500);
		std::this_thread::sleep_for(sec);
	}
}
////////////////////////////////////////////////////////////////////////////////////
void writingLoop()
{
	queueWriter.writingLoop();
}
////////////////////////////////////////////////////////////////////////////////////
int main()
{
	std::thread qWrite(writingLoop);
	std::thread dotter(dotta);
	std::thread A(funA);
	std::thread B(funB);

	//cout << "Wykonuja sie" << endl;
	queueWriter.push("Wykonuja sie\n");

	qWrite.join();
	dotter.join();
	A.join();
	B.join();

	//cout << "Skonczyly sie" << endl;
	queueWriter.push("Skonczyly sie\n");

	system("PAUSE");
	return 0;
}
