import java.util.*;

class Solution {
    int N, M;
    char[][] map;
    boolean[][] v;
    int[] dr = {-1, 1, 0, 0};
    int[] dc = {0, 0, -1, 1};
    public int[] solution(String[] maps) {
        N = maps.length;
        M = maps[0].length();
        map = new char[N][];
        v = new boolean[N][M];
        
        for(int r = 0; r < N; ++r) {
            map[r] = maps[r].toCharArray();
        }
        
        return findIsland();
    }
    
    int[] findIsland() {
        PriorityQueue<Integer> pq = new PriorityQueue();
        
        for(int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                if(map[r][c] != 'X' && !v[r][c]) {
                    pq.offer(floodFill(r, c));
                }
            }
        }
        
        if(pq.size() == 0) return new int[] {-1};
        
        int[] res = new int[pq.size()];
        int i = 0;
        while(!pq.isEmpty()) {
            res[i++] = pq.poll();
        }
        return res;
    }
    
    int floodFill(int startR, int startC) {
        int food = map[startR][startC] - '0';
        Queue<int[]> q = new LinkedList();
        q.offer(new int[] {startR, startC});
        v[startR][startC] = true;
        
        while(!q.isEmpty()) {
            int[] p = q.poll();
            
            for(int d = 0; d < 4; ++d) {
                int nr = p[0] + dr[d];
                int nc = p[1] + dc[d];
                
                if(nr >= N || nr < 0 || nc >= M || nc < 0 || map[nr][nc] == 'X' || v[nr][nc]) continue;
                v[nr][nc] = true;
                food += map[nr][nc] - '0';
                q.offer(new int[] {nr, nc});
            }
        }
        
        return food;
    }
}





