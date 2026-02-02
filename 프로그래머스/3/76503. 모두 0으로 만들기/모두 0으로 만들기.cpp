#include <string>
#include <vector>
// #include <algorithm>

using namespace std;

long long answer = 0;
vector<int> adj[300001];
vector<int>* cost;

long long dfs(int idx, int pre) {
    long long res = (*cost)[idx];
    for(int i = 0; i < adj[idx].size(); ++i) {
        if(adj[idx][i] == pre) continue;
        long long c = dfs(adj[idx][i], idx);
        res += c;
        
        answer += c > 0 ? c : -c;
    }
    return res;
}

long long solution(vector<int> a, vector<vector<int>> edges) { 
    cost = &a;
    for(int i = 0; i < edges.size(); ++i) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    return dfs(0, -1) == 0 ? answer : -1;
}