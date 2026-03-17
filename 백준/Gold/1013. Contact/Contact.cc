#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> tmp;
    unordered_set<string> set;

    string sss = "01";
    while(sss.size() <= 200) {
        tmp.push_back(sss);
        sss += "01";
    }
    
    string s = "10", ss = "";
    for(int i = 1; i < 200; ++i) {
        s += '0';
        for(int j = 1; j < 200 - i; ++j) {
            ss += '1';
            set.insert(s + ss);

            for(int k = 0; k < tmp.size() && tmp[k].size() + s.size() + ss.size() <= 200; ++k) {
                set.insert(s + ss + tmp[k]);
            }
        }
        ss = "";
    }

    string result = "";
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
        string wave;
        cin >> wave;

        if(wave.size() < 2) {
            result += "NO\n";
            continue;
        }

        int i;
        for(i = 0; i < wave.size() - 1; i += 2) {
            if(wave[i] != '0' || wave[i + 1] != '1') {
                break;
            } 
        }

        bool flag = true;
        for(int j = i; j < wave.size(); ++j) {
            if(j - i >= 3 && wave[j - 2] == '1' && wave[j - 1] == '0' && wave[j] == '0') {
                if(set.find(wave.substr(i, j - i - 2)) == set.end()) {
                    flag = false;
                    break;
                }
                i = j - 2;
            }
        }

        if(i < wave.size() && set.find(wave.substr(i)) == set.end()) {
            flag = false;
        }
        result += (flag ? "YES\n" : "NO\n");
    }
    cout << result;
}