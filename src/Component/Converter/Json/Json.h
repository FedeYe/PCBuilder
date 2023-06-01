#ifndef COMPONENT_CONVERTER_JSON_JSON_H
#define COMPONENT_CONVERTER_JSON_JSON_H

#include <QJsonObject>
#include "../../AbstractComponent.h"
#include "IReader.h"

namespace Component {
namespace Converter {
namespace Json {

    class Json {
        private: 
            IReader& reader;

        public:
            Json(IReader& _reader);
            const IReader& getReader() const;
            QJsonObject fromObject(const AbstractComponent& component) const;
            AbstractComponent* toObject(const QJsonObject& json) const;
    };
}
}
}

#endif
