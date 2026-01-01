#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

struct Node {
	int idx;
	long long w;

	bool operator < (const Node& o) const {
		return this->w > o.w;
	}
};

int N, M, K, S, p, q;
int danger[100001] = { 0 };
long long dist[100001];
vector<int> adj[100001];

void dfs(int city, int depth) {
	if (depth > S) return;
	if (danger[city] != -1 && danger[city] <= depth) return;

	danger[city] = depth;

	for (int i = 0; i < adj[city].size(); ++i) {
		dfs(adj[city][i], depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K >> S;
	cin >> p >> q;

	queue<int> tmp;
	for (int k = 0; k < K; ++k) {
		int city;
		cin >> city;
		tmp.push(city);
	}
	
	for (int m = 0; m < M; ++m) {
		int from, to;
		cin >> from >> to;

		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	memset(danger, -1, sizeof(danger));
	while (!tmp.empty()) {
		int city = tmp.front(); tmp.pop();
		dfs(city, 0);
	}

	fill(dist + 2, dist + N + 1, 987654321000);
	priority_queue<Node> pq;
	pq.push({ 1, 0 });

	while (!pq.empty()) {
		Node node = pq.top(); pq.pop();

		if (dist[node.idx] < node.w) continue;

		for (int i = 0; i < adj[node.idx].size(); ++i) {
			int next = adj[node.idx][i];
			if (danger[next] == 0) continue;
			long long w = node.w + (danger[next] == -1 ? p : q);
			if (dist[next] > w) {
				dist[next] = w;
				pq.push({ next, w });
			}
		}
	}
	
	cout << dist[N] - (danger[N] == -1 ? p : q);
}