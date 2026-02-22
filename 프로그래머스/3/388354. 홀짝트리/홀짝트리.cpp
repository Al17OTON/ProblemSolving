#include <vector>
#include <unordered_map>

using namespace std;

struct Union {
    int uni[400001];
    bool check[400001];
    
    Union(int n) {
        for(int i = 0; i < n; ++i) {
            uni[i] = i;
            check[i] = false;
        }
    }
    
    int find(int x) {
        if(uni[x] == x) return x;
        return uni[x] = find(uni[x]);
    }
    void set(int x, int y) {
        x = find(x);
        y = find(y);
        
        if(x == y) return;
        
        uni[y] = x;
    }
};

struct Node {
    int idx;
    bool flag;
    vector<int> adj;  
};

unordered_map<int, Node> hash_map;
Union* uni;

void dfs(int node, int pre, pair<int,int>& status) {
    if(hash_map[node].flag) ++status.first;
    else ++status.second;
    
    vector<int>& adj = hash_map[node].adj;
    for(int i = 0; i < adj.size(); ++i) {
        if(pre != adj[i]) dfs(adj[i], node, status);
    }
}


// 각 노드들을 모두 루트라고 생각하고 상태를 계산하기
// 각 트리마다 노드들의 상태 갯수를 모은다.
// 만약 역홀짝 또는 홀짝이 1인 경우가 있다면 각 상태에 따라 정답에 1 더하기
vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2, 0);
    uni = new Union(nodes.size());
    
    for(int i = 0; i < nodes.size(); ++i) {
        hash_map[nodes[i]] = {i, false, vector<int>(0)};
    }
    for(int i = 0; i < edges.size(); ++i) {
        int from = edges[i][0];
        int to = edges[i][1];
        
        hash_map[from].adj.push_back(to);
        hash_map[to].adj.push_back(from);
        uni->set(hash_map[from].idx, hash_map[to].idx);
    }
    
    for(int i = 0; i < nodes.size(); ++i) {
        int size = hash_map[nodes[i]].adj.size();
        hash_map[nodes[i]].flag = (size % 2 == nodes[i] % 2);
    }
    
    for(int i = 0; i < nodes.size(); ++i) {
        int node = nodes[i];
        int uni_idx = uni->find(hash_map[node].idx);
        if(uni->check[uni_idx]) continue;
        uni->check[uni_idx] = true;
        pair<int,int> res = {0, 0};
        dfs(node, node, res);

        if(res.first == 1) ++answer[0];
        if(res.second == 1) ++answer[1];
    }
    
    return answer;
}
