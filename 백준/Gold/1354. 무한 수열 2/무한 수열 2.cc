#include <iostream>
#include <unordered_map>

using namespace std;

long long N, P, Q, X, Y;
unordered_map<long long, long long> map;

long long dfs(long long i) {
    if(i <= 0) return 1;
    if(map.find(i) != map.end()) return map.find(i)->second;

    return map[i] = dfs(i / P - X) + dfs(i / Q - Y);
}

int main() {
    cin >> N >> P >> Q >> X >> Y;

    cout << dfs(N);
}