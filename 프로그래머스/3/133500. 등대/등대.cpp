#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

void dfs(int idx, const vector<vector<int>>& adj, vector<vector<int>>& dp, vector<bool>& v) {
    if(v[idx]) return;
    v[idx] = true;
    dp[idx][1] = 1;
    
    for(int i = 0; i < adj[idx].size(); ++i) {
        if(!v[adj[idx][i]]) {
            dfs(adj[idx][i], adj, dp, v);
            
            dp[idx][0] += dp[adj[idx][i]][1];
            dp[idx][1] += min(dp[adj[idx][i]][0], dp[adj[idx][i]][1]);
        }
    }
}

// 경로는 n - 1개 이므로 순환은 존재하지 않는다.
int solution(int n, vector<vector<int>> lighthouse) {
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> dp(n + 1, {0, 0});
    vector<bool> v(n + 1, false);
    
    for(int i = 0; i < lighthouse.size(); ++i) {
        adj[lighthouse[i][0]].push_back(lighthouse[i][1]);
        adj[lighthouse[i][1]].push_back(lighthouse[i][0]);
    }
    
    dfs(1, adj, dp, v);
    
    return min(dp[1][0], dp[1][1]);
}