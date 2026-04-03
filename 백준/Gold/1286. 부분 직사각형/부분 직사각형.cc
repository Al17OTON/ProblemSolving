#include <iostream>

using namespace std;

int N, M;

char map[51][51];
long long sum[26] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for(int n = 0; n < N; ++n) {
        cin >> map[n];
    }

    for(int n = 0; n < N * 2; ++n) {
        for(int m = 0; m < M * 2; ++m) {
            sum[map[n % N][m % M] - 'A'] += (n + 1) * (N * 2 - n) * (m + 1) * (M * 2 - m);
        }
    }

    for(int i = 0; i < 26; ++i) {
        cout << sum[i] << "\n";
    }
}