#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> nums;

void dfs(long long num, int idx) {
    if(idx == 0) {
        for(int i = 0; i < 10; ++i) {
            nums.push_back(i);
            dfs(i, 1);
        }
    } else {
        for(int i = num % 10 - 1; i >= 0; --i) {
            long long next = num * 10 + i;
            nums.push_back(next);
            dfs(next, idx + 1);
        }
    }
}

int main() {
    int N;
    cin >> N;

    dfs(0, 0);

    sort(nums.begin(), nums.end());

    if(nums.size() >= N) cout << nums[N - 1];
    else cout << -1;
}