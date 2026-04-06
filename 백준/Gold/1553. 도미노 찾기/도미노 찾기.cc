#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> map(8, "");
bool v[8][7] = {false};
bool check[7][7] = {false};
int answer = 0;

void dfs(int r, int c) {
    if(r == 7 && c == 6) {
        ++answer;
        return;
    }
    if(c == 7) {
        dfs(r + 1, 0);
    }
    else if(v[r][c]) {
        dfs(r, c + 1);
    }
    else {
        if(c + 1 < 7 && !v[r][c + 1] && !check[max(map[r][c] - '0', map[r][c + 1] -'0')][min(map[r][c] - '0', map[r][c + 1] -'0')]) {
            v[r][c + 1] = true;
            v[r][c] = true;
            check[max(map[r][c] - '0', map[r][c + 1] -'0')][min(map[r][c] - '0', map[r][c + 1] -'0')] = true;
            dfs(r, c + 1);
            v[r][c + 1] = false;
            v[r][c] = false;
            check[max(map[r][c] - '0', map[r][c + 1] -'0')][min(map[r][c] - '0', map[r][c + 1] -'0')] = false;
        }
        if(r + 1 < 8 && !v[r + 1][c] && !check[max(map[r][c] - '0', map[r + 1][c] -'0')][min(map[r][c] - '0', map[r + 1][c] -'0')]) {
            v[r + 1][c] = true;
            v[r][c] = true;
            check[max(map[r][c] - '0', map[r + 1][c] -'0')][min(map[r][c] - '0', map[r + 1][c] -'0')] = true;
            dfs(r, c + 1);
            v[r + 1][c] = false;
            v[r][c] = false;
            check[max(map[r][c] - '0', map[r + 1][c] -'0')][min(map[r][c] - '0', map[r + 1][c] -'0')] = false;
        }
    }
}

int main() {
    for(int i = 0; i < 8; ++i) {
        cin >> map[i];
    }

    dfs(0, 0);

    cout << answer;
}