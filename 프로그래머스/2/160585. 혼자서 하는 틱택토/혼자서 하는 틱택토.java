class Solution {
    
    // 조건 1. 어떤 시점이든 X는 O보다 클 수 없다.
    // 조건 2. O가 이긴 경우 X는 O보다 작다.
    // 조건 3. X가 이긴 경우 O는 X랑 같다.
    // 조건 4. O와 X가 동시에 이긴 경우는 존재하지 않는다.
    // 조건 5. O와 X의 차이가 2 이상 날 수 없다.
    public int solution(String[] board) {
        int O = 0, X = 0;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(board[i].charAt(j) == 'O') ++O;
                else if(board[i].charAt(j) == 'X') ++X;
            }
        }
        
        if(X > O || Math.abs(O - X) > 1) {
            return 0;
        } else {
            boolean oWin = false, xWin = false;
            
            //세로
            for(int i = 0; i < 3; ++i) {
                if(board[0].charAt(i) != '.' && board[1].charAt(i) == board[0].charAt(i) && board[2].charAt(i) == board[0].charAt(i)) {
                    if(board[0].charAt(i) == 'O') oWin = true;
                    else if(board[0].charAt(i) == 'X') xWin = true;
                }
            }
            
            // 대각선
            if(board[0].charAt(0) != '.' && board[1].charAt(1) == board[0].charAt(0) && board[2].charAt(2) == board[0].charAt(0)) {
                if(board[0].charAt(0) == 'O') oWin = true;
                else if(board[0].charAt(0) == 'X') xWin = true;
            }
            if(board[0].charAt(2) != '.' && board[1].charAt(1) == board[0].charAt(2) && board[2].charAt(0) == board[0].charAt(2)) {
                if(board[0].charAt(2) == 'O') oWin = true;
                else if(board[0].charAt(2) == 'X') xWin = true;
            }
            
            //가로
            for(int i = 0; i < 3; ++i) {
                if(board[i].charAt(0) != '.' && board[i].charAt(1) == board[i].charAt(0) && board[i].charAt(2) == board[i].charAt(0)) {
                    if(board[i].charAt(0) == 'O') oWin = true;
                    else if(board[i].charAt(0) == 'X') xWin = true;
                }
            }
            
            if(oWin && xWin) {
                return 0;
            }
            if(xWin) {
                return O == X ? 1 : 0;
            }
            if(oWin) {
                return O > X ? 1 : 0;
            }
            
            return 1;
        }
    }
}