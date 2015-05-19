#include <iostream>
#include <thread>

bool kA = false, kB = false, dot = true;

void funA()
{
	std::cout << "A " << std::endl;
	std::chrono::seconds sec(5);
	std::this_thread::sleep_for(sec);
	std::cout << "A2 " << std::endl;
	kA = true;
	if (kB && kA)	dot = false;
}

void funB()
{
	std::cout << "B " <<std::endl;
	std::chrono::seconds sec(2);
	std::this_thread::sleep_for(sec);
	std::cout << "B2 " << std::endl;
	kB = true;
	if (kB && kA)	dot = false;
}

void dotta()
{
	while (dot)
	{
		std::cout << ". " << std::endl;
		std::chrono::milliseconds sec(500);
		std::this_thread::sleep_for(sec);
	}
}

int main()
{
	std::thread dotter(dotta);
	std::thread A(funA);
	std::thread B(funB);

	std::cout << "Wykonuja sie" << std::endl;

	dotter.join();
	A.join();
	B.join();

	std::cout << "Skonczyly sie" << std::endl;

	system("PAUSE");
	return 0;
}
