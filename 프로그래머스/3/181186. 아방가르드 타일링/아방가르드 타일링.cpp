#include <string>
#include <vector>

using namespace std;

long long mod = 1000000007;
long long dp[100001] = {0};
long long except_dp[3] = {12, 2, 4};

int solution(int n) {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 10;
    
    for(int i = 4; i <= n; ++i) {
        int except = i % 3;
        dp[i] = (except_dp[except] + (dp[i - 1] + dp[i - 2] * 2 + dp[i - 3] * 5)) % mod;
        except_dp[except] += (dp[i - 1] * 2 + dp[i - 2] * 2 + dp[i - 3] * 4) % mod;
    }
    return (int)dp[n];
}