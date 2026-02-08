#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool check_pre(const string& pre, const string& cur) {
    return pre.back() == cur.front();
}
bool check_dup(const string& a) {
    static unordered_set<string> set;
    
    if(set.find(a) != set.end()) return false;
    set.insert(a);
    return true;
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    
    string tmp = "";
    tmp += words[0][0];
    string& pre = tmp;
    for(int i = 0; i < words.size(); ++i) {
        string& word = words[i];
        
        if(!check_pre(pre, word) || !check_dup(word)) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        
        pre = words[i];
    }

    return answer;
}