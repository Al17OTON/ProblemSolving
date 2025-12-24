#include <string>
#include <vector>
#include <algorithm>
#define INF 98765432

using namespace std;

int cost[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    fill(&cost[0][0], &cost[200][200], INF);
    
    for(int i = 0; i < fares.size(); ++i) {
        cost[fares[i][0]][fares[i][1]] = fares[i][2];
        cost[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for(int i = 1; i <= n; ++i) {
        cost[i][i] = 0;
    }
    
    for(int mid = 1; mid <= n; ++mid) {
        for(int start = 1; start <= n; ++start) {
            for(int end = 1; end <= n; ++end) {
                cost[start][end] = min(cost[start][end], cost[start][mid] + cost[mid][end]);
            }
        }
    }
    
    for(int mid = 1; mid <= n; ++mid) {
        answer = min(answer, cost[s][mid] + cost[mid][a] + cost[mid][b]);
    }
    
    return answer;
}