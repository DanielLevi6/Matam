#include "exceptions.h"

namespace mtm{
    const string InvalidDate::nameOfException(){
        return string("InvalideDate");
    }

    const string NegativeDays::nameOfException(){
        return string("NegativeDays");
    }
}