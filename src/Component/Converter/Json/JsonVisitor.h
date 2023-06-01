#ifndef COMPONENT_CONVERTER_JSON_JSON_VISITOR_H
#define COMPONENT_CONVERTER_JSON_JSON_VISITOR_H

#include <QJsonObject>
#include "../../IConstVisitor.h" 
#include "../../MotherBoard.h"
#include "../../CPU.h"
#include "../../GPU.h"
#include "../../PSU.h"
#include "../../RAM.h"

namespace Component {
namespace Converter {
namespace Json {

    class JsonVisitor : public IConstVisitor {
        private: 
            QJsonObject object;
        public:
            QJsonObject getObject() const;
            void visit(const MotherBoard& motherboard);
            void visit(const CPU& cpu);
            void visit(const GPU& gpu);
            void visit(const PSU& psu);
            void visit(const RAM& ram);
    };
}
}
}

#endif