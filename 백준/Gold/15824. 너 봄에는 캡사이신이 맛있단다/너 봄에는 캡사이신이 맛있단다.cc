#include <iostream>
#include <algorithm>
#define MAX 300001
#define MOD 1000000007

using namespace std;

int N;
long long menu[MAX] = { 0 }, dp[MAX] = { 0 };

long long pow(long long a, long long b);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	dp[0] = 1;

	cin >> N;

	for (int n = 0; n < N; n++) {
		cin >> menu[n];
	}
	sort(menu, menu + N);

	long long plus = 0, minus = 0;
	for (int i = 0; i < N - 1; i++) {
		plus += (pow(2, N - 1 - i) - 1) * menu[N - 1 - i];
		minus += (pow(2, N - 1 - i) - 1) * menu[i];
		plus %= MOD;
		minus %= MOD;
	}

	cout << (plus + MOD - minus) % MOD;
	
}

long long pow(long long a, long long b) {
	if (dp[b] != 0) return dp[b];
	long long tmp;

	if (b == 0) return dp[0];

	tmp = pow(a, b / 2) % MOD;

	if (b % 2 == 1) return dp[b] = tmp * tmp % MOD * a % MOD;
	return dp[b] = tmp * tmp % MOD;
}