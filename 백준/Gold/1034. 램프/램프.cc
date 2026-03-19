#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N, M, K;
string desk[51];
unordered_map<string, int> map;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int n = 0; n < N; ++n) {
        cin >> desk[n];
        ++map[desk[n]];
    }
    cin >> K;

    int max_result = 0;
    for(int n = 0; n < N; ++n) {
        int count = 0;
        for(int m = 0; m < M; ++m) {
            if(desk[n][m] == '0') ++count;
        }

        if(count <= K && count % 2 == K % 2) {
            max_result = max(max_result, map[desk[n]]);
        }
    }

    cout << max_result;
}