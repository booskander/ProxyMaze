#pragma once
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "FileManager.hpp"
class ProxyDebianService {
private:
    std::string configFile = "/etc/proxychains.conf";
    FileManager* fm = new FileManager("../data/all.json");

public:

    ProxyDebianService() {}

    void addProxyGate(std::string proxyType, std::string IP, std::string port);

    void catFile() {
        system("cat /etc/proxychains.conf");
    }

    void displayCountries() {
        auto countrieslist = this->fm->getCountries();
        for (auto&& ctr : countrieslist)
            std::cout << ctr << std::endl;
    }

    ~ProxyDebianService() {
        delete fm;
    }
};
