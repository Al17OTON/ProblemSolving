import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static class Cheese {
        int r, c;
        public Cheese(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static int R, C;
    static boolean[][] map;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        R = Integer.parseInt(st.nextToken());   
        C = Integer.parseInt(st.nextToken());
        
        map = new boolean[R][C];

        for(int r = 0; r < R; r++) {
            st = new StringTokenizer(br.readLine());
            for(int c = 0; c < C; c++) {
                if(st.nextToken().charAt(0) == '1') {
                    map[r][c] = true;
                }
            }
        }

        int time = 0; 
        while(true) {
            Queue<Cheese> r = floodFill();
            if(r.isEmpty()) break;

            while(!r.isEmpty()) {
                Cheese c = r.poll();
                map[c.r][c.c] = false;
            }
            time++;
        }

        System.out.println(time);
        
    }

    static Queue<Cheese> floodFill() {
        Queue<Cheese> q = new ArrayDeque<>(), remove = new ArrayDeque<>();
        int[][] count = new int[R][C];
        q.offer(new Cheese(0, 0));
        count[0][0] = -1;

        while(!q.isEmpty()) {
            Cheese c = q.poll();

            for(int i = 0; i < dr.length; i++) {
                int nr = c.r + dr[i];
                int nc = c.c + dc[i];

                if(nr >= R || nr < 0 || nc >= C || nc < 0 || count[nr][nc] == -1) continue;

                if(map[nr][nc]) {
                    count[nr][nc]++;
                    if(count[nr][nc] == 2) remove.offer(new Cheese(nr, nc));
                } else {
                    count[nr][nc] = -1;
                    q.offer(new Cheese(nr, nc));
                }
            }
        }

        return remove;
    }
}