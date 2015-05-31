#ifndef SECURECOMM_CONNECTIONERROR_H
#define SECURECOMM_CONNECTIONERROR_H

#include <cstdio>

/**
 * Prosta obsluga bledow. Mozna zaimplementowac rowniez jako rzucanie wyjatkow.
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
