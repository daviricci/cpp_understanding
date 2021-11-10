#include "core.h"
namespace core{
    int CalculatesStringLength(const std::string& s){
        int length = 0;
        while ( s.c_str()[length]!='\0'){
            length += 1;
        }
        return  length;
    }
    std::string SliceString(std::string s, int i, int j){
        if (i==j)return std::string(1,s[i]);
        return std::string(1,s[i]).append(SliceString(s, i + 1, j));
    }
    std::string RevertString(std::string input){
        int length = CalculatesStringLength(input)-1;
        if (length==0){return input;}
        return std::string(1,input[length]).append(RevertString(SliceString(input, 0, length - 1)));
    }

}