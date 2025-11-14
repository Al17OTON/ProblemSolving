#include <string>
#include <vector>

using namespace std;

struct Ban {
    int length;
    vector<pair<int, char>> vec;
};

bool check(const string& user, const Ban& ban) {
    if(ban.length != user.size()) return false;
    
    for(int i = 0; i < ban.vec.size(); ++i) {
        if(user[ban.vec[i].first] != ban.vec[i].second) return false;
    }
    return true;
}
vector<Ban> banned;
vector<string> users;
bool dup[256] = {false};

int dfs(int v, vector<string>& select) { 
    if(select.size() == banned.size()) {
        bool vv[8] = {false};
        int count = 0;
        for(int i = 0; i < select.size(); ++i) {
            for(int j = 0; j < banned.size(); ++j) {
                if(!vv[j] && check(select[i], banned[j])) {
                    vv[j] = true;
                    ++count;
                    break;
                }
            }
        }
        if(!dup[v] && count == select.size()) {
            dup[v] = true;
            return 1;
        }
        return 0;
    }
    
    int res = 0;
    for(int i = 0; i < users.size(); ++i) {
        if(((v >> i) & 1) == 0) {
            select.push_back(users[i]);
            res += dfs(v | (1 << i), select);
            select.pop_back();
        }
    }
    return res;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    users = user_id;
    
    for(int i = 0; i < banned_id.size(); ++i) {
        string& id = banned_id[i];
        vector<pair<int, char>> vec;
        
        for(int j = 0; j < id.size(); ++j) {
            if(id[j] != '*') vec.push_back({j, id[j]});
        }
        banned.push_back({(int)id.size(), vec});
    }
    vector<string> tmp;
    return dfs(0, tmp);
}