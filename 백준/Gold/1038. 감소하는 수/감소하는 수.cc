#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int num[11] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
vector<long long> arr;

long long num2long() {
    long long res = num[0];
    long long j = 10;
    for(int i = 1; num[i] != 10; ++i, j *= 10) {
        res += num[i] * j;
    } 
    return res;
}
void dfs(int idx) {
    if(idx == 10) return;

    for(int i = num[idx - 1] + 1; i < num[idx + 1]; ++i) {
        num[idx] = i;
        arr.push_back(num2long());
        dfs(idx + 1);
    }
    num[idx] = 10;
}

int main() {
    cin >> N;

    for(int i = 0; i < 10; ++i) {
        num[0] = i;
        arr.push_back(num2long());
        dfs(1);
    }

    sort(arr.begin(), arr.end());

    cout << (N < arr.size() ? arr[N] : -1);
}