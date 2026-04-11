#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> domino(7);
bool R[7] = {false}, C[7] = {false};
int maximum = -987654321, minimum = 987654321;

int get_score(int r, int c) {
    if(domino[r][c] >= 'A' && domino[r][c] <= 'I') return -((domino[r][c] - 'A') + 1);
    return domino[r][c] - '0';
}

void dfs(int pos, vector<pair<int,int>>& sel, int score) {
    if(sel.size() == N) {
        int group_count = 0;
        bool check[7] = {false};
        for(int i = 0; i < sel.size(); ++i) {
            if(check[i]) continue;
            ++group_count;
            bool cycle[7] = {false};
            cycle[sel[i].first] = true;
            cycle[sel[i].second] = true;
            bool flag = true;
            while(flag) {
                flag = false;
                for(int j = i + 1; j < sel.size(); ++j) {
                    if(!check[j] && (cycle[sel[j].first] || cycle[sel[j].second])) {
                        cycle[sel[j].first] = true;
                        cycle[sel[j].second] = true;
                        check[j] = true;
                        flag = true;
                    }
                }
            }
        }
        maximum = max(maximum, score * (group_count % 2 == 0 ? -1 : 1));
        minimum = min(minimum, score * (group_count % 2 == 0 ? -1 : 1));
        return;
    }

    for(int i = pos + 1; i < N * N; ++i) {
        int r = i / N;
        int c = i % N;

        if(R[r] || C[c]) continue;
        R[r] = true;
        C[c] = true;
        sel.push_back({r, c});
        dfs(i, sel, score * get_score(r, c));
        sel.pop_back();
        R[r] = false;
        C[c] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for(int r = 0; r < N; ++r) {
        cin >> domino[r];
    }
    vector<pair<int,int>> select;
    dfs(-1, select, 1);

    cout << minimum << "\n" << maximum;
}