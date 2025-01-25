#include <iostream>
#include <queue>
#define MAX 501
#define SUCCESS 1000
using namespace std;

struct Pos {
	int gravity;
	int r, c;
	Pos(int gravity, int r, int c) : gravity(gravity), r(r), c(c) {}

	bool operator < (const Pos p) const {
		return this->gravity > p.gravity;
	}
};

int N, M;
char map[MAX][MAX];
bool v[MAX][MAX][2] = {false};

pair<int, int> cap, doc;
priority_queue<Pos> pq;
int dc[] = { -1, 1 };

int bfs();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> map[n][m];
			if (map[n][m] == 'C') {
				cap = { n, m };
				map[n][m] = '.';
			}
			else if (map[n][m] == 'D') {
				doc = { n, m };
				map[n][m] = '.';
			}
		}
	}

	cout << bfs();
	
}

bool is_doc(int r, int c) {
	return r == doc.first && c == doc.second;
}

// 현재 위치를 입력받고 중력을 적용해준다.
// 맵 밖으로 벗어나면 -1
// 그렇지 않다면 '#' 바로 위 좌표(r) 반환
// 중력으로 떨어지면서 중간에 박사를 만난다면 SUCCESS (1000) 반환
int gravity_effect(const Pos& p) {
	int dir = p.gravity % 2 == 0 ? 1 : -1;
	int nr = p.r;

	while (nr >= 0 && nr < N && map[nr][p.c] == '.') {
		if (is_doc(nr, p.c)) return SUCCESS;	// 중간에 박사를 만난 경우 바로 반환
		nr += dir;
	}

	if (nr < 0 || nr >= N) return -1;
	
	return nr - dir;
}

int bfs() {
	Pos start_pos = Pos(0, cap.first, cap.second);
	int start_r = gravity_effect(start_pos);	// 시작 점에서 중력을 적용해주기

	if (start_r == SUCCESS) return 0;
	if (start_r == -1) return -1;
	start_pos.r = start_r;

	pq.push(start_pos);
	v[start_r][cap.second][0] = true;

	while (!pq.empty()) {
		Pos p = pq.top(); pq.pop();

		if (is_doc(p.r, p.c)) {
			return p.gravity;
		}

		// 좌 우 이동
		for (int d = 0; d < 2; d++) {
			int nc = p.c + dc[d];

			if (nc >= M || nc < 0 || v[p.r][nc][p.gravity % 2] || map[p.r][nc] != '.') continue;
			v[p.r][nc][p.gravity % 2] = true;	// 중력 적용 전에 방문 처리를 해줘야 시간초과 X (중력 적용 후 방문 처리만 하면 이미 방문한 곳임에도 중력 적용 오버헤드 발생)
			Pos tmp = Pos(p.gravity, p.r, nc);
			int nr = gravity_effect(tmp);
			if (nr == SUCCESS) return p.gravity;
			if (nr == -1) continue;

			v[nr][nc][p.gravity % 2] = true;
			tmp.r = nr;
			pq.push(tmp);
		}
		
		// 제자리에서 중력 적용
		Pos tmp = Pos(p.gravity + 1, p.r, p.c);
		int nr = gravity_effect(tmp);
		if (nr == SUCCESS) return tmp.gravity;
		if (nr != -1 && !v[nr][tmp.c][tmp.gravity % 2]) {
			v[nr][p.c][tmp.gravity % 2] = true;
			tmp.r = nr;
			pq.push(tmp);
		}
	}

	return -1;
}