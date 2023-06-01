#ifndef ENGINE_FILTER_VISITOR_H
#define ENGINE_FILTER_VISITOR_H

#include "Query.h"
#include "../Component/IConstVisitor.h"
#include "../Component/MotherBoard.h"
#include "../Component/CPU.h"
#include "../Component/GPU.h"
#include "../Component/PSU.h"
#include "../Component/RAM.h"

namespace Engine
{

    class FilterVisitor : public Component::IConstVisitor
    {
    private:
        const Query &query;
        bool has_match;

    public:
        FilterVisitor(const Query &query);
        const Query &getQuery() const;
        bool hasMatch() const;
        virtual void visit(const Component::MotherBoard &mother_board);
        virtual void visit(const Component::CPU &cpu);
        virtual void visit(const Component::GPU &gpu);
        virtual void visit(const Component::PSU &psu);
        virtual void visit(const Component::RAM &ram);
    };
}
#endif