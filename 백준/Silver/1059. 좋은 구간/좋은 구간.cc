#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, N;
vector<int> S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> L;
    for(int l = 0; l < L; ++l) {
        int element;
        cin >> element;
        S.push_back(element);
    }
    cin >> N;

    S.push_back(0);
    sort(S.begin(), S.end());

    int answer = 0;
    for(int i = 1; i < S.size(); ++i) {
        if(S[i - 1] < N && S[i] > N) {
            int left = N - S[i - 1];
            int right = S[i] - N;
            answer = (left - 1) * right + right - 1;
            break;
        }
    }

    cout << answer;
}