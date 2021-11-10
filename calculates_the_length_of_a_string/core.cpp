#include "core.h"
namespace core{
    int CalculatesStringLength(const std::string& s){
        int length = 0;
        while ( s.c_str()[length]!='\0'){
            length += 1;
        }
        return  length;
    }
}