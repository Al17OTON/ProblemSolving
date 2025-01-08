import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static class FireBall {
        int r, c, m, s, d;

        public FireBall(int r, int c, int m, int s, int d) {
            this.r = r;
            this.c = c;
            this.m = m;
            this.s = s;
            this.d = d;
        }
    }
    static class Map {
        int m, s, d;
        int count = 1;
        boolean isSame = true;

        public Map(int m, int s, int d) {
            this.m = m;
            this.s = s;
            this.d = d;
        }
    }

    static int[] dr = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] dc = {0, 1, 1, 1, 0, -1, -1, -1};
    static int N, M, K;
    static Queue<FireBall> q = new LinkedList<>();

    // 맵 전체를 순회하는 것은  50*50*1000 = 2,500,000 이므로 2차원 배열을 사용
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken()) - 1;
            int m = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            q.add(new FireBall(r, c, m, s, d));
        }

        System.out.println(sim());
    }

    static int sim() {
        int result = 0;

        for(int k = 0; k < K; k++) {
            result = 0;
            Map[][] map = new Map[N][N];

            while(!q.isEmpty()) {
                FireBall f = q.poll();
                int nr = f.r + dr[f.d] * (f.s % N);
                int nc = f.c + dc[f.d] * (f.s % N);

                nr = nr >= 0 ? nr % N : N + nr;
                nc = nc >= 0 ? nc % N : N + nc;

                if(map[nr][nc] == null) {
                    map[nr][nc] = new Map(f.m, f.s, f.d);
                } else {
                    map[nr][nc].m += f.m;
                    map[nr][nc].s += f.s;
                    map[nr][nc].count++;
                    if(map[nr][nc].isSame && isEven(f.d) != isEven(map[nr][nc].d)) {
                        map[nr][nc].isSame = false;
                    }
                }
            }

            for(int r = 0; r < N; r++) {
                for(int c = 0; c < N; c++) {
                    if(map[r][c] != null) {
                        if(map[r][c].count == 1) {
                            q.add(new FireBall(r, c, map[r][c].m, map[r][c].s, map[r][c].d));
                            result += map[r][c].m;
                        }
                        else if(map[r][c].m / 5 > 0) {
                            int m = map[r][c].m / 5;
                            int s = map[r][c].s / map[r][c].count;
                            int d = map[r][c].isSame ? 0 : 1;
                            for(; d <= 7; d+=2) {
                                q.add(new FireBall(r, c, m, s, d));
                            }
                            result += m * 4;
                        }
                    }
                }
            }
        }

        return result;
    }

    static boolean isEven(int d) {
        return d % 2 == 0;
    }
}