#include <iostream>

using namespace std;

int N, K;

int main() {
    cin >> N >> K;

    for(int i = 0; i < K - 1; ++i) {
        for(int j = (1 << 30); j > 0; j /= 2) {
            if(j < N) {
                N -= j;
                break;
            }
        }
    }

    for(int i = 1; i <= (1 << 30); i *= 2) {
        if(i >= N) {
            cout << i - N;
            break;
        }
    }
}