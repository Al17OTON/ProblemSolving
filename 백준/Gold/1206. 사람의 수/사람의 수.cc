#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<int> score;

int main() {
    cin >> N;
    for(int n = 0; n < N; ++n) {
        string s;
        cin >> s;
        int num = 0;
        for(int i = s.size() - 3; i < s.size(); ++i) {
            num *= 10;
            num += s[i] - '0';
        }
        score.push_back(num);
    }

    int base = 1;
    while(true) {
        bool flag = true;
        for(int n = 0; n < N; ++n) {
            bool pass = false;
            for(int i = 0; i < base * 1000; i += 1000) {
                if(i / base == score[n]) {
                    pass = true;
                    break;
                }
            }
            if(!pass) {
                flag = false;
                break;
            }
        }
        
        if(flag) break;
        ++base;
    }
    
    cout << base;
}