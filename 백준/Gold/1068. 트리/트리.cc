#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, root, del;
vector<int> child[51];

int dfs(int idx) {
    if(idx == del) return 0; 

    int res = 0;
    for(int i = 0; i < child[idx].size(); ++i) {
        res += dfs(child[idx][i]);
    }
    return max(1, res);
}

int main() {
    cin >> N;
    for(int n = 0; n < N; ++n) {
        int parent;
        cin >> parent;
        child[parent].push_back(n);
        if(parent == -1) root = n;
    }
    cin >> del;

    cout << dfs(root);
}