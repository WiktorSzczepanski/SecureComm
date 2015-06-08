#ifndef SECURECOMM_CONNECTIONERROR_H
#define SECURECOMM_CONNECTIONERROR_H

#include <cstdio>

/**
 * Klasa obslugi bledow;
 * docelowo jako rzucanie wyjatkow
 */
class ConnectionError
{
public:
    static void error(const char *msg)
    {
        perror(msg);
        exit(1);
    }
};

#endif //SECURECOMM_CONNECTIONERROR_H
