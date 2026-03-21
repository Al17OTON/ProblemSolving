#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<string> table;
vector<int> sel;
vector<long long> nums;

int get_r(int pos) {
    return pos / M;
}
int get_c(int pos) {
    return pos % M;
}

void dfs(int r, int c, int num) {
    int nr = get_r(sel.back()) + r;
    int nc = get_c(sel.back()) + c;

    if (nr < 0 || nr >= N || nc < 0 || nc >= M) return;
    sel.push_back(nr * M + nc);
    num = (num * 10) + table[nr][nc] - '0';
    nums.push_back(num);
    dfs(r, c, num);
    sel.pop_back();
}

int main() {
    cin >> N >> M;

    for (int n = 0; n < N; ++n) {
        string a;
        cin >> a;
        table.push_back(a);
    }

    for (int i = 0; i < N * M; ++i) {
        sel.push_back(i);
        int num = table[get_r(i)][get_c(i)] - '0';
        nums.push_back(num);
        for (int j = 0; j < N * M; ++j) {
            if (i == j) continue;
            sel.push_back(j);
            num = (num * 10) + table[get_r(j)][get_c(j)] - '0';
            nums.push_back(num);
            int r = get_r(j) - get_r(i);
            int c = get_c(j) - get_c(i);
            dfs(r, c, num);
            sel.pop_back();
            num /= 10;
        }
        sel.pop_back();
    }

    sort(nums.rbegin(), nums.rend());

    for (int i = 0; i < nums.size(); ++i) {
        for (long long j = 0; j * j <= nums[i]; ++j) {
            if (j * j == nums[i]) {
                cout << nums[i];
                return 0;
            }
            else if (j * j > nums[i]) break;

        }
    }

    cout << -1;
}