#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 32
using namespace std;

int N, K;
int dp[MAX][MAX] = {0};

int dfs(int n, int k);

int main() {
	scanf("%d %d", &N, &K);

	printf("%d", dfs(N, K));
}

int dfs(int n, int k) {
	if (k == 0 || k == n + 1) return 0;
	if (k == n || k == 1) return 1;

	if (dp[n][k] != 0) return dp[n][k];

	return dp[n][k] = dfs(n - 1, k - 1) + dfs(n - 1, k);
}