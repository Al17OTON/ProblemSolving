// floodFill
import java.util.*;

class Solution {
    boolean[][] v;
    int[] dp;
    int[] dr = {-1, 1, 0, 0};
    int[] dc = {0, 0, -1, 1};
    
    public int solution(int[][] land) {
        int answer = 0;
        v = new boolean[land.length][land[0].length];
        
        dp = new int[land[0].length];
        
        for(int r = 0; r < land.length; r++) {
            for(int c = 0; c < land[0].length; c++) {
                if(land[r][c] == 1 && !v[r][c]) floodFill(land, r, c);
            }
        }
        
        for(int i = 0; i < dp.length; i++) answer = Math.max(answer, dp[i]);
        
        return answer;
    }
    
    void floodFill(int[][] map, int r, int c) {
        boolean[] col = new boolean[map[0].length];
        Queue<Integer> colQ = new LinkedList();
        
        int result = 1;
        Queue<int[]> q = new LinkedList();
        v[r][c] = true;
        q.offer(new int[]{r,c});
        col[c] = true;
        colQ.offer(c);
        
        while(!q.isEmpty()) {
            int[] p = q.poll();
            
            for(int d = 0; d < 4; d++) {
                int nr = p[0] + dr[d];
                int nc = p[1] + dc[d];
                
                if(nr >= v.length || nr < 0 || nc >= v[0].length || nc < 0 || v[nr][nc] || map[nr][nc] == 0) continue;
                
                v[nr][nc] = true;
                q.offer(new int[]{nr,nc});
                result++;
                if(!col[nc]) {
                    col[nc] = true;
                    colQ.offer(nc);
                }
            }
        }
        
        while(!colQ.isEmpty()) {
            int nc = colQ.poll();
            dp[nc] += result;
        }
    }
}