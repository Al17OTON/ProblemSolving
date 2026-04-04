#include <iostream>
#define MAX 30000001
using namespace std;

long long N, P, Q, X, Y;
int dp[MAX] = {0};

long long dfs(long long i) {
    if(i <= 0) return 1;
    if(i >= MAX) return dfs(i / P - X) + dfs(i / Q - Y);
    if(dp[i]) return dp[i];

    return dp[i] = dfs(i / P - X) + dfs(i / Q - Y);
}

int main() {
    cin >> N >> P >> Q >> X >> Y;

    cout << dfs(N);
}