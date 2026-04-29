#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for(int i = 0; i < s.size(); ++i) {
        int count = 0;
        int idx = -1;
        string result = "";
        for(int j = 0; j < s[i].size(); ++j) {
            result += s[i][j];
            if(result.size() >= 3 && result[result.size() - 1] == '0' && result[result.size() - 2] == '1' && result[result.size() - 3] == '1') {
                result.pop_back();
                result.pop_back();
                result.pop_back();
                ++count;
            }
        }
        
        string tmp = "";
        for(int j = 0; j < count; ++j) {
            tmp += "110";
        }
        
        for(int j = result.size() - 1; j >= 0; --j) {
            if(result[j] == '0') {
                idx = j;
                break;
            }
        }
        
        if(idx == -1 || result.size() == idx - 1) result = tmp + result;
        else {
            result = result.substr(0, idx + 1) + tmp + result.substr(idx + 1);
        }
        
        answer.push_back(result);
    }
    
    return answer;
}