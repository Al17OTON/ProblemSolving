#include <iostream>
#include <algorithm>

using namespace std;

int L, R, K;

int main() {
    cin >> L >> R >> K;

    if(K == 2) {
        cout << max(0, R - max(L, 3) + 1);
    } else if(K == 3) {
        cout << max(0, (R / 3 - 1) - max(0, (L - 1) / 3 - 1));
    } else if(K == 4) {
        cout << max(0, (R / 2) - (max(14, L) - 1) / 2) + (L <= 10 && R >= 10 ? 1 : 0);
    } else {
        cout << max(0, (R / 5) - (max(15, L) - 1) / 5);
    }
}