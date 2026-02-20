#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct UNION {
    int uni[101];
    
    UNION(int n) {
        for(int i = 0; i <= n; ++i) {
            uni[i] = i;
        }
    }
    
    int find(int x) {
        if(uni[x] == x) return x;
        return uni[x] = find(uni[x]);
    }
    
    bool set(int x, int y) {
        x = find(x);
        y = find(y);
        
        if(x == y) return false;
        uni[y] = x;
        return true;
    }
};


bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];    
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    UNION uni(n + 1);
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i = 0; i < costs.size(); ++i) {
        if(uni.set(costs[i][0], costs[i][1])) {
            answer += costs[i][2];
        }
    }
    
    return answer;
}




