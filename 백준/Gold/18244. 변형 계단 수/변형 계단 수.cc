#include <iostream>
#include <memory.h>
#include <cmath>
#define MOD 1000000007

using namespace std;

int dp[10][100][5];
int N;

int digitDP(int idx, int pre, int stack) {
	if (pre > 9 || pre < 0) return 0;
	else if (idx == N) return 1;
	else if (dp[pre][idx][stack] != -1) return dp[pre][idx][stack];
	else {
		int res = 0;
		
		if (stack != 4) {
			int next = (stack == 0 || stack == 3) ? 4 : 3;
			res = (res + digitDP(idx + 1, pre - 1, next)) % MOD;
		}
		if (stack != 2) {
			int next = (stack == 0 || stack == 1) ? 2 : 1;
			res = (res + digitDP(idx + 1, pre + 1, next)) % MOD;
		}

		return dp[pre][idx][stack] = res;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	if (N == 1) {
		cout << 10;
		return 0;
	}

	memset(dp, -1, sizeof(dp));
	int answer = 0;

	for (int i = 0; i <= 9; ++i) {
		answer = (answer + digitDP(0, i, 0)) % MOD;
	}
	cout << answer;
}