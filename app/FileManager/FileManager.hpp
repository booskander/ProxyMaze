#ifndef FILE_MANAGER
#define FILE_MANAGER
#include <iostream>
#include <fstream>
#include <string>
#include <jsoncpp/json/json.h>
using namespace Json;
class FileManager {

private:
    std::string filePath_;

public:
    FileManager(const std::string& jsonPath);
};


#endif