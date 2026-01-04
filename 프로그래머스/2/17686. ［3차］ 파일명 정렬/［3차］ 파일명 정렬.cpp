#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct File {
    string head;
    string num;
    string tail;
    string head_low;
    int n;
    int idx;
    
    string to_string() {
        return head + num + tail;
    }
};

bool cmp(const File& a, const File& b) {
    if(a.head_low == b.head_low) {
        if(a.n == b.n) {
            return a.idx < b.idx;
        } else {
            return a.n < b.n;
        }
    } else {
        return a.head_low < b.head_low;
    }
}

bool is_head(char c) {
    return c < '0' || c > '9';
}
bool is_num(char c) {
    return c >= '0' && c <= '9';
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> f;
    
    for(int i = 0; i < files.size(); ++i) {
        string& file = files[i];
        int idx = 0;
        string low = "";
        while(is_head(file[idx])) {
            low += tolower(file[idx]);
            ++idx;
        }
        string head = file.substr(0, idx);
        while(is_num(file[idx])) ++idx;
        string num = file.substr(head.size(), idx - head.size());
        string tail = file.substr(idx);
        f.push_back({head, num, tail, low, stoi(num), i});
    }
    
    sort(f.begin(), f.end(), cmp);
    
    for(int i = 0; i < f.size(); ++i) {
        answer.push_back(f[i].to_string());
    }
    
    return answer;
}