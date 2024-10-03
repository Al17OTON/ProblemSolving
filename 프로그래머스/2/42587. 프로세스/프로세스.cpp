#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

bool compare(int a, int b) {return a > b;}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int,int>> dq;
    
    int stack_top = 0;
    vector<int> stack = priorities;
    sort(stack.begin(), stack.end(), compare);
    for(int i = 0; i < priorities.size(); i++) dq.push_back({priorities[i], i});
    
    while(true) {
        pair<int,int> front = dq.front();
        dq.pop_front();
        if(front.first == stack[stack_top]) {
            stack_top++;
            if(front.second == location) {
                answer = stack_top;
                break;
            }
        } else {
            dq.push_back(front);
        }
        
    }
    
    
    return answer;
}