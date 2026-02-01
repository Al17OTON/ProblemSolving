#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    vector<pair<int,int>> st;
    while(true) {
        for(int i = 0; i < m - 1; ++i) {
            for(int j = 0; j < n - 1; ++j) {
                char cur = board[i][j];
                if(cur == ' ') continue;
                if(cur == board[i + 1][j] && cur == board[i][j + 1] && cur == board[i + 1][j + 1]) {
                    st.push_back({i, j});
                    st.push_back({i + 1, j});
                    st.push_back({i, j + 1});
                    st.push_back({i + 1, j + 1});
                }
            }
        }
        
        if(st.empty()) break;
        
        while(!st.empty()) {
            pair<int, int> pop = st.back(); st.pop_back();
            if(board[pop.first][pop.second] != ' ') {
                ++answer;
                board[pop.first][pop.second] = ' ';
            }
        }
        
        for(int i = m - 2; i >= 0; --i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == ' ') continue;
                int r = i + 1;
                while(r < m && board[r][j] == ' ') ++r;
                char tmp = board[i][j];
                board[i][j] = ' ';
                board[r - 1][j] = tmp;
            }
        }
        
    }
    
    return answer;
}