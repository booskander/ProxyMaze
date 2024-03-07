#include "FileManager.hpp"

FileManager::FileManager(const std::string& jsonFile) {

    filePath_ = jsonFile;
    std::ifstream countriesFile(this->filePath_, std::ifstream::binary);

    Json::Value countries;

    countriesFile >> countries;

    std::cout << countries << std::endl;
}
