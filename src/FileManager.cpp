#include "FileManager.hpp"

FileManager::FileManager(const std::string& jsonFile) {

    filePath_ = jsonFile;
    std::ifstream countriesFile(this->filePath_, std::ifstream::binary);

    countriesFile >> this->jsonCountries_;
}


std::vector<Country*> FileManager::parseCountries() {
    std::vector<Country*> list;

    for (auto&& country : this->jsonCountries_) {
        std::string name = country["name"].asString();
        std::string alpha2 = country["alpha-2"].asString();
        std::transform(name.begin(), name.end(), name.begin(), ::tolower);
        auto ref = Country::factory(name, alpha2);
        list.push_back(ref);
    }


    return list;
}