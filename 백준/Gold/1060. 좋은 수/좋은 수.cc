#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int L, N;
vector<int> S;

struct Num {
	int x;
	long long count;

	bool operator < (const Num& o) const {
		if (count == o.count) return x > o.x;
		if (count == -1) return true;
		if (o.count == -1) return false;
		return count > o.count;
	}
};

priority_queue<Num> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> L;

	S.push_back(0);
	for (int l = 0; l < L; ++l) {
		int s;
		cin >> s;
		S.push_back(s);
		pq.push({ s, 0 });
	}

	cin >> N;

	sort(S.begin(), S.end());

	for (int i = 1; i < S.size(); ++i) {
		int left = S[i - 1];
		int right = S[i];

		if (right - left - 1 >= 100) {
			for (int j = 1; j <= 50; ++j) {
				long long x = left + j;
				long long v = (right - x) * (x - left) - 1;
				pq.push({ left + j, v });
				pq.push({ right - j, v });
			}
		}
		else {
			for (int j = 1; j <= right - left - 1; ++j) {
				long long x = left + j;
				long long v = (right - x) * (x - left) - 1;
				pq.push({ left + j, v });
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		int num = S[S.size() - 1] + i;
		pq.push({ num, -1 });
	}

	for (int i = 0; i < N; ++i) {
		cout << pq.top().x << " ";
		pq.pop();
	}

}