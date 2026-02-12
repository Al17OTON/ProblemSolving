#include <algorithm>
#include <vector>

using namespace std;

int M;
int dr[] = {-1, 1, 0, 0, 0};
int dc[] = {0, 0, -1, 1, 0};

void rotate(const pair<int, int> target, int time, vector<vector<int>>& map) {
    if(time == 0) return;
    for(int d = 0; d < 5; ++d) {
        int nr = target.first + dr[d];
        int nc = target.second + dc[d];
        if(M <= nr || nr < 0 || M <= nc || nc < 0) continue;
        map[nr][nc] = (map[nr][nc] + time) % 4;
    }
}

bool check(const vector<vector<int>>& map) {
    for(int r = 0; r < M; ++r) {
        for(int c = 0; c < M; ++c) {
            if(map[r][c] != 0) return false;
        }
    }
    return true;
}

int row_rotate(int row, int turn, vector<vector<int>>& map) {
    if(row == M) {
        return check(map) ? turn : 987654321;
    }
    for(int col = 0; col < M; ++col) {
        int time = (4 - map[row - 1][col]) % 4;
        rotate({row, col}, time, map);
        turn += time;
    }
    return row_rotate(row + 1, turn, map);
}

int first_row(int col, int turn, vector<vector<int>>& map) {
    if(col == M) {
        vector<vector<int>> copy(map);
        return row_rotate(1, turn, copy);
    }
    int minimum = 987654321;
    minimum = min(minimum, first_row(col + 1, turn, map));
    for(int ro = 1; ro <= 3; ++ro) {
        rotate({0, col}, 1, map);
        minimum = min(minimum, first_row(col + 1, turn + ro, map));
    }
    rotate({0, col}, 1, map);
    
    return minimum;
}

int solution(vector<vector<int>> clockHands) {
    M = clockHands.size();
    
    return first_row(0, 0, clockHands);
}

