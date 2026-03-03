#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    
    int pack = 987654321;
    int single = 987654321;
    for(int m = 0; m < M; ++m) {
        int a, b;
        cin >> a >> b;
        
        pack = min(pack, a);
        single = min(single, b);
    }

    cout << min({(N / 6 + 1) * pack, (N / 6) * pack + (N % 6) * single, N * single});
}