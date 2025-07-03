#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 10001
#define INF 987654321
using namespace std;

int N, K;
int dp[MAX];

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= K; ++i) dp[i] = INF;

	int coin;
	for (int n = 0; n < N; ++n) {
		scanf("%d", &coin);

		for (int i = coin; i <= K; ++i) {
			dp[i] = min(dp[i - coin] + 1, dp[i]);
		}
	}

	printf("%d", dp[K] == INF ? -1 : dp[K]);
}