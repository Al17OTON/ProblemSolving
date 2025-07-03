#include <stdio.h>

int N;
int A[501];
int dp[101];

int MAX(int a, int b) { return (a > b) ? a : b; }

int main() {
	scanf("%d", &N);

	int a, b;
	for (int n = 0; n < N; n++) {
		scanf("%d %d", &a, &b);
		A[a] = b;
	}

	int count = 0, pre = 0;
	for (int i = 1; i <= 500; i++) {
		if (A[i] != 0) {
			count++;
			pre = 0;
			for (int j = 0; j < i; j++) {
				if (A[j] != 0) {
					pre++;
					if (A[i] > A[j]) 
						dp[count] = MAX(dp[count], dp[pre] + 1);
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i <= N; i++) 
		result = MAX(result, dp[i]);

	printf("%d", N - result - 1);
}