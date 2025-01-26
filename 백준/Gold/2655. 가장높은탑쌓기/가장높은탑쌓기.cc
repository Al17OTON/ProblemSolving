#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 101
using namespace std;

struct Brick {
	int width, height, weight, no;
	
	bool operator < (const Brick b) const {
		return this->weight < b.weight;
	}
};

int N;
Brick bricks[MAX];
int dp[MAX], stack[MAX], counter[MAX];

void dfs(int idx) {
	if (idx != 0) {
		dfs(stack[idx]);
		cout << bricks[idx].no << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int n = 1; n <= N; n++) {
		int w, h, s;
		cin >> w >> h >> s;
		bricks[n].width = w;
		bricks[n].height = h;
		bricks[n].weight = s;
		bricks[n].no = n;
	}

	sort(bricks + 1, bricks + N + 1);

	int max_idx = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (bricks[i].width > bricks[j].width && dp[i] < dp[j] + bricks[i].height) {
				dp[i] = dp[j] + bricks[i].height;
				stack[i] = j;
				counter[i] = counter[j] + 1;
			}
		}
		if (dp[max_idx] < dp[i]) {
			max_idx = i;
		}
	}

	cout << counter[max_idx] << "\n";
	dfs(max_idx);
}