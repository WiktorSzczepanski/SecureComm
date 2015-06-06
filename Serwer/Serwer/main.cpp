#include <iostream>
#include <fstream>
#include <string>

bool pierwszy = false;
using std::endl;

int main()
{
	if (pierwszy)
	{
		std::ofstream toFile("Baza.udb");
		toFile << "1,Marian,haslo1234,2015,06,05#";
		toFile << "2,Stefan,buu2123,2015,06,02#";
		toFile.close();
	}

	else
	{
		std::ifstream fromFile("Baza.udb");
		std::string baza;
		fromFile >> baza;
		std::cout << baza <<endl;
		fromFile.close();
	}

	system("PAUSE");
	return 0;
}
