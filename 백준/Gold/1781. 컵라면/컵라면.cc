#include <iostream>
#include <queue>
using namespace std;

struct Work {
	int t;
	int cup;
	bool operator < (const Work w) const {
		if (this->t == w.t) return this->cup < w.cup;
		return this->t > w.t;
	}
};

long long result = 0;
int N;
priority_queue<Work> pq;
priority_queue<int, vector<int>, greater<int>> cup;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int a, b;
	for (int n = 0; n < N; n++) {
		cin >> a >> b;
		pq.push({a, b});
	}

	int time = 1;
	while (!pq.empty()) {
		Work w = pq.top(); pq.pop();

		if (time <= w.t) {
			cup.push(w.cup);
			time++;
		}
		else if(cup.top() < w.cup) {
			cup.pop();
			cup.push(w.cup);
		}
	}

	while (!cup.empty()) {
		result += cup.top(); cup.pop();
	}

	cout << result;
}