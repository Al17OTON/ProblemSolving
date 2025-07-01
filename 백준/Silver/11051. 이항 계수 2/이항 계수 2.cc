#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 1001
#define MOD 10007
using namespace std;

int pascal(int r, int c);
int N, K;
int dp[MAX][MAX];
int main() {
	scanf("%d %d", &N, &K);

	printf("%d", pascal(N, K));
}

int pascal(int r, int c) {
	if (c == 0 || r == c) return 1;
	if (dp[r][c] != 0) return dp[r][c];

	return dp[r][c] = (pascal(r - 1, c) + pascal(r - 1, c - 1)) % MOD;
}