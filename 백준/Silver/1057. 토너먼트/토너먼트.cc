#include <iostream>

using namespace std;

int N, K, L, r = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K >> L;
    
    --K;
    --L;
    while(K / 2 != L / 2) {
        K /= 2;
        L /= 2;
        ++r;
    }
    
    cout << r;
}