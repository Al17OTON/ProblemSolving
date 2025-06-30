#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 50001
using namespace std;

int N;
int dp[MAX];

int min(int a, int b) { return a > b ? b : a; }

int main() {
	scanf("%d", &N);
	dp[1] = 1;
	for (int i = 2; i <= N; ++i) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j * j <= i; ++j) {
			dp[i] = min(dp[i], dp[i - (j * j)] + 1);
		}
	}

	printf("%d", dp[N]);
}