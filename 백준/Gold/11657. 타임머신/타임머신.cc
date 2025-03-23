#include <cstdio>
#include <vector>
#define MAX_N 501
#define INF 987654321

using namespace std;

struct EDGE {
	int from, to, cost;
};

int N, M;
vector<EDGE> edges;
void bellman();
int main() {
	scanf("%d %d", &N, &M);

	for (int m = 0; m < M; ++m) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		edges.push_back({a, b, c });
	}
	bellman();
}

void bellman() {
	long long dist[MAX_N];
	fill(dist, dist + MAX_N, INF);

	dist[1] = 0;
	bool flag = false;

	for (int v = 0; v < N; ++v) {
		for (int e = 0; e < M; ++e) {
			EDGE edge = edges[e];

			if (dist[edge.from] != INF && dist[edge.from] + edge.cost < dist[edge.to]) {
				dist[edge.to] = dist[edge.from] + edge.cost;
				if (v == N - 1) {
					flag = true;
					break;
				}
			}
		}
	}

	if (flag) {
		printf("-1\n");
	}
	else {
		for (int i = 2; i <= N; ++i) printf("%d\n", dist[i] == INF ? -1 : dist[i]);
	}
}