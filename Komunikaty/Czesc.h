#ifndef SECURECOMM_CZESC_H
#define SECURECOMM_CZESC_H

#include <string>
#include "Komunikat.h"

class Czesc : public Komunikat
{
    private:
    std::string wiad;

    public:
    Czesc(std::string w)
   {
	wiad = w;
   };
    std::string toString() const
    {
        return wiad;
    }
};

#endif //SECURECOMM_CZESC_H
