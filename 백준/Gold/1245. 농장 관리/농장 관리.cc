#include <iostream>
#include <queue>

using namespace std;

int N, M, answer = 0;
bool v[101][71] = {false};
int map[101][71];
int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

bool bfs(int r, int c) {
    queue<pair<int,int>> q;
    q.push({r, c});

    bool result = true;
    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();

        if(map[r][c] == map[p.first][p.second]) {
            if(v[p.first][p.second]) continue;
            v[p.first][p.second] = true;

            for(int i = 0; i < 8; ++i) {
                int nr = p.first + dr[i];
                int nc = p.second + dc[i];

                if(nr >= N || nr < 0 || nc >= M || nc < 0) continue;
                q.push({nr, nc});
            }
        } else if(map[r][c] < map[p.first][p.second]) {
            result = false;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int n = 0; n < N; ++n) {
        for(int m = 0; m < M; ++m) {
            cin >> map[n][m];
        }
    }

    for(int n = 0; n < N; ++n) {
        for(int m = 0; m < M; ++m) {
            if(v[n][m]) continue;
            if(bfs(n, m)) ++answer;
        }
    }

    cout << answer;
}