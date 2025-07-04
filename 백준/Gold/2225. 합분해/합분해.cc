#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 201
#define MOD 1000000000
using namespace std;

int N, K;
int dp[MAX][MAX];

int main() {
	scanf("%d %d", &N, &K);

	for (int n = 0; n <= N; ++n) dp[1][n] = 1;


	for (int k = 2; k <= K; ++k) {
		int sum = 0;
		for (int n = 0; n <= N; ++n) {
			sum = (sum + dp[k - 1][n]) % MOD;
			dp[k][n] = sum;
		}
	}

	printf("%d", dp[K][N]);
}