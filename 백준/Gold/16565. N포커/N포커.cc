#include <iostream>

using namespace std;

int N, result = 0;
int dp[53][53] = { 0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i <= 52; i++) dp[i][0] = 1;
	for (int i = 1; i <= 52; i++) {
		for (int j = 1; j <= 52; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}
	
	for (int i = 1; i <= 13 && N - 4 * i >= 0; i++) {
		if (i % 2 == 1) result = (result + dp[52 - 4 * i][N - 4 * i] * dp[13][i]) % 10007;
		else result = (result - (dp[52 - 4 * i][N - 4 * i] * dp[13][i]) % 10007 + 10007) % 10007;
	}

	cout << result;
}