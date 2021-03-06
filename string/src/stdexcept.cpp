#include "string.h"
#include "../include/stdexcept.h"

namespace mtl
{
exception::exception(char const* err)throw():err_(err) {};
exception::exception(string const& err)throw():err_(err) {};
const char* exception::what()const throw()
{
    return err_.c_str();
}
out_of_range::out_of_range(char const* err)throw():exception(err) {}
out_of_range::out_of_range(string const& err)throw():exception(err) {}
domain_error::domain_error(char const* err)throw():exception(err) {}
domain_error::domain_error(string const& err)throw():exception(err) {}
}
