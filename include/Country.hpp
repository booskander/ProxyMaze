#pragma once
#include <string>
#include <iostream>
class Country {

private:

    std::string name_;
    std::string alpha2ISO_;
    
public:

    Country(const std::string& name, const std::string& iso) : name_(name), alpha2ISO_(iso) {}

    const std::string getName() const { return this->name_; }

    const std::string getAlpha2() const { return this->alpha2ISO_; }

    static Country* factory(const std::string& name, const std::string& iso) {
        return new Country(name, iso);
    }

    friend inline std::ostream &operator<<(std::ostream &os, const Country* country) { 
        return os << country->getName() << std::endl;
    }

     
};
