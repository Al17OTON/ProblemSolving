#include <iostream>
#include <vector>

using namespace std;

bool v[(1 << 20) + 1] = {false};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N;
    vector<int> ban;

    cin >> T >> N;

    for(int n = 0; n < N; ++n) {
        int K, bit = 0;
        cin >> K;
        for(int k = 0; k < K; ++k) {
            int ingre;
            cin >> ingre;
            bit |= 1 << (ingre - 1);
        }
        if(v[bit]) continue;
        v[bit] = true;
        ban.push_back(bit);
    }

    int answer = 0;
    for(int i = 0; i < 1 << T; ++i) {
        bool flag = true;
        for(int j = 0; j < ban.size(); ++j) {
            if((ban[j] & i) == ban[j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ++answer;
        } 
    }

    cout << answer;
}