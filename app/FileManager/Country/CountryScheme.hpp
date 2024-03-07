#ifndef COUNTRY_HPP
#define COUNTRY_HPP
#include <string>
class Country {

private:

    std::string name_;
    std::string alpha2ISO_;
    
public:

    Country(const std::string& name, const std::string& iso) : name_(name), alpha2ISO_(iso) {}

    static Country* factory(std::string& name, std::string iso) {
        return new Country(name, iso);
    } 
};

#endif