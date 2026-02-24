#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Map {
    string map[51][51];  
    pair<int,int> uni[51][51];
    
    Map() {
        for(int r = 1; r < 51; ++r) {
            for(int c = 1; c < 51; ++c) {
                map[r][c] = "";
                uni[r][c] = {r, c};
            }
        }
    }
    
    pair<int,int> find(int r, int c) {
        if(uni[r][c].first == r && uni[r][c].second == c) return uni[r][c];
        return uni[r][c] = find(uni[r][c].first, uni[r][c].second);
    }
    
    void merge(int r1, int c1, int r2, int c2) {
        pair<int,int> x = find(r1, c1);
        pair<int,int> y = find(r2, c2);
        
        if(x.first == y.first && x.second == y.second) return;
        
        if(map[x.first][x.second].empty()) map[x.first][x.second] = map[y.first][y.second];
        
        uni[y.first][y.second] = x;
    }
    
    void update(int r, int c, string& value) {
        pair<int,int> x = find(r, c);
        map[x.first][x.second] = value;
    }
    
    void update_all(string& value1, string& value2) {
        for(int r = 1; r < 51; ++r) {
            for(int c = 1; c < 51; ++c) {
                pair<int,int> x = find(r, c);
                if(!map[x.first][x.second].compare(value1)) {
                    map[x.first][x.second] = value2;
                }
            }
        }
    }
    
    void unmerge(int r, int c) {
        pair<int,int> x = find(r, c);
        vector<pair<int,int>> stack;
        string tmp = map[x.first][x.second];
        
        for(int a = 1; a < 51; ++a) {
            for(int b = 1; b < 51; ++b) {
                pair<int,int> y = find(a, b);
                if(y.first == x.first && y.second == x.second) {
                    stack.push_back({a, b});
                }
            }
        }
        
        while(!stack.empty()) {
            pair<int,int> y = stack.back(); stack.pop_back();
            map[y.first][y.second] = "";
            uni[y.first][y.second] = y;
        }
        map[r][c] = tmp;
    }
    
    string print(int r, int c) {
        pair<int,int> x = find(r, c);
        return map[x.first][x.second];
    } 
};

Map map;

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for(int i = 0; i < commands.size(); ++i) {
        istringstream iss(commands[i]);
        string command, a, b;
        iss >> command >> a >> b;
        
        // update
        if(command.size() == 6) {
            if(iss.eof()) {
                map.update_all(a, b);
            } else {
                string value;
                iss >> value;
                map.update(stoi(a), stoi(b), value);
            }
            
        // merge, print
        } else if(command.size() == 5) {
            if(iss.eof()) {
                string res = map.print(stoi(a), stoi(b));
                if(res.empty()) answer.push_back("EMPTY");
                else answer.push_back(res);
            } else {
                int c, d;
                iss >> c >> d;
                map.merge(stoi(a), stoi(b), c, d);
            }
            
        // unmerge
        } else {
            map.unmerge(stoi(a), stoi(b));
        }
    }
    
    return answer;
}