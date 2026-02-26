#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct Path {
    int to;
    int w;
    bool operator < (const Path& o) const {
        return this->w > o.w;
    }
};

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

vector<pair<int,int>> adj[50001];
bool gates_hash[50001] = {false};
bool summits_hash[50001] = {false};

void insert_queue(int idx, priority_queue<Path>& target) {
    for(int j = 0; j < adj[idx].size(); ++j) {
        target.push({adj[idx][j].first, adj[idx][j].second});
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    sort(paths.begin(), paths.end(), cmp);
    sort(summits.begin(), summits.end());
    
    for(int i = 0; i < paths.size(); ++i) {
        int from = paths[i][0];
        int to = paths[i][1];
        int w = paths[i][2];
        
        adj[from].push_back({to, w});
        adj[to].push_back({from, w});
    }
    
    for(int i = 0; i < summits.size(); ++i) {
        summits_hash[summits[i]] = true;
    }
    
    for(int i = 0; i < gates.size(); ++i) {
        gates_hash[gates[i]] = true;
    }
    
    int minimum_intensity = 987654321, minimum_idx = 0;
    for(int i = 0; i < summits.size(); ++i) {
        int intensity = 0;
        unordered_set<int> hash_set;
        priority_queue<Path> pq;
        hash_set.insert(summits[i]);
        insert_queue(summits[i], pq);
        
        while(!pq.empty() && minimum_intensity > intensity) {
            Path p = pq.top(); pq.pop();
            if(hash_set.find(p.to) != hash_set.end() || summits_hash[p.to]) continue;
            hash_set.insert(p.to);
            intensity = max(intensity, p.w);
            
            if(gates_hash[p.to]) {
                if(minimum_intensity > intensity) {
                    minimum_intensity = intensity;
                    minimum_idx = summits[i];
                }
                break;
            }
            insert_queue(p.to, pq);
        }
        
    }
    
    answer.push_back(minimum_idx);
    answer.push_back(minimum_intensity);
    
    return answer;
}