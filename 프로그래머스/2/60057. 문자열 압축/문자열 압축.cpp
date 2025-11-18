#include <string>
#include <vector>
#include <cmath>

using namespace std;

int compression(const string& s, int l) {
    int length = s.size(), count = 1;
    string pre = "", cur = "";
    for(int i = 0; i < s.size(); ++i) {
        cur += s[i];
        if(cur.size() == l) {
            if(pre.compare(cur) == 0) {
                length -= l;
                ++count;
            } else {
                pre = cur;
                if(count > 1) length += (int)to_string(count).size();
                count = 1;
            }
            cur = "";
        }
    }
    
    if(count > 1) length += (int)to_string(count).size();
    
    return length;
}

int solution(string s) {
    int answer = s.size();
    
    for(int i = 1; i <= s.size() / 2; ++i) {
        answer = min(answer, compression(s, i));
    }
    
    return answer;
}