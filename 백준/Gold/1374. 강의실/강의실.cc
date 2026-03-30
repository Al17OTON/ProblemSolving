#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Lecture {
    int start, end;
};

bool cmp(const Lecture& a, const Lecture& b) {
    return a.start < b.start;
}

vector<Lecture> vec;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    for(int n = 0; n < N; ++n) {
        int num, start, end;
        cin >> num >> start >> end;
        vec.push_back({start, end});
    }

    sort(vec.begin(), vec.end(), cmp);

    int answer = 0;
    for(int n = 0; n < N; ++n) {
        while(!pq.empty() && pq.top() <= vec[n].start) pq.pop();
        pq.push(vec[n].end);

        answer = max(answer, (int)pq.size());
    }

    cout << answer;
}