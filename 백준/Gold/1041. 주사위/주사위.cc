#include <iostream>
#include <algorithm>

using namespace std;

long long N, A, B, C, D, E, F;
int main() {
    cin >> N;

    cin >> A >> B >> C >> D >> E >> F;

    long long three_side = min({A + B + C, A + B + D, A + D + E, A + E + C, B + C + F, B + F + D, C + E + F, D + F + E});
    long long two_side = min({A + B, A + C, A + D, A + E, B + F, B + C, B + D, C + E, C + F, D + F, D + E, E + F});
    long long one_side = min({A, B, C, D, E, F});

    if(N == 1) cout << (A + B + C + D + E + F) - max({A, B, C, D, E, F});
    else {
        long long answer = 0;
        answer += 4 * three_side;
        answer += ((N - 1) * 4 + (N - 2) * 4) * two_side;
        answer += ((N - 1) * (N - 2) * 4 + (N - 2) * (N - 2)) * one_side;
        cout << answer;
    }
    
}