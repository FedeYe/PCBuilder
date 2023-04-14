#ifndef ENGINE_QUERY_H
#define ENGINE_QUERY_H

namespace Engine
{
    class Query {
    private:
        unsigned int type;
        //valore di type identifica la componente che vogliamo ricercare 
        //valori speciali sono -1: valore di default
        //                      0: set type to max( qui max = 5)
        //                      1: MotherBoard
        //                      2: CPU
        //                      3: GPU
        //                      4: PSU
        //                      5: RAM
        //                      6(max+1): set type to 1
    public:
        Query(unsigned int type = -1);
        unsigned int getType() const;
        void setType(unsigned int newValue);
    };
}

#endif