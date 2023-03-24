#include "FilterVisitor.h"

namespace Engine
{

    FilterVisitor::FilterVisitor(const Query &query)
        : query(query), has_match(false)
    {
    }

    const Query &FilterVisitor::getQuery() const
    {
        return query;
    }

    bool FilterVisitor::hasMatch() const
    {
        return has_match;
    }

    void FilterVisitor::visit(const Component::MotherBoard &mother_board)
    {
        if (query.getType() == 1)
        {
            has_match = true;
        }
    }

    void FilterVisitor::visit(const Component::CPU &cpu)
    {
        if (query.getType() == 2)
        {
            has_match = true;
        }
    }

    void FilterVisitor::visit(const Component::GPU &gpu)
    {
        if (query.getType() == 3)
        {
            has_match = true;
        }
    }

    void FilterVisitor::visit(const Component::PSU &psu)
    {
        if (query.getType() == 4)
        {
            has_match = true;
        }
    }

    void FilterVisitor::visit(const Component::RAM &ram)
    {
        if (query.getType() == 5)
        {
            has_match = true;
        }
    }
}
