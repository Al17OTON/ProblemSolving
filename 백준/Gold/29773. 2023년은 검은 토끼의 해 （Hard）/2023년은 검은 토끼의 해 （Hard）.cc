#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

long long dp[20][2][5];
int winning[] = { 2,0,2,3,-1};

long long digitDP(int idx, int tight, int win_idx, const string& s) {
	if (idx == s.size()) {
		return win_idx == 4 ? 1 : 0;
	}
	else if (dp[idx][tight][win_idx] != -1) {
		return dp[idx][tight][win_idx];
	}
	else if (tight == 1) {
		long long res = 0;
		for (int i = 0; i <= s[idx] - '0'; ++i) {
			if (i == s[idx] - '0') res += digitDP(idx + 1, 1, (winning[win_idx] == i ? win_idx + 1 : win_idx), s);
			else res += digitDP(idx + 1, 0, (winning[win_idx] == i ? win_idx + 1 : win_idx), s);
		}
		return dp[idx][tight][win_idx] = res;
	}
	else {
		long long res = 0;
		for (int i = 0; i <= 9; ++i) {
			res += digitDP(idx + 1, 0, (winning[win_idx] == i ? win_idx + 1 : win_idx), s);
		}
		return dp[idx][tight][win_idx] = res;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(dp, -1, sizeof(dp));

	string N;
	cin >> N;

	cout << digitDP(0, 1, 0, N);
}