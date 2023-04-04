#include "JsonVisitor.h"

namespace Component
{
    namespace Converter
    {
        namespace Json
        {

            QJsonObject JsonVisitor::getObject() const
            {
                return object;
            }

            void JsonVisitor::visit(const MotherBoard &motherboard)
            {
                QJsonObject motherboard_object;
                motherboard_object.insert("type", QJsonValue::fromVariant("MotherBoard"));
                motherboard_object.insert("id", QJsonValue::fromVariant(motherboard.getIdentifier()));
                motherboard_object.insert("name", QJsonValue::fromVariant(motherboard.getName().c_str()));
                motherboard_object.insert("price", QJsonValue::fromVariant(motherboard.getPrice()));
                motherboard_object.insert("brand", QJsonValue::fromVariant(motherboard.getBrand().c_str()));
                motherboard_object.insert("imagePath", QJsonValue::fromVariant(motherboard.getImagePath().c_str()));
                motherboard_object.insert("socket", QJsonValue::fromVariant(motherboard.getSocket().c_str()));
                motherboard_object.insert("chipset", QJsonValue::fromVariant(motherboard.getChipset().c_str()));
                motherboard_object.insert("generation", QJsonValue::fromVariant(motherboard.getGeneration().c_str()));
                motherboard_object.insert("numRAM", QJsonValue::fromVariant(motherboard.getNumRAM()));
                motherboard_object.insert("numSSD", QJsonValue::fromVariant(motherboard.getNumSSD()));
                object = motherboard_object;
            }

            void JsonVisitor::visit(const CPU &cpu)
            {
                QJsonObject cpu_object;
                cpu_object.insert("type", QJsonValue::fromVariant("CPU"));
                cpu_object.insert("id", QJsonValue::fromVariant(cpu.getIdentifier()));
                cpu_object.insert("name", QJsonValue::fromVariant(cpu.getName().c_str()));
                cpu_object.insert("price", QJsonValue::fromVariant(cpu.getPrice()));
                cpu_object.insert("brand", QJsonValue::fromVariant(cpu.getBrand().c_str()));
                cpu_object.insert("imagePath", QJsonValue::fromVariant(cpu.getImagePath().c_str()));
                cpu_object.insert("chipset", QJsonValue::fromVariant(cpu.getChipset().c_str()));
                cpu_object.insert("numCores", QJsonValue::fromVariant(cpu.getNumCores()));
                cpu_object.insert("threads", QJsonValue::fromVariant(cpu.getThreads()));
                cpu_object.insert("coreclock", QJsonValue::fromVariant(cpu.getCoreclock()));
                cpu_object.insert("boostclock", QJsonValue::fromVariant(cpu.getBoostclock()));
                cpu_object.insert("cache", QJsonValue::fromVariant(cpu.getCache()));
                object = cpu_object;
            }

            void JsonVisitor::visit(const GPU &gpu)
            {
                QJsonObject gpu_object;
                gpu_object.insert("type", QJsonValue::fromVariant("GPU"));
                gpu_object.insert("id", QJsonValue::fromVariant(gpu.getIdentifier()));
                gpu_object.insert("name", QJsonValue::fromVariant(gpu.getName().c_str()));
                gpu_object.insert("price", QJsonValue::fromVariant(gpu.getPrice()));
                gpu_object.insert("brand", QJsonValue::fromVariant(gpu.getBrand().c_str()));
                gpu_object.insert("imagePath", QJsonValue::fromVariant(gpu.getImagePath().c_str()));
                gpu_object.insert("numPorte", QJsonValue::fromVariant(gpu.getNumPorte()));
                gpu_object.insert("numCores", QJsonValue::fromVariant(gpu.getNumCores()));
                gpu_object.insert("numVentole", QJsonValue::fromVariant(gpu.getNumVentole()));
                gpu_object.insert("availability", QJsonValue::fromVariant(gpu.isAvailable()));
                object = gpu_object;
            }

            void JsonVisitor::visit(const PSU &psu)
            {
                QJsonObject psu_object;
                psu_object.insert("type", QJsonValue::fromVariant("PSU"));
                psu_object.insert("id", QJsonValue::fromVariant(psu.getIdentifier()));
                psu_object.insert("name", QJsonValue::fromVariant(psu.getName().c_str()));
                psu_object.insert("price", QJsonValue::fromVariant(psu.getPrice()));
                psu_object.insert("brand", QJsonValue::fromVariant(psu.getBrand().c_str()));
                psu_object.insert("imagePath", QJsonValue::fromVariant(psu.getImagePath().c_str()));
                psu_object.insert("suppliedWatt", QJsonValue::fromVariant(psu.getSuppWatt()));
                psu_object.insert("efficiency", QJsonValue::fromVariant(psu.getEfficiency()));
                psu_object.insert("modular", QJsonValue::fromVariant(psu.isModular()));
                object = psu_object;
            }

            void JsonVisitor::visit(const RAM &ram)
            {
                QJsonObject ram_object;
                ram_object.insert("type", QJsonValue::fromVariant("RAM"));
                ram_object.insert("id", QJsonValue::fromVariant(ram.getIdentifier()));
                ram_object.insert("name", QJsonValue::fromVariant(ram.getName().c_str()));
                ram_object.insert("price", QJsonValue::fromVariant(ram.getPrice()));
                ram_object.insert("brand", QJsonValue::fromVariant(ram.getBrand().c_str()));
                ram_object.insert("imagePath", QJsonValue::fromVariant(ram.getImagePath().c_str()));
                ram_object.insert("capacity", QJsonValue::fromVariant(ram.getCapacity()));
                ram_object.insert("stockSpeed", QJsonValue::fromVariant(ram.getStockSpeed()));
                ram_object.insert("maxSpeed", QJsonValue::fromVariant(ram.getMaxSpeed()));
                ram_object.insert("generation", QJsonValue::fromVariant(ram.getGeneration().c_str()));
                object = ram_object;
            }

        }
    }
}
