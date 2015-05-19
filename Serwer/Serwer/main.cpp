#include <iostream>
#include <thread>

using std::endl;
using std::cout;

bool kA = false, kB = false, dot = true;

void funA()
{
	cout << "A " << endl;
	std::chrono::seconds sec(5);
	std::this_thread::sleep_for(sec);
	cout << "A2 " << endl;
	kA = true;
	if (kB && kA)	dot = false;
}

void funB()
{
	cout << "B " << endl;
	std::chrono::seconds sec(2);
	std::this_thread::sleep_for(sec);
	cout << "B2 " << endl;
	kB = true;
	if (kB && kA)	dot = false;
}

void dotta()
{
	while (dot)
	{
		cout << ". " << endl;
		std::chrono::milliseconds sec(500);
		std::this_thread::sleep_for(sec);
	}
}

int main()
{
	std::thread dotter(dotta);
	std::thread A(funA);
	std::thread B(funB);

	cout << "Wykonuja sie" << endl;

	dotter.join();
	A.join();
	B.join();

	cout << "Skonczyly sie" << endl;

	system("PAUSE");
	return 0;
}
