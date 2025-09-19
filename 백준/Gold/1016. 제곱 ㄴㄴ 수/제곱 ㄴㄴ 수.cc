#include <iostream>

using namespace std;

long long MIN, MAX;
bool v[1000001] = {false};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> MIN >> MAX;

	int answer = 0;
	long long d = 2;
	long long dd;
	while ((dd = d * d) <= MAX) {
		long long start = MIN / dd;
		if (MIN % dd != 0) {
			++start;
		}

		long long s;
		while ((s = start * dd) <= MAX) {
			if (!v[s - MIN]) {
				v[s - MIN] = true;
				++answer;
			}
			++start;
		}

		++d;
	}
	

	cout << (MAX - MIN + 1) - answer;
}