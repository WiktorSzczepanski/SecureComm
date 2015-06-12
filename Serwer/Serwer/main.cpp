#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Deserializer.h"

using std::cout;
using std::endl;

int main()
{
	std::string komunikat("0#Darek#xasax");
	SharedKomunikatPtr komPtr = Deserializer::rozpoznajZeStringa(komunikat);
	cout << komPtr->toString() << endl;

	system("PAUSE");
	return 0;
}
