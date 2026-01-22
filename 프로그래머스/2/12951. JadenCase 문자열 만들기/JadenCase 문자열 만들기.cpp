#include <string>
#include <vector>

using namespace std;

char change(char c) {
    if(c >= 'A' && c <= 'Z') return 'a' + (c - 'A');
    return c;
}
char first_change(char c) {
    if(c >= 'a' && c <= 'z') return 'A' + (c - 'a');
    return c;
}

string solution(string s) {
    string answer = "";
    
    bool first = true;
    for(int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if(c == ' ') {
            answer += c;
            first = true;
        }
        else if(first) {
            answer += first_change(c);
            first = false;
        } else {
            answer += change(c);
        }
    }
    
    return answer;
}