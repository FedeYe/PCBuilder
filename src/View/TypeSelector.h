#ifndef VIEW_TYPE_SELECTOR_H
#define VIEW_TYPE_SELECTOR_H

#include <QComboBox>

#include "../Component/IConstVisitor.h"

namespace View
{

    class TypeSelector : public Component::IConstVisitor
    {
    private:
        QComboBox* combo;

    public:
        TypeSelector(QComboBox* combo);
        virtual void visit(const Component::MotherBoard& mother_board);
        virtual void visit(const Component::CPU& cpu);
        virtual void visit(const Component::GPU& gpu);
        virtual void visit(const Component::PSU& psu);
        virtual void visit(const Component::RAM& ram);
        QComboBox* getComboBox();
        TypeSelector& setComboBox(QComboBox* combo);
    };

}

#endif
