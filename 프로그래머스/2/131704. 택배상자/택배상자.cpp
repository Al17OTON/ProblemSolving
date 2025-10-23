#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    queue<int> q;
    stack<int> s;
    
    for(int i = 1; i <= order.size(); ++i) {
        q.push(i);
    }
    
    for(int i = 0; i < order.size(); ++i) {
        int target = order[i];
        
        if(!q.empty() && target == q.front()) {
            q.pop();
            ++answer;
        } else if(!s.empty() && target == s.top()) {
            s.pop();
            ++answer;
        } else if(!q.empty()) {
            s.push(q.front());
            q.pop();
            --i;
        } else {
            break;
        }
        
    }
    
    
    return answer;
}