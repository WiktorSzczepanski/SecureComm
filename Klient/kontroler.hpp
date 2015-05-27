#ifndef kontroler_hpp
#define kontroler_hpp
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <list>
#include "model.hpp"

using namespace std;

class Kontroler
{
	private:
	Model *model;
	
	public:
	Kontroler();
	void petlaAplikacji();
};

#endif
