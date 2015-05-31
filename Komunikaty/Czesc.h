#ifndef SECURECOMM_CZESC_H
#define SECURECOMM_CZESC_H

#include <string>
#include "Komunikat.h"

class Czesc : public Komunikat
{
    std::string toString() const
    {
        return "Czesc";
    }
};

#endif //SECURECOMM_CZESC_H
