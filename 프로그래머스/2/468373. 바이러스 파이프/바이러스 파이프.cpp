#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

struct Pipe {
    int to, type;  
};

int start;
vector<Pipe> adj[101];

int permutation(int idx, vector<int>& sequence, int pre) {
    if(idx == sequence.size()) {
        vector<int> pipes[4];
        unordered_set<int> set;
        set.insert(start);
        for(int i = 0; i < adj[start].size(); ++i) {
            pipes[adj[start][i].type].push_back(adj[start][i].to);
        }
        
        for(int i = 0; i < sequence.size(); ++i) {
            int type = sequence[i];
            while(!pipes[sequence[i]].empty()) {
                int target = pipes[sequence[i]].back(); pipes[sequence[i]].pop_back();
                if(set.find(target) == set.end()) {
                    set.insert(target);
                    for(int j = 0; j < adj[target].size(); ++j) {
                        pipes[adj[target][j].type].push_back(adj[target][j].to);
                    }
                }
            }
        }
        return set.size();
    }
    
    int res = 0;
    for(int i = 1; i <= 3; ++i) {
        if(i != pre) {
            sequence[idx] = i;
            res = max(res, permutation(idx + 1, sequence, i));
        }
    }
    
    return res;
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    start = infection;
    
    for(int i = 0; i < edges.size(); ++i) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    
    vector<int> seq(k);
    return permutation(0, seq, 0);
}