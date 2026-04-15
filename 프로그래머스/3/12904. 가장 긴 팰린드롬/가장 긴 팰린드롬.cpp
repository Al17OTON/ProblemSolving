#include <string>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int answer = 1;
    
    for(int i = 0; i < s.size(); ++i) {
        for(int j = i + 1; j < s.size(); ++j) {
            if(answer >= j - i + 1) continue;
            int l = i, r = j;
            while(l < r && s[l] == s[r]) {
                l++;
                r--;
            }
            
            if(l >= r) answer = max(answer, j - i + 1);
        }
    }
    
    return answer;
}