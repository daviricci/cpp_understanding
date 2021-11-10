#include "testing.h"
#include "../core.cpp"
#define IS_TRUE(x) { if (!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; \
                    if ((x)) std::cout << __FUNCTION__ << " has successful on line " << __LINE__ << std::endl;}
namespace testing_ConcatRemove{

    bool try_ConcatRemove(const std::string& s, const std::string& t, int k, const std::string& resp) {
        return core::ConcatRemove(s,t,k) == resp;
    }

    void test()
    {
        IS_TRUE(try_ConcatRemove("blablablabla","blablabcde",8,"yes"));
        IS_TRUE(try_ConcatRemove("tab","tab",7,"yes"));
        IS_TRUE(try_ConcatRemove("davi","daniel",6,"yes"));
        IS_TRUE(try_ConcatRemove("d&4i","d&4iel",6,"no"));
        IS_TRUE(try_ConcatRemove("d&4i","d&4iel",6,"no"));
        IS_TRUE(try_ConcatRemove("Davi","Dalva",10,"no"));
        IS_TRUE(try_ConcatRemove("abracadabra","olhodecabra",5,"no"));
    }

}