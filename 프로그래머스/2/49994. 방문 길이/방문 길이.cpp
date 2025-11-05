#include <string>

using namespace std;

bool v[11][11][11][11] = {false};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int solution(string dirs) {
    int answer = 0;
    
    int r = 5, c = 5;
    for(int i = 0; i < dirs.size(); ++i) {
        int dir;
        if(dirs[i] == 'U') dir = 0;
        else if(dirs[i] == 'D') dir = 1;
        else if(dirs[i] == 'L') dir = 2;
        else dir = 3;
        
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        
        if(nr < 0 || nr >= 11 || nc < 0 || nc >= 11) continue;
        
        if(!v[r][c][nr][nc]) {
            v[r][c][nr][nc] = true;
            v[nr][nc][r][c] = true;
            ++answer;
        }
        
        r = nr;
        c = nc;
    }
    
    return answer;
}