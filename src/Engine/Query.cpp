#include "Query.h"

namespace Engine
{
    Query::Query(unsigned int type): type(type) {
    }

    unsigned int Query::getType() const {
        return type;
    }

    void Query::setType(unsigned int newValue) {
        type = newValue;
    }
}