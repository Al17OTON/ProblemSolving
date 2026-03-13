#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
string rect[51];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    
    for(int n = 0; n < N; ++n) {
        cin >> rect[n];
    }

    int max_size = 1;
    for(int r = 0; r < N; ++r) {
        for(int c = 0; c < M; ++c) {
            for(int s = max_size + 1; s <= min(N, M); ++s) {
                if(r + s > N || c + s > M) break;

                if(rect[r][c] == rect[r][c + s - 1] && rect[r][c] == rect[r + s - 1][c] && rect[r][c] == rect[r + s - 1][c + s - 1]) {
                    max_size = s;
                }
            }
        }
    }

    cout << max_size * max_size;
}