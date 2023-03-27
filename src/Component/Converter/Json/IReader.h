#ifndef COMPONENT_CONVERTER_JSON_IREADER_H
#define COMPONENT_CONVERTER_JSON_IREADER_H

#include <QJsonObject>

#include "../../AbstractComponent.h"

namespace Component
{
    namespace Converter
    {
        namespace Json
        {

            class IReader
            {
            public:
                virtual ~IReader(){};
                virtual AbstractComponent *read(const QJsonObject &object) = 0;
            };

        }
    }
}

#endif