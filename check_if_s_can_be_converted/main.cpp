#include "core.h"
int main(int argc, char** argv) {
    while (true){
        std::string s;
        std::string t;
        int k;
        std::cin>>s;
        if(s=="0")break;
        std::cin>>t;
        if(t=="0")break;
        std::cin>>k;
        std::cout<<core::ConcatRemove(s,t,k)<<std::endl;
    }
    return 0;
}
