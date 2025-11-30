#include <iostream>
#include <memory.h>
#include <vector>
#define MOD 1000000007

using namespace std;

int dp[100][1000];
int N, M, K;
vector<int> selected;

int digitDP(int idx, int rest) {
	if (idx == M) return rest == 0 ? 1 : 0;
	else if (dp[idx][rest] != -1) return dp[idx][rest];
	else {
		int res = 0;
		for (int i = 0; i < selected.size(); ++i) {
			res = (res + digitDP(idx + 1, (rest * 10 + selected[i]) % K)) % MOD;
		}
		return dp[idx][rest] = res;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;

	for (int n = 0; n < N; ++n) {
		int num;
		cin >> num;
		selected.push_back(num);
	}

	memset(dp, -1, sizeof(dp));
	int res = 0;
	for (int i = 0; i < selected.size(); ++i) {
		if (selected[i] == 0) continue;
		res = (res + digitDP(1, selected[i] % K)) % MOD;
	}
	cout << res;
}