#ifndef VIEW_TYPE_IDENTIFIER_H
#define VIEW_TYPE_IDENTIFIER_H

#include "../Component/IConstVisitor.h"

namespace View
{

    class TypeIdentifier : public Component::IConstVisitor {

        private:
            unsigned int component_type;

        public:
            TypeIdentifier(const unsigned int component_t = 0);
            virtual void visit(const Component::MotherBoard& mother_board);
            virtual void visit(const Component::CPU& cpu);
            virtual void visit(const Component::GPU& gpu);
            virtual void visit(const Component::PSU& psu);
            virtual void visit(const Component::RAM& ram);
            unsigned int getCompType();
        };
}

#endif