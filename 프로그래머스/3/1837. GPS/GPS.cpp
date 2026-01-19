#include <vector>
#include <queue>
#include <memory.h>
#include <iostream>

using namespace std;

struct Taxi {
    int idx;
    int time;
    int diff;
    
    bool operator < (const Taxi& o) const {
        return this->diff > o.diff;
    }
};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int v[101][201];
    vector<int> adj[201];
    priority_queue<Taxi> pq;
    
    fill(v[0], v[101], 987654321);
    
    for(int i = 0; i < m; ++i) {
        int a = edge_list[i][0];
        int b = edge_list[i][1];
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    pq.push({gps_log[0], 0, 0});
    v[0][gps_log[0]] = 0;
    
    while(!pq.empty()) {
        Taxi taxi = pq.top(); pq.pop();
        
        if(taxi.time == k - 1) {
            if(taxi.idx == gps_log.back()) return taxi.diff;
            continue;
        } 
        
        int log = gps_log[taxi.time + 1];
        
        for(int i = 0; i < adj[taxi.idx].size(); ++i) {
            int next = adj[taxi.idx][i];
            int diff = (log == next) ? taxi.diff : taxi.diff + 1;
            
            if(v[taxi.time + 1][next] > diff) {
                v[taxi.time + 1][next] = diff;
                pq.push({next, taxi.time + 1, diff});
            }
        }
        
        pq.push({taxi.idx, taxi.time + 1, (log == taxi.idx ? taxi.diff : taxi.diff + 1)});
    }
    
    return -1;
}





