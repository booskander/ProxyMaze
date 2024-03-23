#include "ProxyDebianService.hpp"


void ProxyDebianService::addProxyGate(std::string proxyType, std::string IP, std::string port) {
    std::fstream fs;

    try {

        fs.open(configFile, std::fstream::out | std::fstream::app);
        if (fs.is_open()) {
            std::string format = proxyType + " " + IP + " " + port + '\n';
            fs << format;
            fs << std::endl;
            fs.close();
        } else {
            std::cerr << "File is closed already" << std::endl;
        }
    } catch (std::exception* e) {
        std::cerr << e->what();
    }  
}