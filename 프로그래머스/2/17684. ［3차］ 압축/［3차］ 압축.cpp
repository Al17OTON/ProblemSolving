#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> map;

vector<int> solution(string msg) {
    vector<int> answer;
    
    for(int i = 0; i < 26; ++i) {
        string key = "";
        key += 'A' + i;
        map[key] = i;
    }
    
    for(int i = 0; i < msg.size(); ++i) {
        string key = "";
        key += msg[i];
        int idx = i + 1;
        int pre = msg[i] - 'A';
        while(msg.size() > idx) {
            key += msg[idx];
            unordered_map<string, int>::iterator iter = map.find(key);
            if(iter == map.end()) {
                map[key] = map.size();
                break;
            } else {
                pre = iter->second;
            }
            ++idx;
        }
        i = idx - 1;
        answer.push_back(pre + 1);
    }
    
    return answer;
}