#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Route {
    int r, c;
    int curv; // 몇번 꺾었는지
    int req; // 해당 경로를 사용하기 위해 제거되어야하는 타일 비트마스킹
    int pre;
};

int dr[] = { 0, -1, 1, 0, 0 };
int dc[] = { 0, 0, 0, -1, 1 };
int M, N;
vector<int> req_vec[26];

void bfs(int r, int c, const vector<string>& map) {
    queue<Route> q;
    q.push({ r, c, 0, 0, 0 });

    int idx = map[r][c] - 'A';

    while (!q.empty()) {
        Route p = q.front(); q.pop();

        if (p.curv == 2) continue;
        if (!(p.r == r && p.c == c) && map[p.r][p.c] == map[r][c]) {
            req_vec[idx].push_back(p.req);
            continue;
        }

        for (int i = 1; i <= 4; ++i) {
            if ((p.pre == 1 && (i == 2 || (p.curv == 1 && i > 2))) ||
                (p.pre == 2 && (i == 1 || (p.curv == 1 && i > 2))) ||
                (p.pre == 3 && (i == 4 || (p.curv == 1 && i <= 2))) ||
                (p.pre == 4 && (i == 3 || (p.curv == 1 && i <= 2)))
                ) continue;

            int nr = p.r + dr[i];
            int nc = p.c + dc[i];

            if (nr >= M || nr < 0 || nc >= N || nc < 0 || map[nr][nc] == '*') continue;
            int curv = p.curv;
            int req = p.req;
            if ((p.pre == 1 || p.pre == 2 && i > 2) || (p.pre > 2 && i <= 2)) ++curv;
            if (map[nr][nc] != '.' && !(req & (1 << (map[nr][nc] - 'A'))) && map[nr][nc] != map[r][c]) {
                req |= 1 << (map[nr][nc] - 'A');
            }

            q.push({ nr, nc, curv, req, i });

        }

    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> map) {
    string answer = "";

    for (int i = 0; i < 26; ++i) req_vec[i].clear();
    M = m;
    N = n;

    int alpha = 0;
    for (int r = 0; r < M; ++r) {
        for (int c = 0; c < N; ++c) {
            if (map[r][c] >= 'A' && map[r][c] <= 'Z' && !(alpha & (1 << (map[r][c] - 'A')))) {
                bfs(r, c, map);
                alpha |= 1 << (map[r][c] - 'A');
            }
        }
    }

    int bit = 0;
    while (alpha) {
        bool flag = true;
        for (int i = 0; i < 26 && flag; ++i) {
            if (!(alpha & (1 << i))) continue;
            for (int j = 0; j < req_vec[i].size(); ++j) {
                if (!(bit ^ (req_vec[i][j] | bit))) {
                    bit |= 1 << i;
                    alpha ^= 1 << i;
                    answer += ('A' + (char)i);
                    flag = false;
                    break;
                }
            }
        }
        if (flag && alpha) break;
    }
    if (alpha) answer = "IMPOSSIBLE";

    return answer;
}