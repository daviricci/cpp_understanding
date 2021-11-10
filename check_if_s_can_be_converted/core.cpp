
#include "core.h"

namespace core{

    bool check_if_chars_in_az_ascii(const std::string &s){
        int ascii_char = -1;
        const char *p_s = s.c_str();
        bool resp = false;
        for (int i=0;i<s.length();i++){
            ascii_char = (int)p_s[i];
            resp = (ascii_char <= 122)&&(ascii_char>=97);
            if (!resp){return resp;}
        }
        return resp;
    }

    std::string ConcatRemove(const std::string& s, const std::string& t, int k){
        if ((k>100)||(k<1)){return "no";}
        int l_min = std::min(s.length(), t.length());if(l_min<1){return "no";}
        int l_max = std::max(s.length(), t.length());if(l_max>100){return "no";}
        if (!check_if_chars_in_az_ascii(s)){return "no";}
        if (!check_if_chars_in_az_ascii(t)){return "no";}
        const char *p_s = s.c_str();
        const char *p_t = t.c_str();
        int l_similarity_now = 0;
        int l_similarity_next = 1;
        while (((l_similarity_next - l_similarity_now) == 1) && (l_similarity_next <= l_min)){
            l_similarity_now = (p_s[l_similarity_next - 1] == p_t[l_similarity_next - 1]) ? l_similarity_next : l_similarity_now;
            l_similarity_next+=1;
        }
        int n_min_remove = s.length() - l_similarity_now;
        int n_min_concat = t.length() - l_similarity_now;
        int n_min_total_mov = n_min_remove + n_min_concat;
        if (n_min_total_mov<=k){
            return "yes";
        }
        else{
            return "no";
        }
    }
}

