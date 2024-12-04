import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    
    static class Hero {
        int r, c;
        int isGram;
        public Hero(int r, int c, int isGram) {
            this.r = r;
            this.c = c;
            this.isGram = isGram;
        }

    }

    static int[] dr = {-1, 1, 0, 0};    //상하좌우
    static int[] dc = {0, 0, -1, 1};
    static int N, M, T;
    static int[][] map;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        map = new int[N][M];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int res = bfs();

        System.out.println(res == -1 ? "Fail" : res);

    }

    static int bfs() {
        boolean[][][] v = new boolean[2][N][M];
        ArrayDeque<Hero> q = new ArrayDeque<>();
        v[0][0][0] = true;
        q.offer(new Hero(0,0,0));
        int time = 0;
        while(!q.isEmpty() && time <= T) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                Hero h = q.poll();

                if(h.r == N - 1 && h.c == M - 1) return time;
                
                for(int d = 0; d < 4; d++) {
                    int nr = h.r + dr[d];
                    int nc = h.c + dc[d];

                    if(nr < 0 || nr >= N || nc < 0 || nc >= M || v[h.isGram][nr][nc]) continue;
                    if(h.isGram == 0 && map[nr][nc] == 1) continue;
                    
                    v[h.isGram][nr][nc] = true;
                    if(map[nr][nc] == 2) {
                        v[1][nr][nc] = true;
                        q.offer(new Hero(nr, nc, 1));
                    }
                    else q.offer(new Hero(nr, nc, h.isGram));
                }

            }
            time++;
        }

        return -1;
    }
}