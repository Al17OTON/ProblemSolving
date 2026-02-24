#include <vector>

using namespace std;

int sum[1002][1002] = {0};
int N, M;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    N = board.size();
    M = board[0].size();
    
    for(int i = 0; i < skill.size(); ++i) {
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5] * (skill[i][0] == 1 ? -1 : 1);
        
        sum[r1][c1] += degree;
        sum[r1][c2 + 1] -= degree;
        sum[r2 + 1][c1] -= degree;
        sum[r2 + 1][c2 + 1] += degree;
    }
    
    int answer = 0;
    
    for(int c = 0; c < M; ++c) {
        for(int r = 1; r < N; ++r) {
            sum[r][c] += sum[r - 1][c];
        }
    }
    
    for(int r = 0; r < N; ++r) {
        for(int c = 1; c < M; ++c) {
            sum[r][c] += sum[r][c - 1];
        }
    }

    for(int r = 0; r < N; ++r) {
        for(int c = 0; c < M; ++c) {
            board[r][c] += sum[r][c];
            if(board[r][c] > 0) ++answer;
        }
    }
    
    return answer;
}