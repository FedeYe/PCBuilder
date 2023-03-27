#ifndef COMPONENT_CONVERTER_JSON_READER_H
#define COMPONENT_CONVERTER_JSON_READER_H

#include <map>
#include <QJsonObject>

#include "IReader.h"

namespace Component
{
    namespace Converter
    {
        namespace Json
        {

            class Reader : public IReader
            {
            private:
                std::map<unsigned int, AbstractComponent *> cache;

            public:
                const std::map<unsigned int, AbstractComponent *> &getCache() const;
                Reader &clear();
                virtual AbstractComponent *read(const QJsonObject &object);

            private:
                AbstractComponent *readMotherBoard(const QJsonObject &object) const;
                AbstractComponent *readCPU(const QJsonObject &object) const;
                AbstractComponent *readGPU(const QJsonObject &object) const;
                AbstractComponent *readPSU(const QJsonObject &object) const;
                AbstractComponent *readRAM(const QJsonObject &object) const;
            };

        }
    }
}

#endif