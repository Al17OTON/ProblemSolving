#include <string>
#include <vector>

using namespace std;

// true - 올바른, false - 균형잡힌
bool check(const string& p) {
    int open = 0;
    for(int i = 0; i < p.size(); ++i) {
        if(p[i] == '(') ++open;
        else --open;
        
        if(open < 0) return false;
    }
    return true;
}

int find(const string& p) {
    int open = 0;
    for(int i = 0; i < p.size(); ++i) {
        if(p[i] == '(') ++open;
        else --open;
        
        if(open == 0) return i;
    }
    return p.size() - 1;
}

string reverse(const string& p) {
    string a = "";
    for(int i = 1; i < p.size() - 1; ++i) {
        a += (p[i] == '(') ? ')' : '(';
    }
    return a;
}

string dfs(string p) {
    if(check(p)) return p;
    
    int idx = find(p);
    string u = p.substr(0, idx + 1);
    string v = p.substr(idx + 1);
    
    if(!check(u)) {
        return "(" + dfs(v) + ")" + reverse(u);
    } else {
        return u + dfs(v);
    }
    
}

string solution(string p) {
    return dfs(p);
}