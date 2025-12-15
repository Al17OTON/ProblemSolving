#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int bfs(vector<vector<int>>& map) {
    queue<pair<int,int>> q;
    q.push({0, 0});
    map[0][0] = 0;
    
    int turn = 1;
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; ++i) {
            pair<int,int> p = q.front(); q.pop();
            
            if(p.first == map.size() - 1 && p.second == map[0].size() - 1) return turn;
            for(int d = 0; d < 4; ++d) {
                int nr = p.first + dr[d];
                int nc = p.second + dc[d];
                
                if(nr >= map.size() || nr < 0 || nc >= map[0].size() || nc < 0 || map[nr][nc] == 0) continue;
                map[nr][nc] = 0;
                q.push({nr, nc});
            }
            
        }
        ++turn;
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    return bfs(maps);
}