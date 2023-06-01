#include "TypeIdentifier.h"

namespace View {

    TypeIdentifier::TypeIdentifier(const unsigned int component_t) 
        : component_type(component_t) {

        }

    void TypeIdentifier::visit(const Component::MotherBoard& mother_board) {
        (void)mother_board;
        component_type = 1;
    }

    void TypeIdentifier::visit(const Component::CPU& cpu) {
        (void)cpu;
        component_type = 2;
    }

    void TypeIdentifier::visit(const Component::GPU& gpu) {
        (void)gpu;
        component_type = 3;
    }

    void TypeIdentifier::visit(const Component::PSU& psu) {
        (void)psu;
        component_type = 4;
    }

    void TypeIdentifier::visit(const Component::RAM& ram) {
        (void)ram;
        component_type = 5;
    }

    unsigned int TypeIdentifier::getCompType() {
        return component_type;
    }
}