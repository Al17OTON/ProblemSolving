#include <iostream>
#include <queue>

using namespace std;

void bfs(int N) {
    queue<long long> q;
    for(int i = 0; i < 10; ++i) q.push(i);
    int n = 1;

    while(n < N && !q.empty()) {
        long long num = q.front(); q.pop();
        
        for(int i = 0; i < num % 10; ++i) {
            q.push(num * 10 + i);
        }
        ++n;
    }

    if(q.empty()) cout << -1;
    else cout << q.front();
}

int main() {
    int N;
    cin >> N;

    bfs(N);
}