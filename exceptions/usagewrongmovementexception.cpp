#include "usagewrongmovementexception.h"

char const* UsageWrongMovementException::what() const throw()
{
    return "UsageWrongMovementException";
}
