#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string code, password;
unordered_map<char, int> hash_map;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> code >> password;

    for(int i = 0; i < code.size(); ++i) {
        hash_map[code[i]] = i + 1;
    }

    int answer = 0, mul = 1;
    for(int i = password.size() - 1; i >= 0; --i) {
        answer += hash_map[password[i]] * mul;
        mul *= code.size();
        answer %= 900528;
        mul %= 900528;
    }

    cout << answer;
}