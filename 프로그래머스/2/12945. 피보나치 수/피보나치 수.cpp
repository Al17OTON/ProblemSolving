#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int MOD = 1234567;
int dp[100001];

int fib(int num) {
    if(num <= 1) return num;
    else if(dp[num] != -1) return dp[num];
    
    return dp[num] = (fib(num - 1) + fib(num - 2)) % MOD;
}

int solution(int n) {  
    memset(dp, -1, sizeof(dp));
    
    return fib(n);
}