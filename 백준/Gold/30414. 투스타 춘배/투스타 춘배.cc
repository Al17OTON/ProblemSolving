#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Mountain {
	int h, target;
	vector<int> adj;
};

int N, P;
vector<Mountain> mountain;

int dfs(int idx, int pre) {
	Mountain& m = mountain[idx];

	int need = 0;

	for (int i = 0; i < m.adj.size(); ++i) {
		if (m.adj[i] == pre) continue;
		need += dfs(m.adj[i], idx);
	}
	return max(0, need + (m.target - m.h));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> P;

	int h, from, to;
	for (int n = 0; n < N; ++n) {
		cin >> h;
		vector<int> vec;
		mountain.push_back({ h, 0, vec });
	}
	for (int n = 0; n < N; ++n) {
		cin >> h;
		mountain[n].target = h;
	}

	for (int n = 0; n < N - 1; ++n) {
		cin >> from >> to;
		--from;
		--to;
		mountain[from].adj.push_back(to);
		mountain[to].adj.push_back(from);
	}

	cout << dfs(P - 1, -1);
}