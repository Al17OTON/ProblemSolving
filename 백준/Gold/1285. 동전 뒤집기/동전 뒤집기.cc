#include <iostream>
#include <algorithm>

using namespace std;

int N, full;
int map[20];

int get_col(int idx, const int m[]) {
	int count = 0;
	int bit = (1 << idx);
	for (int i = 0; i < N; ++i) {
		if (m[i] & bit) ++count;
	}
	return count;
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

	int answer = 99999;
	int tmp[20];
	for (int i = 0; i <= full; ++i) {
		for (int r = 0; r < N; ++r) {
			if (i & (1 << r)) tmp[r] = map[r] ^ full;
			else tmp[r] = map[r];
		}

		int count = 0;
		for (int c = 0; c < N; ++c) {
			int c_count = get_col(c, tmp);
			if (c_count > N / 2) {
				count += (N - c_count);
			}
			else {
				count += c_count;
			}
		}

		answer = min(answer, count);
	}

	cout << answer;
}