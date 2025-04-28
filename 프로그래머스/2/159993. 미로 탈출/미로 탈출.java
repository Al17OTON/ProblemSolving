import java.util.*;
class Solution {
    class Pos {
        int r, c;
        boolean isOpen;
        public Pos(int r, int c, boolean flag) {this.r = r; this.c = c; isOpen = flag;}
        public boolean isSame(Pos o) {
            return this.r == o.r && this.c == o.c;
        }
    }
    
    boolean[][] map;
    int R, C;
    Pos exit, start, lever;
    int[] dr = {-1, 1, 0, 0};
    int[] dc = {0, 0, -1, 1};
    
    public int solution(String[] maps) {
        map = new boolean[maps.length][maps[0].length()];
        R = maps.length;
        C = maps[0].length();
        
        for(int i = 0; i < maps.length; ++i) {
            for(int j = 0; j < maps[0].length(); ++j) {
                if(maps[i].charAt(j) == 'O') map[i][j] = true;
                else if(maps[i].charAt(j) == 'S') {
                    start = new Pos(i, j, false);
                    map[i][j] = true;
                } else if(maps[i].charAt(j) == 'E') {
                    exit = new Pos(i, j, false);
                    map[i][j] = true;
                } else if(maps[i].charAt(j) == 'L') {
                    lever = new Pos(i, j, false);
                    map[i][j] = true;
                }
            }
        }
        
        return bfs();
    }
    
    int bfs() {
        int time = 0;
        Queue<Pos> q = new LinkedList();
        boolean[][][] v = new boolean[R][C][2];
        q.offer(start);
        v[start.r][start.c][0] = true;
        
        while(!q.isEmpty()) {
            int size = q.size();
            for(int s = 0; s < size; ++s) {
                Pos p = q.poll();
                
                if(p.isOpen && p.isSame(exit)) return time;
                
                for(int d = 0; d < 4; ++d) {
                    int nr = p.r + dr[d];
                    int nc = p.c + dc[d];
                    
                    if(nr >= R || nr < 0 || nc >= C || nc < 0 || !map[nr][nc] || v[nr][nc][p.isOpen ? 1 : 0]) continue;
                    
                    v[nr][nc][p.isOpen ? 1 : 0] = true;
                    Pos np = new Pos(nr, nc, p.isOpen);
                    if(!np.isOpen && np.isSame(lever)) np.isOpen = true;  
                    
                    q.offer(np);
                }
                
            }
            
            ++time;
        }
        
        return -1;
    }
}












