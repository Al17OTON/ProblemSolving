#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

int col, row, limit;
unordered_map<int, int> check;
unordered_map<string, int> map;

int bfs(const vector<vector<string>>& relation) {
    int res = 0;
    queue<pair<int,int>> q;
    for(int i = 0; i < col; ++i) {
        q.push({(1 << i), i});
    }
    
    while(!q.empty()) {
        pair<int,int> p = q.front(); q.pop();
        int bit = p.first;
        int idx = p.second;
        if(bit >= limit || check.find(bit) != check.end()) continue;
        
        bool flag = true;
        for(int i = 0; i < row; ++i) {
            string key = "";
            for(int j = 0; j < col; ++j) {
                if(bit & (1 << j)) {
                    key += relation[i][j];
                    for(int k = 0; k <= j; ++k) key += "!";
                }
            }
            ++map[key];
            if(map[key] >= 2) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ++res;          
            for(int i = 0; i < limit; ++i) ++check[bit | i];
            
        } else {
            for(int i = idx + 1; i < col; ++i) {
                q.push({bit | (1 << i), i});
            }
        }
    }
    return res;
}

int solution(vector<vector<string>> relation) {
    col = relation[0].size();
    row = relation.size();
    limit = (1 << col);
    
    return bfs(relation);
}