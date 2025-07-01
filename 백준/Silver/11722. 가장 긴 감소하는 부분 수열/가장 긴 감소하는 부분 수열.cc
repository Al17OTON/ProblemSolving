#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 1001
using namespace std;

int N;
int arr[MAX], dp[MAX];

int main() {
	int longest = 0;
	scanf("%d", &N);

	for (int n = 0; n < N; ++n) {
		scanf("%d", &arr[n]);
		dp[n] = 1;
		for (int i = n - 1; i >= 0; --i) {
			if (arr[n] < arr[i]) {
				dp[n] = max(dp[n], dp[i] + 1);
			}
		}

		longest = max(longest, dp[n]);
	}
	printf("%d", longest);
}