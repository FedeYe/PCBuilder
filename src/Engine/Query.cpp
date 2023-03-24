#include "Query.h"

namespace Engine
{
    Query::Query(
        const unsigned int type)
        : type(type)
    {
    }

    unsigned int Query::getType() const
    {
        return type;
    }
}