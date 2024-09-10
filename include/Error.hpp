#ifndef MYERROR_HPP_
#define MYERROR_HPP_

#include <stdexcept>
#include <string>

class Error : public std::runtime_error
{
    public:
        Error(const std::string &what);
};

#endif /* !MYERROR_HPP_ */
