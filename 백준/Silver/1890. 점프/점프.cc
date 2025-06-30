#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 101

using namespace std;

int N;
long long dp[MAX][MAX];

int main() {
	scanf("%d", &N);
	dp[0][0] = 1;

	int jump;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			scanf("%d", &jump);

			if (dp[r][c] == 0 || jump == 0) continue;

			int nr = r + jump;
			int nc = c + jump;

			if (nr < N) {
				dp[nr][c] += dp[r][c];
			}
			if (nc < N) {
				dp[r][nc] += dp[r][c];
			}
		}
	}

	printf("%lld", dp[N - 1][N - 1]);
}