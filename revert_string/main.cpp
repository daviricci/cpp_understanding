#include <iostream>
#include "core.h"
int main() {
    while (true){
        std::string name;
        std::cin>>name;
        if (name=="0")break;
        std::cout << core::RevertString(name) << std::endl;
    }
    return 0;
}
