#pragma once
#include "string.h"

namespace mtl
{
class exception
{
public:
    exception(char const* err)throw();
    exception(string const & err)throw();
    virtual const char* what() const throw();
private:
    string err_;

};
class out_of_range:public exception
{
public:
    out_of_range(char const* err) throw();
    out_of_range(string const& err) throw();
};
class domain_error:public exception
{
public:
    domain_error(char const* err) throw();
    domain_error(string const& err)throw();
};
}
