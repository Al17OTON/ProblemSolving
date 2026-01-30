#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> map1, map2;

bool is_alpha(char c) {
    return 'A' <= c && 'Z' >= c || 'a' <= c && 'z' >= c;
}

int solution(string str1, string str2) {  
    for(int i = 1; i < str1.size(); ++i) {
        char pre = str1[i - 1];
        char cur = str1[i];
        
        if(is_alpha(pre) && is_alpha(cur)) {
            pre = tolower(pre);
            cur = tolower(cur);
            string key = "";
            key += pre;
            key += cur;
            ++map1[key];
        }        
    }
    for(int i = 1; i < str2.size(); ++i) {
        char pre = str2[i - 1];
        char cur = str2[i];
        
        if(is_alpha(pre) && is_alpha(cur)) {
            pre = tolower(pre);
            cur = tolower(cur);
            string key = "";
            key += pre;
            key += cur;
            ++map2[key];
        }        
    }
    
    if(map1.size() == 0 && map2.size() == 0) return 65536;
    
    double inter = 0, uni = 0;
    unordered_map<string, int>::iterator iter, tmp;
    // 교집합 구하기
    for(iter = map1.begin(); iter != map1.end(); ++iter) {
        tmp = map2.find(iter->first);
        if(tmp != map2.end()) {
            inter += min(iter->second, tmp->second);
        }
    }
    
    // 합집합 구하기
    for(iter = map1.begin(); iter != map1.end(); ++iter) {
        tmp = map2.find(iter->first);
        if(tmp != map2.end()) {
            tmp->second = max(tmp->second, iter->second);
        } else {
            map2[iter->first] = iter->second;
        }
    }
    
    for(iter = map2.begin(); iter != map2.end(); ++iter) {
        uni += iter->second;
    }
    
    return (int)((inter / uni) * 65536);
}



