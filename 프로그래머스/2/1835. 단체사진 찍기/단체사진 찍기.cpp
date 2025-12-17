#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Friend {
    vector<pair<int, int>> eq, le, gt;
};

int arr[] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

bool check(vector<int>& sel, int f, int idx, Friend friends[]) {
    vector<pair<int, int>>& eq = friends[f].eq;
    vector<pair<int, int>>& le = friends[f].le;
    vector<pair<int, int>>& gt = friends[f].gt;

    for (int i = 0; i < eq.size(); ++i) {
        bool flag = false;
        if (eq[i].second + idx + 1 < 8 && sel[eq[i].second + idx + 1] == eq[i].first) flag = true;
        if (idx - (eq[i].second + 1) >= 0 && sel[idx - (eq[i].second + 1)] == eq[i].first) flag = true;

        if (!flag) return false;
    }

    for (int i = 0; i < le.size(); ++i) {
        bool flag = false;
        for (int j = max(idx - le[i].second, 0); j <= min(idx + le[i].second, 7); ++j) {
            if (sel[j] == le[i].first) {
                flag = true;
                break;
            }
        }
        if (!flag) return false;
    }

    for (int i = 0; i < gt.size(); ++i) {
        bool flag = true;
        for (int j = max(idx - (gt[i].second + 1), 0); j <= min(idx + gt[i].second + 1, 7); ++j) {
            if (sel[j] == gt[i].first) {
                flag = false;
                break;
            }
        }
        if (!flag) return false;
    }
    return true;
}

int dfs(int idx, vector<int>& sel, int v, Friend friends[]) {
    if (idx == 8) {
        for (int i = 0; i < 8; ++i) {
            if (!check(sel, sel[i], i, friends)) return 0;
        }
        return 1;
    }
    int res = 0;
    for (int i = 0; i < 8; ++i) {
        if (v & (1 << i)) continue;
        sel.push_back(arr[i] - 'A');
        res += dfs(idx + 1, sel, v | (1 << i), friends);
        sel.pop_back();
    }
    return res;
}

int solution(int n, vector<string> data) {
    Friend friends[26];
    
    for (int i = 0; i < data.size(); ++i) {
        int from = data[i][0] - 'A';
        int to = data[i][2] - 'A';
        int gap = data[i][4] - '0';
        if (data[i][3] == '=') {
            friends[from].eq.push_back({ to, gap });
        }
        else if (data[i][3] == '<') {
            friends[from].le.push_back({ to, gap });
        }
        else {
            friends[from].gt.push_back({ to, gap });
        }
    }

    vector<int> sel;
    return dfs(0, sel, 0, friends);

}