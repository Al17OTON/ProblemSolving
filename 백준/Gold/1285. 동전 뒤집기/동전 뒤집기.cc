#include <iostream>
#include <algorithm>

using namespace std;

int N, full;
int map[20];

int get_col(int idx) {
	int count = 0;
	int bit = (1 << idx);
	for (int i = 0; i < N; ++i) {
		if (map[i] & bit) ++count;
	}
	return count;
}

int dfs(int idx) {
	if (idx == N) {
		int count = 0;
		for (int c = 0; c < N; ++c) {
			int c_count = get_col(c);
			if (c_count > N / 2) {
				count += (N - c_count);
			}
			else {
				count += c_count;
			}
		}
		return count;
	}

	int original = map[idx];
	map[idx] ^= full;
	int res = dfs(idx + 1);
	map[idx] = original;
	return min(res, dfs(idx + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	full = (1 << N) - 1;

	for (int i = 0; i < N; ++i) {
		string line;
		cin >> line;
		int coin = 0;
		for (int j = 0; j < N; ++j) {
			if (line[j] == 'T') coin |= (1 << j);
		}
		map[i] = coin;
	}

	cout << dfs(0);
}