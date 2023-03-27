#include "Json.h"
#include "JsonVisitor.h"

namespace Component {
namespace Converter {
namespace Json {

    Json::Json(IReader& _reader) : reader(_reader) {}

    const Json::IReader& getReader() const {
        return reader;
    }

    QJsonObject Json::fromObject(const AbstractComponent component) const {
        JsonVisitor json_visitor;
        item.accept(json_visitor);
        return json_visitor.getObject();
    }

    AbstractComponent* Json::toObject(const QJsonObject& json) const {
        return reader.read(json);
    }

}
}
}

#endif