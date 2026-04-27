#include <algorithm>
#include <vector>

using namespace std;

int dp[101][101] = {0};
constexpr int MOD = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) { 
    for(int i = 0; i < puddles.size(); ++i) {
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    dp[0][1] = 1;
    for(int r = 1; r <= n; ++r) {
        for(int c = 1; c <= m; ++c) {
            if(dp[r][c] == -1) continue;
            dp[r][c] = (max(dp[r - 1][c], 0) + max(dp[r][c - 1], 0)) % MOD;
        }
    }
    
    return dp[n][m];
}