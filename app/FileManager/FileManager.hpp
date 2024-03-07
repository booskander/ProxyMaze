#ifndef FILE_MANAGER
#define FILE_MANAGER
#include <iostream>
#include <fstream>
#include <string>
#include <jsoncpp/json/json.h>
#include "Country/Country.hpp"
#include <vector>
#include <algorithm>
class FileManager {

private:
    std::string filePath_;
    Json::Value jsonCountries_;

private:
    std::vector<Country*> parseCountries();


public:
    FileManager(const std::string& jsonPath);


    std::string getFilePath() { return filePath_; }

    std::vector<Country*> getCountries() {
        return this->parseCountries();
    }

};


#endif