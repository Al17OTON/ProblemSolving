#include <iostream>

using namespace std;

int arr[10] = { 0 };

void calc(int a, int level) {
	while (a > 0) {
		arr[a % 10] += level;
		a /= 10;
	}
}

void dfs(int from, int to, int level) {
	while (from % 10 != 0 && from <= to) {
		calc(from, level);
		++from;
	}
	if (from > to) return;
	while (to % 10 != 9 && from <= to) {
		calc(to, level);
		--to;
	}

	int count = to / 10 - from / 10 + 1;
	for (int i = 0; i < 10; ++i) arr[i] += count * level;

	dfs(from / 10, to / 10, level * 10);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;

	dfs(1, N, 1);
	
	for (int i = 0; i < 10; ++i) cout << arr[i] << " ";
}