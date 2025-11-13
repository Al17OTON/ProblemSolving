#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a.size() < b.size();
}

bool v[100001] = {false};

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> tuple;
    int i = 2;
    while(i < s.size() - 2) {
        vector<int> tmp;
        int num_s = i;
        while(s[i] != '}') {
            if(s[i] == ',') {
                tmp.push_back(stoi(s.substr(num_s, i - num_s)));
                num_s = i + 1;
            }
            ++i;
        }
        tmp.push_back(stoi(s.substr(num_s, i - num_s)));
        tuple.push_back(tmp);
        i += 3;   
    }
    
    sort(tuple.begin(), tuple.end(), cmp);
    
    for(int i = 0; i < tuple.size(); ++i) {
        for(int j = 0; j < tuple[i].size(); ++j) {
            if(!v[tuple[i][j]]) {
                answer.push_back(tuple[i][j]);
                v[tuple[i][j]] = true;
            }
        }
    }

    return answer;
}