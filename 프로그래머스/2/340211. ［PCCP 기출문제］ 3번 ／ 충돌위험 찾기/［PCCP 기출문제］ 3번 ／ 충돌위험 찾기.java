import java.util.*;

//시뮬레이션 bfs
//장애물이 없으므로 그냥 최단 경로를 그릴 수 있다

class Robot {
    int r, c;
    boolean isDone;
    public Robot(int r, int c) {
        this.r = r;
        this.c = c;
        isDone = false;
    }
}

class Solution {
    int danger = 0;
    int[] dr = {-1, 1};
    int[][] points, routes;
    int[][][] map = new int[101][101][20000];
    
    public int solution(int[][] points, int[][] routes) {  
        this.points = points;
        this.routes = routes;
        
        
        // for(int i = 0; i < routes.length; i++) {
        //     int idx = routes[i][0] - 1;
        //     robots.add(new Robot(points[idx][0], points[idx][1]));
        //     // map[points[idx][0]][points[idx][1]]++;
        // }
        
        for(int i = 0; i < routes.length; i++) {
            makeRoute(i);
        }
        
        return danger;
    }
    
    
    void makeRoute(int idx) {
        int time = 0;
        int r = points[routes[idx][0] - 1][0] - 1;
        int c = points[routes[idx][0] - 1][1] - 1;
        
        int target_r, target_c;
        
        for(int i = 1; i < routes[idx].length; i++) {
            target_r = points[routes[idx][i] - 1][0] - 1;
            target_c = points[routes[idx][i] - 1][1] - 1;
            
            int vec = target_r - r < 0 ? 0 : 1;
            int nr = r;
            for(nr = r; nr != target_r; nr += dr[vec]) {
                if(map[nr][c][time] == 1) danger++;
                map[nr][c][time++]++;
            }
            r = nr;

            vec = target_c - c < 0 ? 0 : 1;
            int nc = c;
            for(nc = c; nc != target_c; nc += dr[vec]) {
                if(map[r][nc][time] == 1) danger++;
                map[r][nc][time++]++;
            }
            c = nc;
        }
        if(map[r][c][time] == 1) danger++;
        map[r][c][time++]++;
    }
}