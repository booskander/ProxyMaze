#include "RequestService.hpp"

const std::string RequestService::getAlpha2ByName(std::string& name) {
    
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    auto it = std::find_if(
        countries.begin(),
        countries.end(),
        [name](Country* country) {
            std::string countryName = country->getName();
            
            return country->getName() == name;
    });


    if (it != countries.end()) {

        if ((*it)->getName() == "Israel") {
            throw NotCountryException("Fuck Israel");
        }

        return (*it)->getAlpha2();

    } else {
        std::cerr << "This is not a country" << std::endl;
        return "";
    }
}

void RequestService::displayCountries() const {

    std::for_each(countries.begin(), countries.end(), [](auto country) {
        std::cout << country << std::endl;
    });
}

std::string RequestService::forgeRequest(std::string protocol, std::string country, bool SSL) {
    
    if (country != "all") {
        country = this->getAlpha2ByName(country);
    }

    std::string sslParam = SSL ? "yes" : "no";

    return this->baseURL + protocol + "&timeout=10000&country=" + country + "&ssl=" + sslParam + "anonymity=all";
}


void RequestService::fetchProxies(std::string protocol, std::string country, bool SSL) {
    std::string command = "curl --location";
    std::string url = this->forgeRequest(protocol, country, SSL);
    
    system(url.c_str());
}