#include <iostream>
#include <memory.h>
#include <string>
#include <cmath>

using namespace std;

long long dp[10][2][90];

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

	int l, r;
	cin >> l >> r;

	memset(dp, -1, sizeof(dp));
	long long l_res = digitDP(0, 1, 0, to_string(max(0, l - 1)));
	memset(dp, -1, sizeof(dp));
	long long r_res = digitDP(0, 1, 0, to_string(r));

	cout << r_res - l_res;

}