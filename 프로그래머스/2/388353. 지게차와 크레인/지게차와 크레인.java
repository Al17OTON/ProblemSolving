import java.util.*;

class Solution {
    
    int cargoCnt;
    char[][] map;
    int[] dr = {-1, 1, 0, 0};
    int[] dc = {0, 0, -1, 1};
    
    public int solution(String[] storage, String[] requests) {
        cargoCnt = storage.length * storage[0].length();
        map = new char[storage.length + 2][storage[0].length() + 2];
        
        for(int r = 0; r < storage.length; r++) {
            for(int c = 0; c < storage[0].length(); c++) {
                map[r + 1][c + 1] = storage[r].charAt(c);
            }
        }
        
        for(String req : requests) {
            if(req.length() == 1) {
                lift(req.charAt(0));
            } else {
                crane(req.charAt(0));
            }
        }
        
        return cargoCnt;
    }
    
    void print() {
        for(int r = 0; r < map.length; r++) {
            for(int c = 0; c < map[0].length; c++) {
                System.out.print(map[r][c] + " ");
            }
            
            System.out.println();
        }
        System.out.println();
    }
    
    void crane(char cargo) {
        for(int r = 1; r < map.length - 1; r++) {
            for(int c = 1; c < map[0].length - 1; c++) {
                if(map[r][c] == cargo) {
                    map[r][c] = map[0][0];
                    cargoCnt--;
                }
            }
        }
    }
    
    void lift(char cargo) {
        Queue<int[]> q = new LinkedList(), tmp = new LinkedList();
        boolean[][] v = new boolean[map.length][map[0].length];
        
        q.offer(new int[] {0, 0});
        v[0][0] = true;
        
        while(!q.isEmpty()) {
            int[] p = q.poll();
            
            for(int d = 0; d < 4; d++) {
                int nr = p[0] + dr[d];
                int nc = p[1] + dc[d];
                
                if(nr >= map.length || nr < 0 || nc >= map[0].length || nc < 0 || v[nr][nc]) continue;
                v[nr][nc] = true;
                if(map[nr][nc] != map[0][0]) {
                    if(map[nr][nc] == cargo) {
                        tmp.offer(new int[] {nr, nc});
                    }
                    continue;
                }
                q.offer(new int[] {nr, nc});
                
            }
        }
        
        cargoCnt -= tmp.size();
        
        while(!tmp.isEmpty()) {
            int[] p = tmp.poll();
            map[p[0]][p[1]] = map[0][0];
        }
        
    }
}