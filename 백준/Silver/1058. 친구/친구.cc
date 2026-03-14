#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<long long> adj;
long long one = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int n = 0; n < N; ++n) {
        string line;
        cin >> line;
        long long bit = 0;
        for(int nn = 0; nn < N; ++nn) {
            if(line[nn] == 'Y') bit |= one << nn;
        }
        adj.push_back(bit);
    }

    int max_friends = 0;
    for(int n = 0; n < N; ++n) {
        long long total = adj[n];
        for(int nn = 0; nn < N; ++nn) {
            if(adj[n] & (one << nn)) {
                total |= adj[nn];
            }
        }

        int friends_cnt = 0;
        for(int nn = 0; nn < N; ++nn) {
            if(n != nn && total & (one << nn)) ++friends_cnt;
        }

        if(max_friends < friends_cnt) max_friends = friends_cnt;
    }

    cout << max_friends;
}