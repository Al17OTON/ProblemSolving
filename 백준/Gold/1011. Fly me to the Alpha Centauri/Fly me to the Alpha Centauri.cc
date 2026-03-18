#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;

    for(int t = 0; t < T; ++t) {
        long long x, y, k = 1;
        cin >> x >> y;

        while(x + k <= y - k) {
            x += k;
            y -= k;
            ++k;
        }

        int answer = (k - 1) * 2;
        if(x != y) {
            if(y - x <= k) ++answer;
            else answer += 2;
        }
        
        cout << answer << "\n";
    }
}