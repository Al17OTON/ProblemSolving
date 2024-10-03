#include <string>
#include <vector>
#include <deque>
#define MAX 201

using namespace std;

bool v[MAX] = {false};
int answer = 0, N;
vector<vector<int>>* adj;

void bfs(const int node) {
    deque<int> q;
    v[node] = true;
    q.push_back(node);
    int p;
    while(!q.empty()) {
        p = q.front(); q.pop_front();
        for(int i = 0; i < N; i++) {
            if(i == p || v[i] || (*adj)[p][i] == 0) continue;
            v[i] = true;
            q.push_back(i);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    
    adj = &computers;
    N = n;
    
    for(int i = 0; i < n; i++) {
        if(!v[i]) {
            answer++;
            bfs(i);
        }
    }
    
    
    return answer;
}