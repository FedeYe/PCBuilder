#ifndef ITEM_I_CONST_VISITOR_H
#define ITEM_I_CONST_VISITOR_H

namespace Component {

class Motherboard;
class CPU;
class GPU;
class PSU;
class RAM;

class IConstVisitor {
  public:
    virtual ~IConstVisitor() {};
    virtual void visit(const Motherboard& mother_board) = 0;
    virtual void visit(const CPU& cpu) = 0;
    virtual void visit(const GPU& gpu) = 0;
    virtual void visit(const PSU& psu) = 0;
    virtual void visit(const RAM& ram) = 0;
};

}

#endif