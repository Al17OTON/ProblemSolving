#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int offset = 0; offset < s.size(); ++offset) {
        stack<char> st;
        bool flag = true;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[(i + offset) % s.size()];   
            if(c == '[' || c == '(' || c =='{') {
                st.push(c);
            } else {
                if(st.empty() || abs(c - st.top()) > 2) {
                    flag = false;
                    break;
                } else {
                    st.pop();
                }
            }
        }
        if(flag && st.empty()) ++answer;
    }
    
    return answer;
}