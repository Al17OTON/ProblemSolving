#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

struct Delivery {
    int town;
    int time;
    
    bool operator < (const Delivery& o) const {
        return this->time > o.time;
    }
};

int adj[51][51];
bool v[51];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    memset(adj, 500009, sizeof(adj));
    for(int i = 0; i < road.size(); ++i) {
        int from = road[i][0];
        int to = road[i][1];
        int cost = road[i][2];
        if(adj[from][to] > cost) {
            adj[from][to] = cost;
            adj[to][from] = cost;
        }
    }

    priority_queue<Delivery> pq;
    pq.push({1, 0});
    while(!pq.empty()) {
        Delivery p = pq.top(); pq.pop();
        
        if(v[p.town] || p.time > K) continue;
        v[p.town] = true;
        ++answer;
        
        for(int next = 1; next <= N; ++next) {
            pq.push({next, p.time + adj[p.town][next]});
        }
    }
    
    
    return answer;
}