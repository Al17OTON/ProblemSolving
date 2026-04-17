#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int euclidean(int a, int b) {
    while(b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> vec(N, 0), sub;
    
    for(int n = 0; n < N; ++n) {
        cin >> vec[n];
    }

    sort(vec.begin(), vec.end());

    for(int n = 0; n < N - 1; ++n) {
        sub.push_back(vec[n + 1] - vec[n]);
    }

    int result = sub[0];
    for(int i = 1; i < sub.size(); ++i) {
        result = euclidean(result, sub[i]);
    }
    cout << result;
}