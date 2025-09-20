#include <iostream>
#include <cmath>

using namespace std;

void dfs(int r, int c, int len, bool black);

bool map[50][50] = { false };
int s, N, K, R1, R2, C1, C2, padding;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

	int len = pow(N, s);
	padding = (N - K) / 2;

	dfs(0, 0, len, false);

	for (int i = 0; i <= R2 - R1; ++i) {
		for (int j = 0; j <= C2 - C1; ++j) {
			cout << (map[i][j] ? "1" : "0");
		}
		cout << "\n";
	}
}

void dfs(int r, int c, int len, bool black) {
	if (r > R2 || r + len <= R1 || c > C2 || c + len <= C1) return;

	if (len == 1) {
		map[r - R1][c - C1] = black;
		return;
	}

	if (black) {
		for (int i = max(r, R1); i < min(r + len, R2 + 1); ++i) {
			for (int j = max(c, C1); j < min(c + len, C2 + 1); ++j) {
				map[i - R1][j - C1] = true;
			}
		}
		return;
	}

	int n_len = len / N;

	for (int i = r, i_idx = 0; i_idx < N; i += n_len, ++i_idx) {
		for (int j = c, j_idx = 0; j_idx < N; j += n_len, ++j_idx) {

			dfs(i, j, n_len, (i_idx >= padding && j_idx >= padding && i_idx < padding + K && j_idx < padding + K));

		}
	}

}