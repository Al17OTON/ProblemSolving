#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int map[102][102];
int mini;
int tmp1, tmp2;

void swap(int x1, int y1, int x2, int y2) {
    int tmp = map[y1][x1];
    map[y1][x1] = map[y2][x2];
    map[y2][x2] = tmp;
    mini = min({mini, map[y1][x1], map[y2][x2]});
}

int rotate(const vector<int> q) {
    mini = 987654321;
    int y = q[0];
    int x = q[1];
    
    while(++y <= q[2]) {
        swap(x, y, x, y - 1);
    }
    --y;
    while(++x <= q[3]) {
        swap(x, y, x - 1, y);
    }
    --x;
    while(--y >= q[0]) {
        swap(x, y, x, y + 1);
    }
    ++y;
    while(--x > q[1]) {
        swap(x, y, x + 1, y);
    }
    return mini;
}

vector<int> solution(int row, int col, vector<vector<int>> queries) {
    vector<int> answer;
    tmp1 = row;
    tmp2 = col;
    for(int i = 1; i <= row; ++i) {
        for(int j = 1; j <= col; ++j) {
            map[i][j] = (i - 1) * col + j;        
        }
    }
    
    for(int i = 0; i < queries.size(); ++i) {
        answer.push_back(rotate(queries[i]));
    }
    
    return answer;
}