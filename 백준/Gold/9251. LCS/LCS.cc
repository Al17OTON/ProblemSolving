#include <stdio.h>

char A[1002], B[1002];
int dp[1002][1002];

int MAX(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	scanf("%s %s", A, B);
	int i, j;
	for (i = 1; A[i - 1]; i++) {
		for (j = 1; B[j - 1]; j++) {
			if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	printf("%d", dp[i - 1][j - 1]);
}