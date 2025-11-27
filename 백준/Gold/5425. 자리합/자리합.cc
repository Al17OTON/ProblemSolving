#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

long long dp[16][2][144];

long long digitDP(int idx, int tight, int sum, const string& s) {
	if (idx == s.size()) return sum;
	else if (dp[idx][tight][sum] != -1) return dp[idx][tight][sum];
	else if (tight == 1) {
		long long res = 0;
		for (int i = 0; i <= s[idx] - '0'; ++i) {
			if (i == s[idx] - '0') res += digitDP(idx + 1, 1, sum + i, s);
			else res += digitDP(idx + 1, 0, sum + i, s);
		}
		return dp[idx][tight][sum] = res;
	}
	else {
		long long res = 0;
		for (int i = 0; i <= 9; ++i) {
			res += digitDP(idx + 1, 0, sum + i, s);
		}
		return dp[idx][tight][sum] = res;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		string b;
		long long a;
		cin >> a >> b;
		if (a != 0) --a;

		long long a_sum = digitDP(0, 1, 0, to_string(a));
		memset(dp, -1, sizeof(dp));
		long long b_sum = digitDP(0, 1, 0, b);
		memset(dp, -1, sizeof(dp));

		cout << b_sum - a_sum << "\n";
	}
}