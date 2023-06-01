#include "ComponentInjector.h"

namespace View
{
    namespace ComponentEditor
    {

        ComponentInjector::ComponentInjector(
            MotherBoardEditor &mother_board_editor,
            CPUEditor &cpu_editor,
            GPUEditor &gpu_editor,
            PSUEditor &psu_editor,
            RAMEditor &ram_editor)
            : mother_board_editor(mother_board_editor), cpu_editor(cpu_editor),
              gpu_editor(gpu_editor), psu_editor(psu_editor), ram_editor(ram_editor)
        {
        }

        void ComponentInjector::visit(const Component::MotherBoard &mother_board)
        {
            mother_board_editor.setValues(mother_board);
        }

        void ComponentInjector::visit(const Component::CPU &cpu)
        {
            cpu_editor.setValues(cpu);
        }

        void ComponentInjector::visit(const Component::GPU &gpu)
        {
            gpu_editor.setValues(gpu);
        }

        void ComponentInjector::visit(const Component::PSU &psu)
        {
            psu_editor.setValues(psu);
        }

        void ComponentInjector::visit(const Component::RAM &ram)
        {
            ram_editor.setValues(ram);
        }
    }
}