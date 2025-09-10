#include <iostream>

using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie();

	int C, N;
	// 고객의 수(C) 만큼 인덱스 사용
	int dp[1001];

	cin >> C >> N;

	// 무한값으로 할당
	for (int i = 0; i <= C; ++i) dp[i] = 987654321;

	int cost, customer;
	for (int n = 0; n < N; ++n) {
		cin >> cost >> customer;

		customer = customer > C ? C : customer;

		dp[customer] = min(dp[customer], cost);
	}

	// 각 인덱스(n)에 n명 이상의 고객을 구했을 때의 최소값을 구한다.
	for (int n = 1; n <= C; ++n) {
		for (int i = 1; i <= C; ++i) {
			// n명 고객을 만들었을 때
			if (i < n) {
				dp[n] = min(dp[n], dp[n - i] + dp[i]);
			}
			// n명 이상일 때
			else {
				dp[n] = min(dp[n], dp[i]);
			}
		}
	}

	printf("%d\n", dp[C]);
}