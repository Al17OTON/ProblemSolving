#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int target) {
    int maxi = 987654321;
    vector<vector<int>> dp(target + 1, {maxi, -1});
    
    for(int i = 1; i <= target; ++i) {
        if(i == 50 || i <= 20) {
            dp[i] = {1, 1};
        } else if((i % 2 == 0 && i <= 40) || (i % 3 == 0 && i <= 60)) {
            dp[i] = {1, 0};
        } else {
            for(int j = 1; j <= 60 && j < i; ++j) {
                int total = dp[j][0] + dp[i - j][0];
                int single = dp[j][1] + dp[i - j][1];
                
                if(total < dp[i][0] || (total == dp[i][0] && single > dp[i][1])) {
                    dp[i] = {total, single};
                }
            }   
        }
    }
    return dp[target];
}


/*
      1 2 3 4 5 6 7 .... 20 21
싱글  1 1 1 1 1 1 1 ..... 1  0
전체  1 1 1 1 1 1 1 ..... 1  1
*/
