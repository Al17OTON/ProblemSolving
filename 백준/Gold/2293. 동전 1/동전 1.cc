#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define MAX 101
#define MAX_K 10001

using namespace std;

int N, K;
int coin[MAX], dp[MAX_K];

int main() {
	scanf("%d %d", &N, &K);
	
	dp[0] = 1;

	for (int n = 0; n < N; ++n) {
		scanf("%d", &coin[n]);
	}
	sort(coin, coin + N);

	for (int n = 0; n < N; ++n) {
		if (coin[n] > K) continue;
		for (int i = coin[n]; i <= K; ++i) {
			dp[i] += dp[i - coin[n]];
		}
	}

	printf("%d", dp[K]);
}