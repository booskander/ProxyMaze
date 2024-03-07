#ifndef PROXY_DEBIAN
#define PROXY_DEBIAN
#include <cstdlib>
#include <fstream>
#include <iostream>
class ProxyDebianService {
private:
    std::string configFile = "/etc/proxychains.conf";

public:

    ProxyDebianService() {}

    void addProxyGate(std::string proxyType, std::string IP, std::string port);

    void catFile() {
        system("cat /etc/proxychains.conf");
    }
};



#endif