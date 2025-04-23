class Solution {
    // 가로, 세로
    int M, N;
    int startX, startY;
    public int[] solution(int m, int n, int startX, int startY, int[][] balls) {
        int[] result = new int[balls.length];
        M = m;
        N = n;
        this.startX = startX;
        this.startY = startY;
        for(int i = 0; i < balls.length; ++i) {
            int targetX = balls[i][0];
            int targetY = balls[i][1];
            
            int[][] targets = getRelativePos(targetX, targetY);
            
            // double a = Math.abs(targetY - startY) / Math.abs(targetX - startX); // 기울기
            // double a = getInclination(targetX, targetY, startX, startY);
            
            int min = Integer.MAX_VALUE;
            for(int j = 0; j < targets.length; ++j) {
                int X = targets[j][0];
                int Y = targets[j][1];
                // double b = getInclination(X, Y, startX, startY); // 기울기
                // if(i == 1) System.out.println(a + " " + b + " " + (a == b));
                // if(a == b && Math.min(X, startX) <= targetX && Math.max(X, startX) >= targetX && Math.min(Y, startY) <= targetY && Math.max(Y, startY) >= targetY) continue;
                // if(i == 2) System.out.println(getLen(X, Y));
                // System.out.println(X + " " + Y);
                
                if((X == startX && targetX == startX && Math.min(Y, startY) <= targetY && Math.max(Y, startY) >= targetY) || (Y == startY && targetY == startY && Math.min(X, startX) <= targetX && Math.max(X, startX) >= targetX)) continue;
                
                
                
                min = Math.min(min, getLen(X, Y));
            }
            result[i] = min;
        }
        return result;
    }
    
    double getInclination(int ax, int ay, int bx, int by) {
        int x = Math.abs(ax - bx);
        int y = Math.abs(ay - by);
        
        if(x == 0) return -1;
        if(y == 0) return 0;
        
        return y / x;
    }
    
    int getLen(int x, int y) {
        int xLen = startX - x;
        int yLen = startY - y;
        
        return xLen * xLen + yLen * yLen;
    }
    
    // 당구대 기준 8 방향에 대한 목표공 좌표 계산
    int[][] getRelativePos(int targetX, int targetY) {
        int[][] pos = new int[4][2];
        
        // 상
        // 가로 그대로, 세로는 N - Y 더하기
        pos[0][0] = targetX;
        pos[0][1] = N + N - targetY;
        
        // 우상
        // 가로 M - X 세로 N - Y 더하기
        // pos[1][0] = M + M - targetX;
        // pos[1][1] = N + N - targetY;
        
        // 우
        // 가로 M - X 세로 그대로
        pos[1][0] = M + M - targetX;
        pos[1][1] = targetY;
        
        // 우하
        // 가로 M - X 세로 -1 곱하기
        // pos[3][0] = M + M - targetX;
        // pos[3][1] = -targetY;
        
        // 하
        // 가로 그대로 세로 -1 곱하기
        pos[2][0] = targetX;
        pos[2][1] = -targetY;
        
        // 좌하
        // 가로 -1 곱하기 세로 -1 곱하기
        // pos[5][0] = -targetX;
        // pos[5][1] = -targetY;
        
        // 좌
        // 가로 -1 곱하기 세로 그대로
        pos[3][0] = -targetX;
        pos[3][1] = targetY;
        
        // 좌상
        // 가로 -1 곱하기 세로 N - Y
        // pos[7][0] = -targetX;
        // pos[7][1] = N + N - targetY;
        
        
        return pos;
    }
}