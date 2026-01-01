#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    int idx;
    int w;
    
    bool operator < (const Node& o) const {
        return this->w > o.w;
    }
};

vector<int> adj[20001];
int dist[20001];
priority_queue<Node> pq;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int m = 0;
    for(int i = 0; i < edge.size(); ++i) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    fill(dist + 2, dist + n + 1, 987654321);
    pq.push({1, 0});
    
    while(!pq.empty()) {
        Node p = pq.top(); pq.pop();
        
        if(dist[p.idx] < p.w) continue;
        
        for(int i = 0; i < adj[p.idx].size(); ++i) {
            int to = adj[p.idx][i];
            if(dist[to] > p.w + 1) {
                dist[to] = p.w + 1;
                m = max(m, dist[to]);
                pq.push({to, dist[to]});
            }
        }
        
    }
    
    for(int i = 1; i <= n; ++i) {
        if(dist[i] == m) ++answer;
    }
    
    return answer;
}