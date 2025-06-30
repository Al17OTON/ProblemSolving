#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 1001
using namespace std;

int N;
int arr[MAX];
int dp[MAX];

int max(int a, int b) { return a > b ? a : b; }

int main() {
	int maximum = 0;
	scanf("%d", &N);

	for (int n = 0; n < N; ++n) {
		scanf("%d", &arr[n]);

		dp[n] = arr[n];

		for (int i = n - 1; i >= 0; --i) {
			if (arr[i] < arr[n]) {
				dp[n] = max(dp[n], arr[n] + dp[i]);
			}
		}

		maximum = max(maximum, dp[n]);
	}

	printf("%d", maximum);
}