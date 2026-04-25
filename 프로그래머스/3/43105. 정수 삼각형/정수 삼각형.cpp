#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp(triangle.size(), vector<int>());
    
    for(int i = 0; i < triangle.back().size(); ++i) {
        dp[triangle.size() - 1].push_back(triangle.back()[i]);
    }
    
    for(int r = triangle.size() - 2; r >= 0; --r) {
        for(int c = 0; c < triangle[r].size(); ++c) {
            dp[r].push_back(triangle[r][c] + max(dp[r + 1][c], dp[r + 1][c + 1]));
        }
    }
    
    return dp[0][0];
}