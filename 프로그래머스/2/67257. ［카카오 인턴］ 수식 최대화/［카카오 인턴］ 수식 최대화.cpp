#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <iostream>

using namespace std;

char priority[6][3] = {
    {'*', '+', '-'},
    {'*', '-', '+'},
    {'-', '*', '+'},
    {'-', '+', '*'},
    {'+', '-', '*'},
    {'+', '*', '-'}
};

long long solution(string expression) {
    long long answer = 0;
    stack<long long> nums;
    stack<char> oper;
    int i, j;
    for(i = expression.size() - 1, j = expression.size() - 1; i >= 0; --i) {
        char c = expression[i];
        if(c == '+' || c == '-' || c == '*') {
            nums.push(stoi(expression.substr(i + 1, j - i)));
            oper.push(c);
            j = i - 1;
        }
    }
    nums.push(stoi(expression.substr(i + 1, j - i)));

    for(i = 0; i < 6; ++i) {
        stack<long long> a1(nums), a2;
        stack<char> b1(oper), b2;
        for(j = 0; j < 3; ++j) {
            while(!b1.empty()) {
                char o = b1.top(); b1.pop();
                long long first = a1.top(); a1.pop();
                long long second = a1.top();
                if(o == priority[i][j]) {
                    a1.pop();
                    if(o == '*') a1.push(first * second);
                    else if(o == '+') a1.push(first + second);
                    else a1.push(first - second);
                } else {
                    a2.push(first);
                    b2.push(o);
                }
            }
            
            while(!a2.empty()) {
                a1.push(a2.top());
                a2.pop();
            }
            while(!b2.empty()) {
                b1.push(b2.top());
                b2.pop();
            }
        }
        answer = max(answer, abs(a1.top()));
    }
    
    return answer;
}