#include <iostream>
#include <map>

using namespace std;

long long N, P, Q, X, Y;
map<long long, long long> m;

long long dfs(long long i) {
    if(i <= 0) return 1;
    if(m.find(i) != m.end()) return m.find(i)->second;

    return m[i] = dfs(i / P - X) + dfs(i / Q - Y);
}

int main() {
    cin >> N >> P >> Q >> X >> Y;

    cout << dfs(N);
}