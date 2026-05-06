#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Drone {
    int x1, y1, x2, y2;
};

int N;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
bool v[101][101][101][101] = {false};

bool is_out(int x, int y) {
    return x < 0 || x > N || y < 0 || y > N; 
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    N = board.size() - 1;
    
    queue<Drone> q;
    q.push({0, 0, 0, 1});
    
    bool flag = false;
    while(!q.empty()) {
        for(int size = q.size(); size > 0; --size) {
            Drone drone = q.front(); q.pop();
            int x1 = drone.x1;
            int x2 = drone.x2;
            int y1 = drone.y1;
            int y2 = drone.y2;
            if((x1 == N && y1 == N) || (x2 == N && y2 == N)) {
                flag = true;
                break;
            }
            if(v[x1][y1][x2][y2]) continue;
            v[x1][y1][x2][y2] = true;
            
            for(int d = 0; d < 4; ++d) {
                int nx1 = x1 + dr[d];
                int nx2 = x2 + dr[d];
                int ny1 = y1 + dc[d];
                int ny2 = y2 + dc[d];
                
                if(is_out(nx1, ny1) || is_out(nx2, ny2) || board[nx1][ny1] || board[nx2][ny2]) continue;
                
                q.push({nx1, ny1, nx2, ny2});
            }
            
            if(x1 == x2) {
                if(x1 + 1 <= N) {
                    if(!board[x1 + 1][y1 + 1] && !board[x1 + 1][y1]) q.push({x1, y1, x1 + 1, y1});
                    if(!board[x2 + 1][y2 - 1] && !board[x2 + 1][y2]) q.push({x2, y2, x2 + 1, y2});
                }
                if(x1 - 1 >= 0) {
                    if(!board[x1 - 1][y1 + 1] && !board[x1 - 1][y1]) q.push({x1 - 1, y1, x1, y1});
                    if(!board[x2 - 1][y2 - 1] && !board[x2 - 1][y2]) q.push({x2 - 1, y2, x2, y2});
                }
            } else {
                if(y1 - 1 >= 0) {
                    if(!board[x1 + 1][y1 - 1] && !board[x1][y1 - 1]) q.push({x1, y1 - 1, x1, y1});
                    if(!board[x2 - 1][y2 - 1] && !board[x2][y2 - 1]) q.push({x2, y2 - 1, x2, y2});
                }
                if(y1 + 1 <= N) {
                    if(!board[x1 + 1][y1 + 1] && !board[x1][y1 + 1]) q.push({x1, y1, x1, y1 + 1});
                    if(!board[x2 - 1][y2 + 1] && !board[x2][y2 + 1]) q.push({x2, y2, x2, y2 + 1});
                }
            }
        }
        if(flag) break;
        ++answer;
    }

    return answer;
}