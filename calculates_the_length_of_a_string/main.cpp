#include <iostream>
#include "core.h"
int main() {
    while(true){
        std::string s;
        std::cin>>s;
        if(s=="0")break;
        std::cout << core::CalculatesStringLength(s)<<std::endl;
    }
    return 0;
}
