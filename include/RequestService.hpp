#ifndef REQUEST_SERVICE
#define REQUEST_SERVICE
#include "FileManager.hpp"
#include <algorithm>
#include <cctype>
// #include "httplib.h"
// #include "httplib/httplib.h"
class RequestService {
private:
    std::string baseURL = "https://api.proxyscrape.com/v2/?request=displayproxies&protocol=";
    FileManager* fm_;
    std::vector<Country*> countries;

private:

public:
    RequestService(char* path) {
        fm_ = new FileManager(path);
        countries = fm_->getCountries();
    }

    const std::string getAlpha2ByName(std::string& name);

    void displayCountries() const;

    std::string forgeRequest(std::string protocol = "all", std::string country="all", bool SSL);

    void fetchProxies(std::string protocol = "all", std::string country="all", bool SSL);

    ~RequestService() {
        std::for_each(countries.begin(), countries.end(), [](auto country) {
            delete country;
        });
    }
};


class NotCountryException: public std::exception {
    const char* message_;
public:
    NotCountryException(const char* message): std::exception(), message_(message) {}

    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return message_;
    }
};

#endif