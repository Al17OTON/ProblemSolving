#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

bool v[10][10];
int N, M;

bool dfs(int cnt, int dist, vector<vector<int>>& sel) {
    if (cnt == 0) return true;
    
    for (int r = (sel.empty() ? 0 : sel.back()[0]); r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (v[r][c]) continue;
            bool flag = true;
            for (int i = 0; i < sel.size(); ++i) {
                if (abs(sel[i][0] - r) + abs(sel[i][1] - c) < dist) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                v[r][c] = true;
                sel.push_back({ r, c });
                if (dfs(cnt - 1, dist, sel)) return true;
                sel.pop_back();
                v[r][c] = false;
            }
        }
    }
    return false;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> timetable) {
    if (n == 1) return 0;
    N = n;
    M = m;

    memset(v, 0, sizeof(v));
    sort(timetable.begin(), timetable.end());

    int max_cnt = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < timetable.size(); ++i) {
        while (!pq.empty() && pq.top() < timetable[i][0]) {
            pq.pop();
        }
        pq.push(timetable[i][1]);
        max_cnt = max(max_cnt, (int)pq.size());
    }

    // vector<vector<int>> vec;
    if (max_cnt <= 1) return 0;

    for (int dist = (n - 1) * 2; dist >= 1; --dist) {
        // if (dfs(max_cnt, dist, vec)) return dist;
        for(int r = 0; r < N; ++r) {
            for(int c = 0; c < N; ++c) {
                vector<vector<int>> vec({{r, c}});
                for(int rr = r; rr < N; ++rr) {
                    for(int cc = 0; cc < N; ++cc) {
                        if(r != rr || cc > c) {
                            bool flag = true;
                            for(int i = 0; i < vec.size(); ++i) {
                                if((abs(vec[i][0] - rr) + abs(vec[i][1] - cc)) < dist) {
                                    flag = false;
                                    break;
                                }
                            }
                            if(flag) {
                                vec.push_back({rr, cc});
                                if(max_cnt == vec.size()) return dist;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}