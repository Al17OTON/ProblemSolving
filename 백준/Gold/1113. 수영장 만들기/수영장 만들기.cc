#include <iostream>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int map[52][52] = { 0 };
bool v[52][52] = { false };
bool vv[52][52] = { false };
int dn[] = { -1, 1, 0, 0 };
int dm[] = { 0, 0, -1, 1 };

void floodfill() {
	v[0][0] = true;
	queue<pair<int, int>> q;
	q.push({ 0,0 });

	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop();

		for (int d = 0; d < 4; ++d) {
			int nn = p.first + dn[d];
			int nm = p.second + dm[d];

			if (nn > N + 1|| nn < 0 || nm > M + 1 || nm < 0 || v[nn][nm] || map[nn][nm] < map[p.first][p.second]) continue;
			v[nn][nm] = true;
			q.push({ nn, nm });
		}
	}


}

int same_low(int n, int m) {
	vector<pair<int, int>> vec;
	queue<pair<int, int>> q;
	vv[n][m] = true;
	q.push({ n, m });
	vec.push_back({ n, m });

	int low = 10;
	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop();

		for (int d = 0; d < 4; ++d) {
			int nn = p.first + dn[d];
			int nm = p.second + dm[d];

			if (map[n][m] < map[nn][nm] || v[nn][nm]) {
				low = min(low, map[nn][nm]);
				continue;
			}
			else if (vv[nn][nm]) continue;
			vv[nn][nm] = true;
			q.push({ nn, nm });
			vec.push_back({ nn, nm });
		}
	}

	int res = 0;
	for (int i = 0; i < vec.size(); ++i) {
		vv[vec[i].first][vec[i].second] = false;
		res += max(0, low - map[vec[i].first][vec[i].second]);
		map[vec[i].first][vec[i].second] = max(low, map[vec[i].first][vec[i].second]);
	}
	return res;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int n = 1; n <= N; ++n) {
		string line;
		cin >> line;
		for (int m = 1; m <= M; ++m) {
			map[n][m] = line[m - 1] - '0';
		}
	}

	floodfill();

	int res = 0;
	for (int n = 1; n <= N; ++n) {
		for (int m = 1; m <= M; ++m) {
			if (!v[n][m]) {
				res += same_low(n, m);
			}
		}
	}
	cout << res;
}