import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {

    static class Bomb {
        int r, c;

        public Bomb(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static int R, C, N;
    static char[][] map;
    static ArrayDeque<Bomb> bombs = new ArrayDeque<>();
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        map = new char[R][];

        for(int r = 0; r < R; r++) {
            map[r] = br.readLine().toCharArray();
            for(int c = 0; c < C; c++) {
                if(map[r][c] == 'O') bombs.offer(new Bomb(r, c));
            }
        }

        if(N == 1) {
            for(int r = 0; r < R; r++) {
                for(int c = 0; c < C; c++) {
                    sb.append(map[r][c]);
                }
                sb.append("\n");
            }
            System.out.println(sb);
            return;
        }

        boolean[][] boom = new boolean[R][C];

        for(int n = 1; n < N; n++) {
            boom = new boolean[R][C];

            n++;
            if(n == N) {
                
                for(int r = 0; r < R; r++) {
                    for(int c = 0; c < C; c++) {
                        sb.append("O");
                    }
                    sb.append("\n");
                }
                System.out.println(sb);
                return;
            }
            while(!bombs.isEmpty()) {
                Bomb b = bombs.poll();
                boom[b.r][b.c] = true;
                for(int i = 0; i < 4; i++) {
                    int nr = b.r + dr[i];
                    int nc = b.c + dc[i];

                    if(nr >= R || nr < 0 || nc >= C || nc < 0) continue;
                    boom[nr][nc] = true;
                }
            }

            for(int r = 0; r < R; r++) {
                for(int c = 0; c < C; c++) {
                    if(!boom[r][c]) bombs.offer(new Bomb(r, c));
                }
            }

        }

        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                sb.append(boom[r][c] ? "." : "O");
            }
            sb.append("\n");
        }
        System.out.println(sb);


    }
}