#ifndef USAGEWRONGMOVEMENTEXCEPTION_H
#define USAGEWRONGMOVEMENTEXCEPTION_H

#include <exception>

class UsageWrongMovementException : public std::exception
{
public:
    virtual char const* what() const throw();
};

#endif // USAGEWRONGMOVEMENTEXCEPTION_H
