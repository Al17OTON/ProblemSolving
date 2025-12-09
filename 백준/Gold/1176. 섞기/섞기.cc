#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int N, K;
vector<int> students;
long long dp[16][1 << 16] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	
	memset(dp, 0, sizeof(dp));
	for (int n = 0; n < N; ++n) {
		int h;
		cin >> h;
		students.push_back(h);
		dp[n][1 << n] = 1;
	}

	int full = (1 << N) - 1;

	for (int bit = 1; bit <= full; ++bit) {
		for (int n = 0; n < N; ++n) {
			if (dp[n][bit] == 0) continue;
			for (int a = 0; a < N; ++a) {
				if (bit & (1 << a) || abs(students[n] - students[a]) <= K) continue;
				dp[a][bit | (1 << a)] += dp[n][bit];
			}
		}
	}

	long long res = 0;
	for (int i = 0; i < N; ++i) {
		res += dp[i][full];
	}
	cout << res;
}