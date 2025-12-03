#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

long long dp[30][8];
int N;
long long K;

long long digitDP(int idx, int bit) {
	if (idx == N) {
		return bit == 0 ? 1 : 0;
	}
	else if (dp[idx][bit] != -1) {
		return dp[idx][bit];
	}
	else {
		long long res = 0;
		res += digitDP(idx + 1, bit ^ 1);
		res += digitDP(idx + 1, bit ^ 2);
		res += digitDP(idx + 1, bit ^ 4);
		return dp[idx][bit] = res;
	}
}

int bit = 0;
string find(int idx) {
	if (idx == N) {
		return "";
	}

	long long seven = 0, five = 0, three = 0;
	for (int i = 0; i < 8; ++i) {
		if (i == bit) continue;
		seven += digitDP(idx + 1, i ^ 1);
	}
	for (int i = 0; i < 8; ++i) {
		if (i == bit) continue;
		five += digitDP(idx + 1, i ^ 2);
	}
	for (int i = 0; i < 8; ++i) {
		if (i == bit) continue;
		three += digitDP(idx + 1, i ^ 4);
	}

	if (K <= seven) {
		bit ^= 1;
		return "7" + find(idx + 1);
	}
	K -= seven;
	if (K <= five) {
		bit ^= 2;
		return "5" + find(idx + 1);
	}
	K -= five;
	if (K <= three) {
		bit ^= 4;
		return "3" + find(idx + 1);
	}
	K -= three;
	return find(idx + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	memset(dp, -1, sizeof(dp));
	digitDP(0, 0);

	cout << find(0);
}