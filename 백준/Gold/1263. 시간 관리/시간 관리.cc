#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int t, s;
};

bool cmp(const Task& a, const Task& b) {
    return a.s > b.s;
}

int N;
vector<Task> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int n = 0; n < N; ++n) {
        int t, s;
        cin >> t >> s;

        arr.push_back({t, s});
    }

    sort(arr.begin(), arr.end(), cmp);

    int sleep = arr[0].s - arr[0].t;
    for(int i = 1; i < arr.size(); ++i) {
        if(sleep > arr[i].s) sleep = arr[i].s;
        sleep -= arr[i].t;
    }

    cout << max(sleep, -1);
}