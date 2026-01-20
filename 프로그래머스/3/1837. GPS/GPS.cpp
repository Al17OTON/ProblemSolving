#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    
    int dp[101][201];
    fill(dp[0], dp[101], 987654321);
    vector<int> adj[201];
    
    for(int i = 0; i < m; ++i) {
        int a = edge_list[i][0];
        int b = edge_list[i][1];
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dp[0][gps_log[0]] = 0;
    
    for(int t = 0; t < k - 1; ++t) {
        for(int j = 1; j <= n; ++j) {
            if(dp[t][j] == 987654321) continue;
            
            for(int x = 0; x < adj[j].size(); ++x) {
                int next = adj[j][x];
                dp[t + 1][next] = min(dp[t + 1][next], dp[t][j] + (next == gps_log[t + 1] ? 0 : 1));
            }
            dp[t + 1][j] = min(dp[t + 1][j], dp[t][j] + (j == gps_log[t + 1] ? 0 : 1));
        }
    }
    
    return (dp[k - 1][gps_log.back()] < 987654321 ? dp[k - 1][gps_log.back()] : -1);
}