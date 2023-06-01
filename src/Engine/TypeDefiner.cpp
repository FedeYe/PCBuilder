#include "TypeDefiner.h"

namespace Engine {

    TypeDefiner::TypeDefiner(const unsigned int component_t) 
        : component_type(component_t) {

        }

    void TypeDefiner::visit(const Component::MotherBoard& mother_board) {
        (void)mother_board;
        component_type = 1;
    }

    void TypeDefiner::visit(const Component::CPU& cpu) {
        (void)cpu;
        component_type = 2;
    }

    void TypeDefiner::visit(const Component::GPU& gpu) {
        (void)gpu;
        component_type = 3;
    }

    void TypeDefiner::visit(const Component::PSU& psu) {
        (void)psu;
        component_type = 4;
    }

    void TypeDefiner::visit(const Component::RAM& ram) {
        (void)ram;
        component_type = 5;
    }

    unsigned int TypeDefiner::getCompType() {
        return component_type;
    }
}