#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
vector<int> adj[100001];
int tree_count[100001] = { 0 };
bool v[100001] = { false };
int dfs(int r) {
    v[r] = true;
    int cnt = 1;
    for (int i = 0; i < adj[r].size(); ++i) {
        if (v[adj[r][i]]) continue;
        cnt += dfs(adj[r][i]);
    }
    return tree_count[r] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R >> Q;

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(R);

    for (int q = 0; q < Q; ++q) {
        int query;
        cin >> query;
        cout << tree_count[query] << "\n";
    }
}