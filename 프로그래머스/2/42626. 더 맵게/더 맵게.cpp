#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    // while(!pq.empty()) {
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }
    
    while(!pq.empty() && pq.top() < K) {
        int a = pq.top(); pq.pop();
        if(pq.empty()) {
            answer = -1;
            break;
        }
        int b = pq.top() * 2; pq.pop();
        pq.push(a + b);
        answer++;
    }
    
    
    
    return answer;
}