#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> st;
    
    for(char num : number) {
        if(st.empty() || st.top() >= num || k == 0) {
            st.push(num);
        } else {
            while(!st.empty() && st.top() < num && k > 0) {
                st.pop();
                --k;
            }
            st.push(num);
        }
    }
    while(k-- > 0) st.pop();
    
    while(!st.empty()) {
        answer = st.top() + answer;
        st.pop();
    }
    
    return answer;
}