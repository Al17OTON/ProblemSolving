#include <vector>

using namespace std;

int min(int a, int b) {
    return a > b ? b : a;
}

vector<int> h(16);
int min_cost = 987654321;

int dfs(int stage, int sum, const vector<vector<int>>& cost, const vector<vector<int>>& hint) {
    if(min_cost <= sum) return 987654321;
    if(stage == cost.size() - 1) {
        return sum + cost[stage][min(cost.size() - 1, h[stage])];
    }
    
    int res = dfs(stage + 1, sum + cost[stage][min(cost.size() - 1, h[stage])], cost, hint);
    
    for(int i = 1; i < hint[stage].size(); ++i) {
        ++h[hint[stage][i] - 1];
    }
    res = min(res, dfs(stage + 1, sum + cost[stage][min(cost.size() - 1, h[stage])] + hint[stage][0], cost, hint));
    for(int i = 1; i < hint[stage].size(); ++i) {
        --h[hint[stage][i] - 1];
    }
    return res;
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    return dfs(0, 0, cost, hint);
}