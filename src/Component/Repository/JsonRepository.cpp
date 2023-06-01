#include "JsonRepository.h"

#include <stdexcept>

#include "../Converter/Json/Reader.h"
#include "../Converter/Json/Json.h"

namespace Component {
namespace Repository {

    JsonRepository::JsonRepository(DataMapper::JsonFile data_mapper) 
    : data_mapper(data_mapper) {
        std::vector<AbstractComponent*> items(data_mapper.load());
        for (
            std::vector<AbstractComponent*>::const_iterator cit = items.begin();
            cit != items.end();
            cit++
        ) {
            repository[(*cit)->getIdentifier()] = *cit;
        }
    }

    JsonRepository::~JsonRepository() {
        for (
            std::map<unsigned int, AbstractComponent*>::const_iterator cit = repository.begin();
            cit != repository.end();
            cit++
        ) {
            delete cit->second;
        }
    }

    JsonRepository JsonRepository::fromPath(const std::string path) {
        Converter::Json::Reader reader;
        Converter::Json::Json converter(reader);
        DataMapper::JsonFile data_mapper(path, converter);
        JsonRepository repository(data_mapper);
        return repository;
    }

    const DataMapper::JsonFile& JsonRepository::getDataMapper() const {
        return data_mapper;
    }

    const std::map<unsigned int, AbstractComponent*>& JsonRepository::getRepository() const {
        return repository;
    }

    const std::string& JsonRepository::getPath() const {
        return data_mapper.getPath();
    }

    JsonRepository& JsonRepository::setPath(std::string path) {
        data_mapper.setPath(path);
        return *this;
    }

    JsonRepository& JsonRepository::create(AbstractComponent* component) {
        repository[component->getIdentifier()] = component;
        return *this;
    }

    AbstractComponent* JsonRepository::read(const unsigned int identifier) const {
        std::map<unsigned int, AbstractComponent*>::const_iterator it = repository.find(identifier);
        if (it == repository.end()) {
            throw std::out_of_range("Identiefer used is undefined so impossible to read");
        }
        return it->second;
    }

    JsonRepository& JsonRepository::update(AbstractComponent* component) {
        return create(component);
    }

    JsonRepository& JsonRepository::remove(const unsigned int identifier) {
        std::map<unsigned int, AbstractComponent*>::const_iterator cit = repository.find(identifier);
        if (cit != repository.end()) {
            delete cit->second;
            repository.erase(cit);
        }
        return *this;
    }

    std::vector<AbstractComponent*> JsonRepository::readAll() const {
        std::vector<AbstractComponent*> components;
        for (
            std::map<unsigned int, AbstractComponent*>::const_iterator it = repository.begin();
            it != repository.end();
            it++
        ) {
            components.push_back(it->second);
        }
        return components;
    }

    JsonRepository& JsonRepository::store() {
        data_mapper.store(readAll());
        return *this;
    }

}
}

