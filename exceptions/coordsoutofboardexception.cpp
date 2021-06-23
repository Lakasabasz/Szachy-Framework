#include "coordsoutofboardexception.h"

char const* CoordsOutOfBoardException::what() const throw()
{
    return "CoordsOutOfBoardException";
}
