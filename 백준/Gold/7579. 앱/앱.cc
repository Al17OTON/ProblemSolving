#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 101

using namespace std;

struct App {
	int mem, cost;
	
	bool operator < (const App a) const {
		if (this->cost == a.cost) return this->mem < a.mem;
		return this->cost > a.cost;
	}
};

int N, M, total_cost = 0;
App arr[MAX];
int dp[MAX][MAX * MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int n = 0; n < N; n++) {
		cin >> arr[n].mem;
	}
	for (int n = 0; n < N; n++) {
		cin >> arr[n].cost;
		total_cost += arr[n].cost;
	}

	for (int j = 0; j <= total_cost; j++) {
		if (arr[0].cost <= j) dp[0][j] = arr[0].mem;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= total_cost; j++) {
			if (j - arr[i].cost >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i].cost] + arr[i].mem);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	
	for (int j = 0; j <= total_cost; j++) {
		if (dp[N - 1][j] >= M) {
			cout << j;
			break;
		}
	}

}