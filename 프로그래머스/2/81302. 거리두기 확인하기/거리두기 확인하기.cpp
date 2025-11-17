#include <string>
#include <vector>

using namespace std;

int v[5][5] = {0};
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool dfs(int r, int c, int dist, int id, const vector<string>& map) {
    if(dist == 3) return true;
    if(map[r][c] == 'P' && dist != 0) return false;
    
    v[r][c] = id;
    
    for(int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr >= 5 || nr < 0 || nc >= 5 || nc < 0 || v[nr][nc] == id || map[nr][nc] == 'X') continue;
        if(!dfs(nr, nc, dist + 1, id, map)) return false;
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int id = 1;
    for(int i = 0; i < places.size(); ++i) {
        bool result = true;
        for(int r = 0; r < places[i].size(); ++r) {
            for(int c = 0; c < places[i][r].size(); ++c) {
                if(places[i][r][c] == 'P' && !dfs(r, c, 0, id++, places[i])) {
                    result = false;
                    break;
                } 
            }
            if(!result) break;
        }
        answer.push_back(result ? 1 : 0);
    }
    
    
    return answer;
}