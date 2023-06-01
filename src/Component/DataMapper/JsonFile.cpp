#include "JsonFile.h"
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

#include "../Converter/Json/Reader.h"

namespace Component
{
    namespace DataMapper
    {

        JsonFile::JsonFile(const std::string &path, Converter::Json::Json &converter)
            : path(path), converter(converter)
        {
        }

        JsonFile JsonFile::fromPath(const std::string &path)
        {
            Converter::Json::Reader reader;
            Converter::Json::Json converter(reader);
            JsonFile data_mapper(path, converter);
            return data_mapper;
        }

        const std::string &JsonFile::getPath() const
        {
            return path;
        }

        JsonFile &JsonFile::setPath(const std::string &path)
        {
            this->path = path;
            return *this;
        }

        const Converter::Json::Json &JsonFile::getConverter() const
        {
            return converter;
        }

        JsonFile &JsonFile::store(const std::vector<AbstractComponent *> components)
        {
            QJsonArray json_components;
            for (
                std::vector<AbstractComponent *>::const_iterator it = components.begin();
                it != components.end();
                it++)
            {
                json_components.push_back(converter.fromObject(**it));
            }
            QJsonDocument document(json_components);
            QFile json_file(path.c_str());
            json_file.open(QFile::WriteOnly);
            json_file.write(document.toJson());
            json_file.close();
            return *this;
        }

        std::vector<AbstractComponent *> JsonFile::load()
        {
            std::vector<AbstractComponent *> components;
            QFile json_file(path.c_str());
            json_file.open(QFile::ReadOnly);
            QByteArray data = json_file.readAll();
            json_file.close();
            QJsonDocument document = QJsonDocument::fromJson(data);
            QJsonArray json_components = document.array();

            for (const QJsonValue &value : json_components)
            {
                QJsonObject json_object = value.toObject();
                components.push_back(converter.toObject(json_object));
            }
            return components;
        }

    }
}
