#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

long long dp[19][2][10][19];

string M, Z;
int r;
long long digitDP(int idx, int tight, int num, int count) {
	if (idx == M.size()) return count == r ? 1 : 0;
	else if (dp[idx][tight][num][r - count] != -1) return dp[idx][tight][num][r - count];
	else if (tight == 1) {
		long long res = 0;
		for (int i = 0; i <= M[idx] - '0'; ++i) {
			if (i == M[idx] - '0') res += digitDP(idx + 1, 1, i, (count == r ? count : ((Z[idx] - '0') == i ? count + 1 : 0)));
			else res += digitDP(idx + 1, 0, i, (count == r ? count : ((Z[idx] - '0') == i ? count + 1 : 0)));
		}
		return dp[idx][tight][num][r - count] = res;
	}
	else {
		long long res = 0;
		for (int i = 0; i <= 9; ++i) {
			res += digitDP(idx + 1, 0, i, (count == r ? count : ((Z[idx] - '0') == i ? count + 1 : 0)));
		}
		return dp[idx][tight][num][r - count] = res;
	}
}

void setZ() {
	string tmp = "";
	while (tmp.size() != M.size() - Z.size()) tmp += "0";
	Z = tmp + Z;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int C;
	cin >> C;
	for (int c = 0; c < C; ++c) {
		long long m;
		cin >> m >> Z >> r;
		M = to_string(m - 1);
		setZ();
		memset(dp, -1, sizeof(dp));
		cout << digitDP(0, 1, 0, 0) << "\n";
	}
}