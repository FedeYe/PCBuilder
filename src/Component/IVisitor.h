#ifndef ITEM_I_VISITOR_H
#define ITEM_I_VISITOR_H

namespace Component {

class Motherboard;
class CPU;
class GPU;
class PSU;
class RAM;

class IVisitor {
  public:
    virtual ~IVisitor() {};
    virtual void visit(Motherboard& mother_board) = 0;
    virtual void visit(CPU& cpu) = 0;
    virtual void visit(GPU& gpu) = 0;
    virtual void visit(PSU& psu) = 0;
    virtual void visit(RAM& ram) = 0;
};

}

#endif