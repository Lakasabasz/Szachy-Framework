#ifndef COORDSOUTOFBOARDEXCEPTION_H
#define COORDSOUTOFBOARDEXCEPTION_H

#include <exception>

class CoordsOutOfBoardException : public std::exception
{
public:
    virtual char const* what() const throw();
};

#endif // COORDSOUTOFBOARDEXCEPTION_H
