#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int map[52][52] = { 0 };
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void floodfill(int target) {
	queue<pair<int, int>> q;

	map[0][0] = target;
	q.push({ 0, 0 });

	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop();

		for (int d = 0; d < 4; ++d) {
			int nr = p.first + dr[d];
			int nc = p.second + dc[d];

			if (nr > N + 1 || nr < 0 || nc > M + 1 || nc < 0 || map[nr][nc] >= target) continue;
			map[nr][nc] = target;
			q.push({ nr,nc });
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	int high = 0;
	for (int n = 1; n <= N; ++n) {
		string line;
		cin >> line;
		for (int m = 1; m <= M; ++m) {
			map[n][m] = line[m - 1] - '0';
			high = max(high, map[n][m]);
		}
	}

	int res = 0;
	for (int i = 1; i <= high; ++i) {
		floodfill(i);

		for (int r = 1; r <= N; ++r) {
			for (int c = 1; c <= M; ++c) {
				if (map[r][c] < i) {
					++res;
					++map[r][c];
				}
			}
		}
	}

	cout << res;
}

