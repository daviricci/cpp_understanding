#include "core.cpp"

int main(int argc, char** argv) {
    while(true){
        print_one_hundred_s1();
        std::string s;
        std::cin>>s;
        if(s=="0")break;
    }
    return 0;
}
