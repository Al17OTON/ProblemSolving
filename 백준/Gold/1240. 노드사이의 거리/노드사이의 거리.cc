#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int to, cost;
};

int N, M;
vector<Node> adj[1001];

int dfs(int idx, int pre, int target, int cost) {
    if(idx == target) return cost;

    for(int i = 0; i < adj[idx].size(); ++i) {
        if(pre == adj[idx][i].to) continue;
        int res = dfs(adj[idx][i].to, idx, target, cost + adj[idx][i].cost);
        if(res != -1) return res;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;

    for(int n = 0; n < N - 1; ++n) {
        int from, to, cost;
        cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
        adj[to].push_back({from, cost});
    }

    for(int m = 0; m < M; ++m) {
        int from, to;
        cin >> from >> to;
        cout << dfs(from, from, to, 0) << "\n";
    }
}