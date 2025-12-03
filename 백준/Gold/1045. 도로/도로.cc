#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

class Union {
	int uni[50];

public:

	Union() {
		for (int i = 0; i < N; ++i) uni[i] = i;
	}

	int find(int x) {
		if (uni[x] == x) return x;
		return uni[x] = find(uni[x]);
	}

	bool set(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) return false;

		uni[y] = x;
		return true;
	}
};

// 일단 최소신장트리를 만들고 우선순위에 따라 간선을 M개가 되도록 더하기
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq, tmp;

	for (int i = 0; i < N; ++i) {
		string line;
		cin >> line;
		for (int j = i + 1; j < N; ++j) {
			if (line[j] == 'Y') pq.push({ i, j });
		}
	}

	if (pq.size() < M) {
		cout << -1;
		return 0;
	}

	int count[50] = { 0 };
	int selected = 0;
	Union uni;
	while (!pq.empty()) {
		pair<int, int> p = pq.top(); pq.pop();

		if (uni.set(p.first, p.second)) {
			++count[p.first];
			++count[p.second];
			++selected;
		}
		else {
			tmp.push(p);
		}
	}
	if (selected != N - 1 || selected + tmp.size() < M) {
		cout << -1;
		return 0;
	}

	while (!tmp.empty() && selected != M) {
		pair<int, int> p = tmp.top(); tmp.pop();
		++count[p.first];
		++count[p.second];
		++selected;
	}

	for (int i = 0; i < N; ++i) {
		cout << count[i] << " ";
	}

}