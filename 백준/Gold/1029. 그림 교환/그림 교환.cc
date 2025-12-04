#include <iostream>
#include <memory.h>
#include <cmath>

using namespace std;

int N;
int cost[15][15];
int dp[15][32768][10];

int dfs(int idx, int price, int bit) {
	if (dp[idx][bit][price] != -1) return dp[idx][bit][price];

	int res = 0;
	for (int i = 1; i < N; ++i) {
		if ((bit & (1 << i)) || cost[idx][i] < price) continue;
		res = max(res, dfs(i, cost[idx][i], (bit | (1 << i))));
	}
	return dp[idx][bit][price] = res + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int n = 0; n < N; ++n) {
		string line;
		cin >> line;
		for (int i = 0; i < N; ++i) {
			cost[n][i] = line[i] - '0';
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 0, 1);
}