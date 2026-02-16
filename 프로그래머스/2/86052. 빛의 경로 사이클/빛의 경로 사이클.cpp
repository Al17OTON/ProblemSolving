#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
bool visit[4][501][501];

int change_dir(int dir, char state) {
    if(state == 'S') return dir;
    else if(state == 'L') {
        return (dir + 4 - 1) % 4;
    } else {
        return (dir + 1) % 4;
    }
}

int dfs(int r, int c, int dir, int time, const vector<string>& grid) {
    if(visit[dir][r][c]) return time;
    visit[dir][r][c] = true;
    
    int next_dir = change_dir(dir, grid[r][c]);
    int nr = (r + dr[next_dir] + grid.size()) % grid.size();
    int nc = (c + dc[next_dir] + grid[0].size()) % grid[0].size();
    
    return dfs(nr, nc, next_dir, time + 1, grid);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    for(int r = 0; r < grid.size(); ++r) {
        for(int c = 0; c < grid[0].size(); ++c) {
            for(int d = 0; d < 4; ++d) {
                int travel = dfs(r, c, d, 0, grid);
                if(travel > 0) answer.push_back(travel);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}