#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int N, K;
vector<int> students;
long long dp[16][1 << 16];

long long dfs(int idx, int pre, int bit) {
	if (idx == N) return 1;
	if (dp[pre][bit] != -1) return dp[pre][bit];

	long long res = 0;
	for (int n = 0; n < N; ++n) {
		if (bit & (1 << n) || abs(students[n] - students[pre]) <= K) continue;
		res += dfs(idx + 1, n, bit | (1 << n));
	}
	return dp[pre][bit] = res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;

	for (int n = 0; n < N; ++n) {
		int h;
		cin >> h;
		students.push_back(h);
	}

	memset(dp, -1, sizeof(dp));

	long long res = 0;
	for (int n = 0; n < N; ++n) {
		res += dfs(1, n, (1 << n));
	}
	cout << res;
}