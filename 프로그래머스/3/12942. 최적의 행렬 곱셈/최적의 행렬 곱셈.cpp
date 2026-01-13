#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int dp[201][201] = {0};

int dfs(int s, int e, const vector<vector<int>>& mat) {
    if(e - s == 1) return 0;
    if(dp[s][e] != -1) return dp[s][e];
    
    int res = 987654321;
    for(int m = s + 1; m < e; ++m) {
        int l = dfs(s, m, mat);
        int r = dfs(m, e, mat);
        
        res = min(res, l + r + (mat[s][0] * mat[m][0] * mat[e - 1][1]));
    }
    return dp[s][e] = res;
}

int solution(vector<vector<int>> mat) {
    memset(dp, -1, sizeof(dp));
    
    return dfs(0, mat.size(), mat);
}







