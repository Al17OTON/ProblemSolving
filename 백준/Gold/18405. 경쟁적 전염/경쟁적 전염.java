import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static class Virus implements Comparable<Virus> {
        int r, c, no;

        public Virus(int r, int c, int no) {
            this.r = r;
            this.c = c;
            this.no = no;
        }

        @Override
        public int compareTo(Virus o) {
            return Integer.compare(this.no, o.no);
        }

    }
    
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    static int N, K, S, X, Y;
    static PriorityQueue<Virus> pq = new PriorityQueue<>();
    static int[][] map;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        map = new int[N][N];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] != 0) pq.offer(new Virus(i, j, map[i][j]));
            }
        }
        st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());
        Y = Integer.parseInt(st.nextToken());

        simulation();

        System.out.println(map[X- 1][Y - 1]);
    }

    static void simulation() {
        for(int t = 0; t < S; t++) {
            PriorityQueue<Virus> tmp = new PriorityQueue<>();

            while(!pq.isEmpty()) {
                Virus v = pq.poll();

                for(int d = 0; d < 4; d++) {
                    int nr = v.r + dr[d];
                    int nc = v.c + dc[d];

                    if(nr >= N || nr < 0 || nc >= N || nc < 0 || map[nr][nc] != 0) continue;
                    map[nr][nc] = v.no;
                    tmp.offer(new Virus(nr, nc, v.no));
                }
            }
            pq = tmp;
        }
    }
}