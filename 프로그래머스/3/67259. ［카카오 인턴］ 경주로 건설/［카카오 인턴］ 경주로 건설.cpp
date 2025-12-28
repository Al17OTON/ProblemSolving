#include <string>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

struct Node {
    int cost;
    int pre;
    int r, c;
    
    bool operator < (const Node& o) const {
        return this->cost > o.cost;
    }
};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int cost[5][5] = {
    {100, 100, 600, 600, 100},
    {100, 100, 600, 600, 100},
    {600, 600, 100, 100, 100},
    {600, 600, 100, 100, 100},
    {100, 100, 100, 100, 100}
};

int bfs(const vector<vector<int>>& board) {
    int v[26][26][5];
    memset(v, -1, sizeof(v));
    priority_queue<Node> pq;
    
    v[0][0][4] = true;
    pq.push({0, 4, 0, 0});
    
    while(!pq.empty()) {
        Node p = pq.top(); pq.pop();
        
        if(p.r == p.c && p.r == board.size() - 1) {
            return p.cost;
        }
        
        for(int d = 0; d < 4; ++d) {
            int nr = p.r + dr[d];
            int nc = p.c + dc[d];
            
            if(nr >= board.size() || nr < 0 || nc >= board.size() || nc < 0 || board[nr][nc] == 1 || (v[nr][nc][d] != -1 && v[nr][nc][d] <= p.cost + cost[p.pre][d])) continue;
            v[nr][nc][d] = p.cost + cost[p.pre][d];
            pq.push({p.cost + cost[p.pre][d], d, nr, nc});  
        }
    }
    return -1;
}


int solution(vector<vector<int>> board) {
    return bfs(board);
}