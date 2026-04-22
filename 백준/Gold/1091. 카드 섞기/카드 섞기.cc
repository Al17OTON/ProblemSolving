#include <iostream>

using namespace std;

int N;
int P[48], S[48], A[48], orignal[48], tmp[48];

void shuffle() {
    for(int n = 0; n < N; ++n) {
        A[S[n]] = tmp[n];
    }

    for(int n = 0; n < N; ++n) {
        tmp[n] = A[n];
    }
}

bool equal(const int* a, const int* b) {
    for(int n = 0; n < N; ++n) {
        if(a[n] != b[n]) return false;
    }
    return true;
}

bool check() {
    for(int n = 0; n < N; ++n) {
        if(P[A[n]] != n % 3) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int n = 0; n < N; ++n) {
        cin >> P[n];
        A[n] = n;
        orignal[n] = n;
        tmp[n] = n;
    }
    for(int n = 0; n < N; ++n) {
        cin >> S[n];
    }

    int answer = 0;
    while(!check()) {
        if(answer != 0 && equal(A, orignal)) {
            answer = -1;
            break;
        }

        ++answer;
        shuffle();
    }

    cout << answer;
}