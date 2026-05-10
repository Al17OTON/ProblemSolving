#include <string>
#include <vector>

using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    for(int d = 0; d < 4; ++d) {
        int nr = h + dr[d];
        int nc = w + dc[d];
        
        if(nr < 0 || nr >= board.size() || nc < 0 || nc >= board.size() || board[h][w].size() != board[nr][nc].size()) continue;
        
        bool flag = true;
        for(int i = 0; i < board[h][w].size(); ++i) {
            if(board[h][w][i] != board[nr][nc][i]) {
                flag = false;
                break;
            }
        }
        answer += flag ? 1 : 0;
    }
    
    return answer;
}