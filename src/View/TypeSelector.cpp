#include "TypeSelector.h"

#include "../Component/IConstVisitor.h"

namespace View
{

    TypeSelector::TypeSelector(QComboBox *combo)
        : combo(combo)
    {
    }

    void TypeSelector::visit(const Component::MotherBoard& mother_board)
    {
        (void)mother_board;
        combo->setCurrentText("mother board");
    }

    void TypeSelector::visit(const Component::CPU& cpu)
    {
        (void)cpu;
        combo->setCurrentText("cpu");
    }

    void TypeSelector::visit(const Component::GPU& gpu)
    {
        (void)gpu;
        combo->setCurrentText("gpu");
    }

    void TypeSelector::visit(const Component::PSU& psu)
    {
        (void)psu;
        combo->setCurrentText("psu");
    }

    void TypeSelector::visit(const Component::RAM& ram)
    {
        (void)ram;
        combo->setCurrentText("ram");
    }

    QComboBox* TypeSelector::getComboBox()
    {
        return combo;
    }

    TypeSelector& TypeSelector::setComboBox(QComboBox* combo)
    {
        this->combo = combo;
        return *this;
    }

}
