#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dr[] = {1, 1, 0};
int dc[] = {0, 1, 1};
int dp[1000][1000] = {0};

int dfs(int r, int c, const vector<vector<int>>& map) {
    if(r >= map.size() || c >= map[r].size() || map[r][c] == 0) return 0;
    if(dp[r][c] != -1) return dp[r][c];
    
    return dp[r][c] = min({dfs(r + 1, c, map), dfs(r + 1, c + 1, map), dfs(r, c + 1, map)}) + 1;
    
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    memset(dp, -1, sizeof(dp));
    for(int r = 0; r < board.size(); ++r) {
        for(int c = 0; c < board[r].size(); ++c) {
            answer = max(answer, dfs(r, c, board));
        }
    }
    
    return answer * answer;
}