#ifndef COMPONENT_DATA_MAPPER_JSON_FILE_H
#define COMPONENT_DATA_MAPPER_JSON_FILE_H

#include <string>
#include <vector>

#include "../AbstractComponent.h"
#include "../Converter/Json/Json.h"

namespace Component
{
    namespace DataMapper
    {

        class JsonFile
        {
        private:
            std::string path;
            Converter::Json::Json &converter;

        public:
            JsonFile(const std::string &path, Converter::Json::Json &converter);
            static JsonFile fromPath(const std::string &path);
            const std::string &getPath() const;
            JsonFile &setPath(const std::string &path);
            const Converter::Json::Json &getConverter() const;
            JsonFile &store(const std::vector<AbstractComponent *> components); //??
            std::vector<AbstractComponent *> load();
        };

    }
}

#endif