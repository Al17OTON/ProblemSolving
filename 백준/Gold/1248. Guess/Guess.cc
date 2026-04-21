#include <iostream>
#include <vector>

using namespace std;

int N;
char mat[11][11];
vector<int> sel, sum(10, 0);

bool dfs(int idx) {
    if(idx > 0) {
        for(int j = 0; j < idx; ++j) {
            if(mat[j][idx - 1] == '+' && sum[j] <= 0) return false;
            else if(mat[j][idx - 1] == '-' && sum[j] >= 0) return false;
            else if(mat[j][idx - 1] == '0' && sum[j] != 0) return false;
        }
    }
    
    if(idx == N) {
        for(int i = 0; i < sel.size(); ++i) {
            cout << sel[i] << " ";
        }
        return true;
    }

    if(mat[idx][idx] == '0') {
        sel.push_back(0);
        if(dfs(idx + 1)) return true;
        sel.pop_back();
        return false;
    }
    int sign = (mat[idx][idx] == '+' ? 1 : -1);
    for(int i = 1; i < 11; ++i) {
        sel.push_back(i * sign);
        for(int j = 0; j <= idx; ++j) {
            sum[j] += sel.back();
        }
        if(dfs(idx + 1)) return true;
        for(int j = 0; j <= idx; ++j) {
            sum[j] -= sel.back();
        }
        sel.pop_back();
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int i = 0; i < N; ++i) {
        for(int j = i; j < N; ++j) {
            cin >> mat[i][j];
        }
    }

    dfs(0);

}