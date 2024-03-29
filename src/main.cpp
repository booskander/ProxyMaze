#include "ProxyDebianService.hpp"

int main(int argc, char** argv) {

    auto r = new ProxyDebianService();
    r->displayCountries();

    delete r;


    return 0;
}