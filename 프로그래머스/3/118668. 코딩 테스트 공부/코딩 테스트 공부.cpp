#include <algorithm>
#include <vector>

using namespace std;

int dp[151][151];
int max_alp = 0, max_cop = 0;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    fill(&dp[0][0], &dp[150][151], 987654321);
    
    for(int i = 0; i < problems.size(); ++i) {
        max_alp = max(max_alp, problems[i][0]);
        max_cop = max(max_cop, problems[i][1]);
    }
    
    if(alp >= max_alp) alp = max_alp;
    if(cop >= max_cop) cop = max_cop;
    
    if(alp == max_alp && cop == max_cop) return 0;
    dp[alp][cop] = 0;

    for(int r = alp; r <= max_alp; ++r) {
        for(int c = cop; c <= max_cop; ++c) {
            dp[min(r + 1, max_alp)][c] = min(dp[min(r + 1, max_alp)][c], dp[r][c] + 1);
            dp[r][min(c + 1, max_cop)] = min(dp[r][min(c + 1, max_cop)], dp[r][c] + 1);
            
            for(int i = 0; i < problems.size(); ++i) {
                if(r < problems[i][0] || c < problems[i][1]) continue;
                int nr = min(r + problems[i][2], max_alp);
                int nc = min(c + problems[i][3], max_cop);
                
                dp[nr][nc] = min(dp[nr][nc], dp[r][c] + problems[i][4]);
            }
        }
    }
   
    
    return dp[max_alp][max_cop];
}