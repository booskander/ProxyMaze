#include "FileManager/FileManager.hpp"

int main(int argc, char** argv) {

    std::string path = "Countries/all.json";

    FileManager* fm = new FileManager(path);


    delete fm;


}