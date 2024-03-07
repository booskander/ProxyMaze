#include "FileManager/FileManager.hpp"
#include "Request/RequestService.hpp"
int main(int argc, char** argv) {

    auto req = new RequestService("FileManager/Country/all.json");


    std::string input;
    std::string alpha;

    while(alpha.empty()) {
        std::cout << "Choose a country: " << std::endl;
        std::cin >> input;
        alpha = req->getAlpha2ByName(input);
    }


    std::cout << alpha;


    delete req;


}