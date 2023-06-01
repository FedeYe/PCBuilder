#ifndef ENGINE_QUERY_H
#define ENGINE_QUERY_H

namespace Engine
{
    class Query {
    private:
        unsigned int type;
        //valore di type identifica la componente che vogliamo ricercare 
        //valori speciali sono  0: valore di default
        //                      1: MotherBoard
        //                      2: CPU
        //                      3: GPU
        //                      4: PSU
        //                      5: RAM
    public:
        Query(unsigned int type = 0);
        unsigned int getType() const;
        void setType(unsigned int newValue);
    };
}

#endif