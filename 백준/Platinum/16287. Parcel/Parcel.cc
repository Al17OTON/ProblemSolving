#include <iostream>
#include <vector>
#include <memory.h>

using namespace std; 

vector<int> A;
int dp1[400001] = { 0 }, dp2[400001] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int W, N;
	cin >> W >> N;

	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));

	for (int n = 0; n < N; ++n) {
		int a;
		cin >> a;
		A.push_back(a);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int sum = A[i] + A[j];
			dp1[sum] = i;
			dp2[sum] = j;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int sum = W - (A[i] + A[j]);

			if (sum < 400001 && sum >= 0 && dp1[sum] != -1 && (dp1[sum] != i && dp2[sum] != j && dp1[sum] != j && dp2[sum] != i)) {
				cout << "YES\n";
				return 0;
			}

		}
	}
	cout << "NO\n";
}