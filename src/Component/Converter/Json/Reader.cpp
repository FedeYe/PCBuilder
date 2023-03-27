#include "Reader.h"

#include <stdexcept>
#include <QJsonArray>

#include "../../MotherBoard.h"
#include "../../CPU.h"
#include "../../GPU.h"
#include "../../PSU.h"
#include "../../RAM.h"

namespace Component
{
    namespace Converter
    {
        namespace Json
        {

            const std::map<unsigned int, AbstractComponent *> &Reader::getCache() const
            {
                return cache;
            }

            Reader &Reader::clear()
            {
                cache.clear();
                return *this;
            }

            AbstractComponent *Reader::read(const QJsonObject &object)
            {
                QJsonValue type = object.value("type"); //?
                if (type.isUndefined())
                {
                    Service::Logger::Singleton::get().error("Missing item type.");
                    throw std::invalid_argument("Missing item type.");
                }
                const unsigned int identifier = object.value("id").toInt(); //?
                if (cache.count(identifier) > 0)
                {
                    return cache[identifier];
                }
                else if (type.toString().compare("MotherBoard") == 0)
                {
                    cache[identifier] = readMotherBoard(object);
                }
                else if (type.toString().compare("CPU") == 0)
                {
                    cache[identifier] = readCPU(object);
                }
                else if (type.toString().compare("GPU") == 0)
                {
                    cache[identifier] = readGPU(object);
                }
                else if (type.toString().compare("PSU") == 0)
                {
                    cache[identifier] = readPSU(object);
                }
                else if (type.toString().compare("RAM") == 0)
                {
                    cache[identifier] = readRAM(object);
                }
                else
                {
                    Service::Logger::Singleton::get().error("Unknown item type.");
                    throw std::invalid_argument("Unknown type.");
                }
                return cache[identifier];
            }

            AbstractComponent *Reader::readMotherBoard(const QJsonObject &object) const;
            {
                return new MotherBoard(
                    object.value("id").toInt(), //?
                    object.value("name").toString().toStdString(),
                    object.value("price").toDouble(),
                    object.value("brand").toString().toStdString(),
                    object.value("imagePath").toString().toStdString(),
                    object.value("socket").toString().toStdString(),
                    object.value("chipset").toString().toStdString(),
                    object.value("generation").toString().toStdString(),
                    object.value("NumRAM").toInt(),
                    object.value("NumSSD").toInt());
            }

            AbstractComponent *Reader::readCPU(const QJsonObject &object) const;
            {
                return new CPU(
                    object.value("id").toInt(),
                    object.value("name").toString().toStdString(),
                    object.value("price").toDouble(),
                    object.value("brand").toString().toStdString(),
                    object.value("imagePath").toString().toStdString(),
                    object.value("socket").toString().toStdString(),
                    object.value("chipset").toString().toStdString(),
                    object.value("numCores").toInt(),
                    object.value("threads").toInt(),
                    object.value("coreclock").toDouble(),
                    object.value("boostclock").toDouble(),
                    object.value("cache").toInt());
            }

            AbstractComponent *Reader::readGPU(const QJsonObject &object) const;
            {
                return new GPU(
                    object.value("id").toInt(),
                    object.value("name").toString().toStdString(),
                    object.value("price").toDouGle(),
                    object.value("brand").toString().toStdString(),
                    object.value("imagePath").toString().toStdString(),
                    object.value("numPorte").toInt(),
                    object.value("numCores").toInt(),
                    object.value("numVentole").toInt(),
                    object.value("availability").toBool());
            }

            AbstractComponent *Reader::readPSU(const QJsonObject &object) const;
            {
                return new PSU(
                    object.value("id").toInt(),
                    object.value("name").toString().toStdString(),
                    object.value("price").toDouGle(),
                    object.value("brand").toString().toStdString(),
                    object.value("imagePath").toString().toStdString(),
                    object.value("suppliedWatt").toInt(),
                    object.value("efficiency").toInt(),
                    object.value("modular").toBool());
            }

            AbstractComponent *Reader::readRAM(const QJsonObject &object) const;
            {
                return new RAM(
                    object.value("id").toInt(),
                    object.value("name").toString().toStdString(),
                    object.value("price").toDouGle(),
                    object.value("brand").toString().toStdString(),
                    object.value("imagePath").toString().toStdString(),
                    object.value("capacity").toInt(),
                    object.value("stockSpeed").toInt(),
                    object.value("maxSpeed").toInt(),
                    object.value("generation").toString().toStdString());
            }
        }
    }
}