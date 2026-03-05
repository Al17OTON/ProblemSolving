#include <iostream>

using namespace std;

int N, L;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L;

    int sum = 0;
    for(int i = 1; i < L; ++i) {
        sum += i;
    }

    bool flag = true;
    for(int l = L; l <= 100; ++l) {
        int i = N - sum;
        if(i >= 0 && i % l == 0) {
            int start = i / l;
            for(int j = 0; j < l; ++j) {
                cout << start + j << " ";
            }
            flag = false;
            break;
        }
        sum += l;
    }
    if(flag) cout << -1;
}