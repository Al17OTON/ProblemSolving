using namespace std;

long long MOD = 1000000007;
long long dp[5001];

int solution(int n) {
    if(n % 2 != 0) return 0;
    
    dp[2] = 3;
    dp[4] = 11;
    
    for(int i = 6; i <= n; i += 2) {
        dp[i] = (dp[i - 2] * 4 - dp[i - 4] + MOD) % MOD;
        
    }
    return dp[n];
}