#include <iostream>

using namespace std;

long long N, P, Q;
long long dp[3000000] = {0};

long long dfs(long long n) {
    if(n <= 0) return 1;
    if(n < 3000000) {
        if(dp[n]) return dp[n];

        return dp[n] = dfs(n / P) + dfs(n / Q);
    }

    return dfs(n / P) + dfs(n / Q);
}

int main() {
    cin >> N >> P >> Q;

    cout << dfs(N);
}