#include <iostream>
#define MAX_N 11
#define MAX_H 31

using namespace std;

int N, M, H;
int adj[MAX_N][MAX_H];

bool dfs(int i, int num);
bool sim();

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> H;

	for (int m = 0; m < M; m++) {
		int a, b;
		cin >> a >> b;

		adj[b][a] = b + 1;
		adj[b + 1][a] = b;
	}

	int count = 0;
	bool flag = false;
	for (; count < 4; count++) {
		flag = dfs(1, count);
		if (flag) break;
	}

	count = flag ? count : -1;
	cout << count;
}

bool dfs(int i, int num) {
	if (num == 0) {
		return sim();
	}
	if (i == N) {
		return false;
	}

	for (int j = 1; j <= H; j++) {
		if (adj[i][j] == 0 && adj[i + 1][j] == 0) {
			adj[i][j] = i + 1;
			adj[i + 1][j] = i;
			if(dfs(i, num - 1)) return true;
			adj[i][j] = 0;
			adj[i + 1][j] = 0;
		}
	}

	return dfs(i + 1, num);
}

bool sim() {
	for (int i = 1; i <= N; i++) {
		int cur = i;
		for (int j = 1; j <= H; j++) {
			if (adj[cur][j] != 0) {
				cur = adj[cur][j];
			}
		}

		if (cur != i) return false;
	}
	return true;
}