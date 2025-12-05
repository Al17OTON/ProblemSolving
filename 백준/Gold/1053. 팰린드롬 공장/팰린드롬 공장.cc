#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int dp[50][50];

int dfs(const string& s, int left, int right) {
	if (dp[left][right] != -1) return dp[left][right];
	if (left >= right) return 0;

	return dp[left][right] = min({ dfs(s, left + 1, right) + 1, dfs(s, left, right - 1) + 1, dfs(s, left + 1, right - 1) + (s[left] != s[right]) });
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> vec;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); ++i) {
		for (int j = i + 1; j < str.size(); ++j) {
			string a = str;
			char tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			vec.push_back(a);
		}
	}

	memset(dp, -1, sizeof(dp));
	int res = dfs(str, 0, str.size() - 1);
	for (int i = 0; i < vec.size(); ++i) {
		memset(dp, -1, sizeof(dp));
		res = min(res, dfs(vec[i], 0, vec[i].size() - 1) + 1);
	}
	cout << res;
}