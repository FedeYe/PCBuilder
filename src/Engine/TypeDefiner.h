#ifndef ENGINE_TYPE_DEFINER_H
#define ENGINE_TYPE_DEFINER_H

#include "../Component/IConstVisitor.h"

namespace Engine
{

    class TypeDefiner : public Component::IConstVisitor {

        private:
            unsigned int component_type;

        public:
            TypeDefiner(const unsigned int component_t = 0);
            virtual void visit(const Component::MotherBoard& mother_board);
            virtual void visit(const Component::CPU& cpu);
            virtual void visit(const Component::GPU& gpu);
            virtual void visit(const Component::PSU& psu);
            virtual void visit(const Component::RAM& ram);
            unsigned int getCompType();
        };
}

#endif