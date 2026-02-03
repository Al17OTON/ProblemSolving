#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N;
long long answer = 0;
priority_queue<int> lower;
priority_queue<int, vector<int>, greater<int>> higher;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	int pre;
	int x, y;

	cin >> x >> y;
	lower.push(y);
	answer += abs(x);
	pre = y;
	cout << pre << " " << answer << "\n";

	for (int n = 1; n < N; ++n) {
		cin >> x >> y;

		int s_low = lower.size();
		int s_high = higher.size();

		if (s_low == s_high) lower.push(y);
		else if (s_high + 1 == s_low) higher.push(y);

		if (!lower.empty() && !higher.empty() && lower.top() > higher.top()) {
			int l = lower.top(); lower.pop();
			int h = higher.top(); higher.pop();
			higher.push(l);
			lower.push(h);
		}

		int mid = lower.top();

		answer += ((long long)abs(pre - mid) * (long long)abs(s_high - s_low)) + abs(y - mid) + abs(x);

		cout << mid << " " << answer << "\n";
		pre = mid;
	}
}