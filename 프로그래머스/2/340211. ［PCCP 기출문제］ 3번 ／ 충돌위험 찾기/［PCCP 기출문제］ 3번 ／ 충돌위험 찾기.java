//시뮬레이션
//장애물이 없으므로 그냥 최단 경로를 그릴 수 있다

class Solution {
    int danger = 0;
    int[] dr = {-1, 1};
    int[][] points, routes;
    
    // 각 시간마다 해당 좌표에 몇 대의 로봇이 있었는지 체크를 위한 배열
    // 맵의 크기가 100x100이므로 가장 긴 경로는 200
    // 200 * 로봇의 갯수 = 대략 필요한 최대 시간
    int[][][] map = new int[101][101][20000];
    
    public int solution(int[][] points, int[][] routes) {  
        this.points = points;
        this.routes = routes;
        
        // 모든 로봇을 최단 경로로 이동 시킨다.
        for(int i = 0; i < routes.length; i++) {
            makeRoute(i);
        }
        
        return danger;
    }
    
    // 맵에 장애물이 없으므로 bfs를 사용하지 않고 r 좌표 우선 최단 경로를 그린다.
    void makeRoute(int idx) {
        //초기값
        int time = 0;
        int r = points[routes[idx][0] - 1][0] - 1;
        int c = points[routes[idx][0] - 1][1] - 1;
        
        int target_r, target_c;
        
        for(int i = 1; i < routes[idx].length; i++) {
            // 방문 포인트
            target_r = points[routes[idx][i] - 1][0] - 1;
            target_c = points[routes[idx][i] - 1][1] - 1;
            
            // 벡터를 구해준다.
            int vec = target_r - r < 0 ? 0 : 1;
            int nr = r;
            for(nr = r; nr != target_r; nr += dr[vec]) {
                // 해당 좌표에 두 번째로 방문한 경우 위험 상황 증가
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
        // 가장 마지막 좌표는 위 반복문에서 방문처리를 안하므로 수동 방문처리
        if(map[r][c][time] == 1) danger++;
        map[r][c][time++]++;
    }
}