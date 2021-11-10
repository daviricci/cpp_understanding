#include <string>
#include <iostream>
namespace {
    void print_one_hundred_s1(){
        std::string values[101];
        for (int i = 1; i <= 100; ++i) {values[i] = std::to_string(i);} //one hundred operations
        for (int i = 1;i<=33;i++){values[i*3] = "Foo";}// thirty three operations
        for (int i=1;i<=20;i++){values[i*5] = "Baa";}//twenty operations
        for (int i=1;i<=6;i++){values[i*15] = "FooBaa";}//fifty operations
        for (int i = 1; i <= 100; ++i) {std::cout<<values[i]<<std::endl;}//one hundred operations
    }
}

