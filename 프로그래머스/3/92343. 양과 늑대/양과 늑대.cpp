#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    vector<int> child;
};

struct Sheep {
    int size;
    int wolf_bit;
};

struct Union {
    int uni[18];
    int size[18];
    int bit[18];
    
    Union(int n) {
        for(int i = 0; i < n; ++i) {
            uni[i] = i;
            size[i] = 1;
            bit[i] = 0;
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
        
        uni[x] = y;
        size[y] += size[x];
    }
};

int N;
Node tree[18];
vector<Sheep> sheep;
Union uni(18);

void dfs(int idx, int pre, int wolf_bit) {
    bool flag = false;
    if(tree[idx].data == 0) {
        if(pre != -1) uni.set(idx, pre);
        else {
            uni.bit[idx] = wolf_bit;
        }
        flag = true;
    } 
    if(tree[idx].child.empty()) return;
    
    dfs(tree[idx].child[0], (flag ? idx : -1), (flag ? wolf_bit : wolf_bit | (1 << idx)));
    
    if(tree[idx].child.size() == 2) dfs(tree[idx].child[1], (flag ? idx : -1), (flag ? wolf_bit : wolf_bit | (1 << idx)));
}

int permutation(int wolf_bit, int wolf_count, int sheep_count, int v) {
    int res = sheep_count;
    for(int i = 0; i < sheep.size(); ++i) {
        if(v & (1 << i)) continue;
        
        int next_bit = wolf_bit | sheep[i].wolf_bit;
        int new_wolf_count = 0;
        for(int n = 1; n < N; ++n) {
            int bit = 1 << n;
            if(!(wolf_bit & bit) && (sheep[i].wolf_bit & bit)) ++new_wolf_count;
        }
        
        if(wolf_count + new_wolf_count >= sheep_count) continue;
        res = max(res, permutation(next_bit, wolf_count + new_wolf_count, sheep_count + sheep[i].size, v | (1 << i)));
    }
    return res;
}


// N <= 17 이므로 인접한 양들을 집합으로 모아준다면 순열을 8!까지 줄일 수 있다...
int solution(vector<int> info, vector<vector<int>> edges) {
    N = info.size();
    for(int i = 0; i < info.size(); ++i) {
        tree[i].data = info[i];
    }
    
    for(int i = 0; i < edges.size(); ++i) {
        tree[edges[i][0]].child.push_back(edges[i][1]);
    }
    
    dfs(0, -1, 0);
    
    for(int i = 1; i < N; ++i) {
        if(tree[i].data == 0 && uni.find(i) == i) {
            sheep.push_back({uni.size[i], uni.bit[i]});
        }
    }
    
    return permutation(0, 0, uni.size[0], 0);
}