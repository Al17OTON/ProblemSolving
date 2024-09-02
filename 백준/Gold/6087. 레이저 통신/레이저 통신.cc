#define _CRT_SECURE_NO_WARNINGS
#define MAX 101
#include <iostream>
#include <queue>

using namespace std;

int W, H;
char map[MAX][MAX] = {};
pair<int, int>* start = NULL, *goal = NULL;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int bfs();

int main() {
	scanf("%d %d", &W, &H);

	for (int h = 0; h < H; h++) {
		scanf("%s", map[h]);
	}

	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			if (map[h][w] == 'C') {
				if (start == NULL) start = new pair<int, int>(h, w);
				else goal = new pair<int, int>(h, w);
			}
		}
	}


	printf("%d", bfs());
	delete start, goal;
}

int bfs() {
	queue<pair<int, int>> q;
	bool v[MAX][MAX] = {};
	bool flag = false;
	pair<int, int> mirror;
	int size, mirror_count = -1, nr, nc;

	q.push(*start);
	v[start->first][start->second] = true;

	while (!q.empty() && !flag) {

		mirror_count++;
		size = q.size();
		
		for (int i = 0; i < size; i++) {

			mirror = q.front();
			q.pop();

			if (mirror.first == goal->first && mirror.second == goal->second) {
				flag = true;
				break;
			}

			for (int d = 0; d < 4; d++) {
				nr = mirror.first + dr[d];
				nc = mirror.second + dc[d];
				while (nr >= 0 && nr < H && nc >= 0 && nc < W) {
					if(map[nr][nc] == '*') break;
					if (!v[nr][nc]) {
						v[nr][nc] = true;
						q.push(pair<int, int>(nr, nc));
					}
					nr += dr[d];
					nc += dc[d];
				}
			}

		}
	}
	return mirror_count - 1;
}