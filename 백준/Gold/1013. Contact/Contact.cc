#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    regex reg("(100+1+|01)+");
    string result = "";
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
        string wave;
        cin >> wave;
        
        result += (regex_match(wave, reg) ? "YES\n" : "NO\n");
    }
    cout << result;
}