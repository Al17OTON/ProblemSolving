#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cost[20][20];
int dp[20][1 << 20];

int dfs(int idx, int bit) {
	if (idx == N) return 0;
	if (dp[idx][bit] != 0) return dp[idx][bit];

	int res = 987654321;
	for (int i = 0; i < N; ++i) {
		if (bit & (1 << i)) continue;
		res = min(res, cost[idx][i] + dfs(idx + 1, bit | (1 << i)));
	}
	return dp[idx][bit] = res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int n = 0; n < N; ++n) {
		for (int a = 0; a < N; ++a) {
			cin >> cost[n][a];
		}
	}

	cout << dfs(0, 0);

}