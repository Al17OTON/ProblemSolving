#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<string> A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    string line;
    for(int n = 0; n < N; ++n) {
        cin >> line;
        A.push_back(line);
    }

    for(int n = 0; n < N; ++n) {
        cin >> line;
        B.push_back(line);
    }

    int answer = 0;
    for(int r = 0; r < N - 2; ++r) {
        for(int c = 0; c < M - 2; ++c) {
            if(A[r][c] != B[r][c]) {
                A[r][c] = A[r][c] == '1' ? '0' : '1';
                A[r][c + 1] = A[r][c + 1] == '1' ? '0' : '1';
                A[r][c + 2] = A[r][c + 2] == '1' ? '0' : '1';
                A[r + 1][c] = A[r + 1][c] == '1' ? '0' : '1';
                A[r + 1][c + 1] = A[r + 1][c + 1] == '1' ? '0' : '1';
                A[r + 1][c + 2] = A[r + 1][c + 2] == '1' ? '0' : '1';
                A[r + 2][c] = A[r + 2][c] == '1' ? '0' : '1';
                A[r + 2][c + 1] = A[r + 2][c + 1] == '1' ? '0' : '1';
                A[r + 2][c + 2] = A[r + 2][c + 2] == '1' ? '0' : '1';
                ++answer;
            }
        }
    }
    
    for(int r = 0; r < N; ++r) {
        for(int c = 0; c < M; ++c) {
            if(A[r][c] != B[r][c]) {
                answer = -1;
                break;
            }
        }
        if(answer == -1) break;
    }

    cout << answer;
}