#include <string>
#include <vector>

using namespace std;

int solution(int N, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> table(N + 1, vector<int>(N + 1, 0));
    
    for(int i = 0; i < results.size(); ++i) {
        table[results[i][0]][results[i][1]] = 1;
        table[results[i][1]][results[i][0]] = -1;
    }
    
    for(int s = 1; s <= N; ++s) {
        for(int e = 1; e <= N; ++e) {
            for(int m = 1; m <= N; ++m) {
                if(table[s][m] == 1 && table[m][e] == 1) {
                    table[s][e] = 1;
                    table[e][s] = -1;
                }
                if(table[s][m] == -1 && table[m][e] == -1) {
                    table[s][e] = -1;
                    table[e][s] = 1;
                }
            }
        }
    }
    
    for(int i = 1; i <= N; ++i) {
        int count = 0;
        for(int j = 1; j <= N; ++j) {
            if(table[i][j] != 0) ++count;
        }
        
        if(count == N - 1) ++answer;
    }
    
    return answer;
}