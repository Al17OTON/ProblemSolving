#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int counter[1000001] = {0};

vector<int> solution(string s) {
    vector<int> answer;
    
    bool flag = false;
    int num_s = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] < '0' || s[i] > '9') {
            if(flag) {
                flag = false;
                ++counter[stoi(s.substr(num_s, i - num_s))];   
            }
            num_s = i + 1;
        } else {
            flag = true;
        }
    }
    
    vector<pair<int,int>> tmp;
    for(int i = 0; i < 1000001; ++i) {
        if(counter[i] > 0) tmp.push_back({counter[i], i});
    }
    sort(tmp.rbegin(), tmp.rend());
    for(int i = 0; i < tmp.size(); ++i) answer.push_back(tmp[i].second);
    
    return answer;
}