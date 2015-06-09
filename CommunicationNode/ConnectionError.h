#ifndef SECURECOMM_CONNECTIONERROR_H
#define SECURECOMM_CONNECTIONERROR_H

#include <cstdio>
#include <stdexcept>
/**
 * Klasa obslugi bledow;
 */
class ConnectionError : public std::runtime_error
{
public:
    static void error(const char *msg)
    {
        std::string errorMsg(msg);
        errorMsg = errorMsg + ": " + strerror(errno);
        throw ConnectionError(errorMsg);
    }
    ConnectionError(const std::string& what) : std::runtime_error(what) {}
};

#endif //SECURECOMM_CONNECTIONERROR_H
