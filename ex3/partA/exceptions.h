#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>
#include <string>
#include <iostream>

using std::string;
using std::exception;

namespace mtm{
    class Exception:public exception{};
    class InvalidDate:public Exception{
    public:
        InvalidDate()=default;
        const string nameOfException();
    };
    class NegativeDays:public Exception{
    public:
        NegativeDays()=default;
        const string nameOfException();
    };
}

#endif