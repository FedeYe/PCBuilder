#ifndef COMPONENT_REPOSITORY_JSON_REPOSITORY_H
#define COMPONENT_REPOSITORY_JSON_REPOSITORY_H

#include <string>
#include <map>

#include "IRepository.h"
#include "../DataMapper/JsonFile.h"

namespace Component {
namespace Repository {

    class JsonRepository : public IRepository {
        private:
            DataMapper::JsonFile data_mapper;
            std::map<unsigned int, AbstractComponent*> repository;

        public:
            JsonRepository(DataMapper::JsonFile data_mapper);
            virtual ~JsonRepository();
            static JsonRepository fromPath(const std::string path);
            const DataMapper::JsonFile& getDataMapper() const;
            const std::map<unsigned int, AbstractComponent*>& getRepository() const;
            const std::string& getPath() const;
            JsonRepository& setPath(std::string path);
            virtual JsonRepository& create(AbstractComponent* component);
            virtual AbstractComponent* read(const unsigned int identifier) const;
            virtual JsonRepository& update(AbstractComponent* component);
            virtual JsonRepository& remove(const unsigned int identifier);
            virtual std::vector<AbstractComponent*> readAll() const;
            JsonRepository& store();
    };
}
}
#endif