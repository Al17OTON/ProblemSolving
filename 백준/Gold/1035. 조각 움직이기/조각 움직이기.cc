#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Shard {
	int r, c;

	bool equal(const Shard& o) {
		return this->r == o.r && this->c == o.c;
	}
	int get_pos() {
		return this->r * 5 + this->c;
	}
};

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
char map[5][5];
vector<Shard> shards;
vector<Shard> temp(5, {-1, -1});
int vv;

int get_move() {
	int total = 0;
	for (int i = 0; i < shards.size(); ++i) {
		queue<Shard> q;
		q.push(shards[i]);
		vv = 0;
		vv |= 1 << shards[i].get_pos();
		int turn = 0;
		while (!q.empty()) {
			int size = q.size();
			bool flag = false;
			for (; size > 0; --size) {
				Shard s = q.front(); q.pop();

				if (s.equal(temp[i])) {
					flag = true;
					break;
				}

				for (int d = 0; d < 4; ++d) {
					int nr = s.r + dr[d];
					int nc = s.c + dc[d];

					if(nr >= 5 || nr < 0 || nc >= 5 || nc < 0 || (vv & (1 << (nr * 5 + nc)))) continue;
					vv |= (1 << (nr * 5 + nc));
					q.push({ nr, nc });
				}
			}
			if (flag) break;
			++turn;
		}
		total += turn;
	}

	return total;
}

int check(int r, int c) {
	if (r >= 5 || r < 0 || c >= 5 || c < 0 || map[r][c] == '.' || (vv & (1 << (r * 5 + c)))) return 0;
	vv |= (1 << (r * 5 + c));
	int result = 1;
	for (int d = 0; d < 4; ++d) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		
		result += check(nr, nc);
	}
	return result;
}

int permutation(int idx) {
	if (idx == shards.size()) {
		vv = 0;
		if (check(temp[0].r, temp[0].c) != shards.size()) return 987654321;

		return get_move();
	}

	int result = 987654321;
	for (int r = 0; r < 5; ++r) {
		for(int c = 0; c < 5; ++c) {
			if (map[r][c] != '.') continue;
			map[r][c] = '*';
			temp[idx].r = r;
			temp[idx].c = c;
			result = min(result, permutation(idx + 1));
			map[r][c] = '.';
		}
	}
	return result;
}

// 5 * 5이므로 조각이 위치할 수 있는 경우의 수 다 구하기
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 5; ++i) {
		cin >> map[i];

		for (int j = 0; j < 5; ++j) {
			if (map[i][j] == '*') {
				shards.push_back({ i, j });
				map[i][j] = '.';
			}
		}
	}

	cout << permutation(0);
}