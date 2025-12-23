#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int dp[100001];

int solution(int n, vector<int> money) {
    dp[0] = 1;
    
    for(int i = 0; i < money.size(); ++i) {
        for(int j = money[i]; j <= n; ++j) {
            dp[j] = (dp[j] + dp[j - money[i]]) % MOD;
        }
    }
    return dp[n];
}