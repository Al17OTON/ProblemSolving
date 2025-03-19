#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    priority_queue<int> pq;
    
    for(int i = people.size() - 1; i >= 0; i--) {
        int w = people[i];
        if(!pq.empty() && pq.top() >= w) pq.pop();
        else {
            answer++;
            pq.push(limit - w);
        }
    }
    
    
    return answer;
}