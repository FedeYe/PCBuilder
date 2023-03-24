#ifndef ENGINE_QUERY_H
#define ENGINE_QUERY_H

namespace Engine
{

    class Query
    {
    private:
        const unsigned int type;

    public:
        Query(
            const unsigned int type);

        unsigned int getType() const;
    };
}

#endif