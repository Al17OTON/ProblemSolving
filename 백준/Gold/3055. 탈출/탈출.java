import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    
    static class Pos {
        int r, c;

        public Pos(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
    static class Hedgehog extends Pos {
        int len;

        public Hedgehog(int r, int c, int len) {
            super(r, c);
            this.len = len;
        }
    }
    /*
1 4
S.D*
     */

    static int R, C;
    static char[][] map;
    static Queue<Hedgehog> water = new LinkedList<>();
    static Hedgehog sonic;
    static int[][] watermap;
    
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        map = new char[R][];
        watermap = new int[R][C];

        for(int r = 0; r < R; r++) {
            map[r] = br.readLine().toCharArray();
            for(int c = 0; c < C; c++) {
                if(map[r][c] == '*') {
                    watermap[r][c] = 1;
                    water.offer(new Hedgehog(r, c, 1));
                } else if(map[r][c] == 'S') {
                    map[r][c] = '.';
                    sonic = new Hedgehog(r, c, 0);
                } else if(map[r][c] == 'D') {
                    watermap[r][c] = Integer.MAX_VALUE;
                }
            }
        }

        simWater();
        int res = bfs();
        System.out.println(res == -1 ? "KAKTUS" : res);
    }

    static int bfs() {
        boolean[][] v = new boolean[R][C];
        Queue<Hedgehog> son = new LinkedList<>();
        son.offer(sonic);
        v[sonic.r][sonic.c] = true;

        while(!son.isEmpty()) {
            Hedgehog s = son.poll();

            if(map[s.r][s.c] == 'D') return s.len;

            for(int i = 0; i < dr.length; i++) {
                int nr = s.r + dr[i];
                int nc = s.c + dc[i];

                if(nr >= R || nr < 0 || nc >= C || nc < 0 || v[nr][nc] || map[nr][nc] == 'X' || (watermap[nr][nc] != 0 && watermap[nr][nc] <= s.len + 2)) continue;
                v[nr][nc] = true;

                son.offer(new Hedgehog(nr, nc, s.len + 1));
            }

        }

        return -1;
    }


    static void simWater() {
        while(!water.isEmpty()) {
            Hedgehog w = water.poll();

            for(int i = 0; i < dr.length; i++) {
                int nr = w.r + dr[i];
                int nc = w.c + dc[i];

                if(nr >= R || nr < 0 || nc >= C || nc < 0 || map[nr][nc] != '.' || (watermap[nr][nc] != 0 && watermap[nr][nc] <= w.len + 1)) continue;

                watermap[nr][nc] = w.len + 1;
                water.offer(new Hedgehog(nr, nc, w.len + 1));
            }
        }
    }
}