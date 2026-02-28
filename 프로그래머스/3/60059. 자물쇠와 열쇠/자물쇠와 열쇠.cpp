#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
    int r, c;  
};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int target = 0;

bool bfs(const vector<Pos>& pos, const vector<vector<int>> lock) {
    bool v[51][51] = {false};
    queue<Pos> q;
    q.push({25, 25});
    
    while(!q.empty()) {
        Pos offset = q.front(); q.pop();
        
        if(abs(25 - offset.r) >= lock.size() || abs(25 - offset.c) >= lock.size() || v[offset.r][offset.c]) continue;
        v[offset.r][offset.c] = true;
        
        int count_fit = 0;
        for(int i = 0; i < pos.size(); ++i) {
            int r = pos[i].r + (offset.r - 25);
            int c = pos[i].c + (offset.c - 25);
            
            if(r < 0 || r >= lock.size() || c < 0 || c >= lock.size()) continue;
            if(lock[r][c] == 1) {
                break;
            }
            ++count_fit;
        }
        if(count_fit == target) return true;
        
        for(int d = 0; d < 4; ++d) {
            int nr = offset.r + dr[d];
            int nc = offset.c + dc[d];
            
            q.push({nr, nc});
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vector<Pos> pos;
    
    for(int r = 0; r < lock.size(); ++r) {
        for(int c = 0; c < lock.size(); ++c) {
            if(lock[r][c] == 0) ++target;
        }
    }
    
    for(int r = 0; r < key.size(); ++r) {
        for(int c = 0; c < key.size(); ++c) {
            if(key[r][c] == 1) pos.push_back({r, c});
        }
    }
    
    if(bfs(pos, lock)) return true;
    // 3번 90도 시계 방향 회전
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < pos.size(); ++j) {
            int nr = pos[j].c;
            int nc = abs(pos[j].r - ((int)lock.size() - 1));
            pos[j] = {nr, nc};
        }
        if(bfs(pos, lock)) return true;
    }
    
    return false;
}