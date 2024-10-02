#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int stack = 0;
    char c;
    for(int i = 0; i < s.length(); i++) {
        c = s[i];
        if(c == '(') stack++;
        else if(--stack < 0) {
            answer = false;
            break;
        }
    }
    

    return stack == 0 ? answer : false;
}