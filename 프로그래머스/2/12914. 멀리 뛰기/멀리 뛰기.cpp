#include <string>
#include <vector>
#include <memory.h>
#define MOD 1234567

using namespace std;

int N;
long long dp[2001];
long long dfs(int idx) {
    if(idx >= N) return idx == N ? 1 : 0;
    if(dp[idx] != -1) return dp[idx];
    
    return dp[idx] = (dfs(idx + 1) + dfs(idx + 2)) % MOD;
}

long long solution(int n) {
    N = n;
    memset(dp, -1, sizeof(dp));
    return dfs(0);
}