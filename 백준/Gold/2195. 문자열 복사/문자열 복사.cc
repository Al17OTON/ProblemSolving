#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S, P;
int answer = 0;

int main() {
    cin >> S >> P;
    
    for(int i = 0; i < P.size(); ++i) {
        int maximum = 0;
        for(int j = 0; j < S.size(); ++j) {
            if(P[i] == S[j]) {
                int idx = 1;
                while(i + idx < P.size() && j + idx < S.size() && P[i + idx] == S[j + idx]) {
                    ++idx;
                }
                maximum = max(maximum, idx - 1);
            }
        }
        i += maximum;
        ++answer;
    }

    cout << answer;
}