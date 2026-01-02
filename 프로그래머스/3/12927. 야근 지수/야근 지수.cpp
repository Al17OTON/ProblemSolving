#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    for(int i = 0; i < works.size(); ++i) pq.push(works[i]);
    
    while(n-- > 0 && !pq.empty()) {
        int work = pq.top(); pq.pop();
        if(work == 1) continue;
        pq.push(work - 1);
    }
    
    while(!pq.empty()) {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}