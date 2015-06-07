#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
//#include <time.h>

bool pierwszy = false;
using std::endl;

int main()
{
	std::string s1 = "0123456789";
	std::string::iterator it1 = s1.begin() + 1;
	std::string::iterator it2 = s1.end() - 1;
	s1.erase(it1, it2);

	std::cout << s1 <<std::endl;

	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	std::cout << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< endl;

	system("PAUSE");
	return 0;
}
