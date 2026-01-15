#include <vector>
#include <memory.h>

using namespace std;

int MOD = 20170805;
int dp[2][501][501];
int dr[] = {1, 0};
int dc[] = {0, 1};

int dfs(int r, int c, int pre, const vector<vector<int>>& map) {
    if(r >= map.size() || c >= map[0].size()) return 0;
   
    if(map[r][c] == 0) {
        if(dp[0][r][c] != -1) return dp[0][r][c];
        return dp[0][r][c] = (dfs(r + 1, c, 0, map) + dfs(r, c + 1, 1, map)) % MOD;
    } else if(map[r][c] == 2) {
        if(dp[pre][r][c] != -1) return dp[pre][r][c];
        return dp[pre][r][c] = dfs(r + dr[pre], c + dc[pre], pre, map);
    } else return 0;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {    
    memset(dp, -1, sizeof(dp));
    dp[0][city_map.size() - 1][city_map[0].size() - 1] = 1;
    
    return dfs(0, 0, 0, city_map);
}