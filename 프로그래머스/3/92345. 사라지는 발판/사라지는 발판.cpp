#include <vector>
#include <algorithm>

using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int R, C;

bool check_out(int r, int c) {
    return r < 0 || r >= R || c < 0 || c >= C;
}

int dfs(int map, int a, int b, int turn) {
    int r, c, n_map = map;
    bool flag = (turn % 2 == 0);
    if(flag) {
        r = a / C;
        c = a % C;
        n_map ^= 1 << a;
        if(!(map & (1 << a))) return turn;
    } else {
        r = b / C;
        c = b % C;
        n_map ^= 1 << b;
        if(!(map & (1 << b))) return turn;
    }
    
    bool move_check = false;
    int win_best = 987654321;
    int lose_best = -1;
    for(int d = 0; d < 4; ++d) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        int pos = nr * C + nc;
        
        if(check_out(nr, nc) || !(map & (1 << pos))) continue;
        
        move_check = true;
        int res = dfs(n_map, (flag ? pos : a), (flag ? b : pos), turn + 1);
        
        bool result_flag = (res % 2 == 0);
        // lose
        if(flag == result_flag) {
            lose_best = max(lose_best, res);
        // win
        } else {
            win_best = min(win_best, res);
        }
    }
    if(!move_check) return turn;
    
    return win_best == 987654321 ? lose_best : win_best;
    
} 

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    R = board.size();
    C = board[0].size();
    int map = 0;
    for(int r = 0; r < R; ++r) {
        for(int c = 0; c < C; ++c) {
            map |= board[r][c] << (r * C + c);
        }
    }
    int a_pos = aloc[0] * C + aloc[1];
    int b_pos = bloc[0] * C + bloc[1];
    
    return dfs(map, a_pos, b_pos, 0);
}