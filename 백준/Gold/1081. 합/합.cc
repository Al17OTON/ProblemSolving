#include <iostream>
#include <string>
#include <memory.h>

using namespace std; 

long long dp[20][2][180];

long long digitDP(int idx, int tight, long long sum, const string& s) {
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

	string U, L;
	int num_L;
	cin >> num_L >> U;

	if (--num_L < 0) num_L = 0;
	L = to_string(num_L);

	memset(dp, -1, sizeof(dp));
	long long U_sum = digitDP(0, 1, 0, U);
	memset(dp, -1, sizeof(dp));
	long long L_sum = digitDP(0, 1, 0, L);

	cout << U_sum - L_sum;
}