#include "../include/Error.hpp"

Error::Error(const std::string &what) : std::runtime_error(what)
{
}
