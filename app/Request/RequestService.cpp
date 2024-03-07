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