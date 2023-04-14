#ifndef VIEW_ITEM_EDITOR_COMPONENT_INJECTOR_H
#define VIEW_ITEM_EDITOR_COMPONENT_INJECTOR_H

#include "../../Component/IConstVisitor.h"
#include "MotherBoardEditor.h"
#include "CPUEditor.h"
#include "GPUEditor.h"
#include "PSUEditor.h"
#include "RAMEditor.h"

namespace View
{
    namespace ComponentEditor
    {

        class ComponentInjector : public Component::IConstVisitor
        {
        private:
            MotherBoardEditor &mother_board_editor;
            CPUEditor &cpu_editor;
            GPUEditor &gpu_editor;
            PSUEditor &psu_editor;
            RAMEditor &ram_editor;

        public:
            ComponentInjector(
                MotherBoardEditor &mother_board_editor,
                CPUEditor &cpu_editor,
                GPUEditor &gpu_editor,
                PSUEditor &psu_editor,
                RAMEditor &ram_editor);
            virtual void visit(const Component::MotherBoard &mother_board);
            virtual void visit(const Component::CPU &cpu);
            virtual void visit(const Component::GPU &gpu);
            virtual void visit(const Component::PSU &psu);
            virtual void visit(const Component::RAM &ram);
        };

    }
}

#endif