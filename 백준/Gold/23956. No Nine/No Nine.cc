#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

long long dp[19][2][9];

long long digitDP(int idx, int tight, int num, int mod, const string& s) {
	if (idx == s.size()) return mod != 0 ? 1 : 0;
	else if (dp[idx][tight][num] != -1) return dp[idx][tight][num];
	else if(tight == 1) {
		long long res = 0;
		for (int i = 0; i <= s[idx] - '0'; ++i) {
			if (i == 9) continue;
			else if (i == s[idx] - '0') res += digitDP(idx + 1, 1, i, (mod * 10 + i) % 9, s);
			else res += digitDP(idx + 1, 0, i, (mod * 10 + i) % 9, s);
		}
		return dp[idx][tight][num] = res;
	}
	else {
		long long res = 0;
		for (int i = 0; i <= 8; ++i) {
			res += digitDP(idx + 1, 0, i, (mod * 10 + i) % 9, s);
		}
		return dp[idx][tight][num] = res;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		string F, L;
		long long f_num;
		cin >> f_num >> L;
		F = to_string(f_num - 1);
		memset(dp, -1, sizeof(dp));
		long long f_res = digitDP(0, 1, 0, 0, F);
		memset(dp, -1, sizeof(dp));
		long long l_res = digitDP(0, 1, 0, 0, L);
		cout << "Case #" << t + 1 << ": " << l_res - f_res << "\n";
	}
}