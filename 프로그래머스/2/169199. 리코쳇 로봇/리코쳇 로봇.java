import java.util.*;

class Solution {
    class Robot {
        int r, c;
        public Robot(int r, int c) {this.r = r; this.c = c;}
        public boolean isEqual(Robot o) {
            return o.r == this.r && o.c == this.c;
        }
    }
    int N, M;
    char[][] map;
    int[] dr = {-1, 1, 0, 0};
    int[] dc = {0, 0, -1 ,1};
    Robot start, goal;
    public int solution(String[] board) {
        N = board.length;
        M = board[0].length();
        map = new char[N][];
        for(int i = 0; i < N; ++i) {
            map[i] = board[i].toCharArray();
            for(int j = 0; j < M; ++j) {
                if(map[i][j] == 'R') {
                    start = new Robot(i, j);
                    map[i][j] = '.';
                } else if(map[i][j] == 'G') {
                    goal = new Robot(i, j);
                    map[i][j] = '.';
                }
                
            }
        }
        
        
        return bfs();
    }
    
    int bfs() {
        Queue<Robot> q = new LinkedList();
        boolean[][] v = new boolean[N][M];
        q.offer(start);
        v[start.r][start.c] = true;
        
        int turn = 0;
        while(!q.isEmpty()) {
            int size = q.size();
            for(int s = 0; s < size; ++s) {
                Robot robot = q.poll();
                
                if(robot.isEqual(goal)) {
                    return turn;
                }
                
                for(int d = 0; d < 4; ++d) {
                    Robot nRobot = move(robot, d);
                    if(!v[nRobot.r][nRobot.c]) {
                        v[nRobot.r][nRobot.c] = true;
                        q.offer(nRobot);
                    }
                }
            }
            ++turn;
        }
        return -1;
    }
    
    // 주어진 로봇의 위치와 방향을 사용해 로봇을 움직인다.
    Robot move(Robot o, int dir) {
        int r = o.r;
        int c = o.c;
        int nr = o.r + dr[dir];
        int nc = o.c + dc[dir];
        
        while(nr >= 0 && nr < N && nc >= 0 && nc < M && map[nr][nc] == '.') {
            r = nr;
            c = nc;
            nr += dr[dir];
            nc += dc[dir];
        }
        
        return new Robot(r, c); 
    }
    
}