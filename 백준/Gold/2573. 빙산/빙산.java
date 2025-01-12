import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    // static class Union {
    //     int[][] uni;
    //     int N, M;

    //     public Union(int N, int M) {
    //         this.N = N;
    //         this.M = M;
    //         uni = new int[N][M];
    //         for(int n = 0; n < N; n++) {
    //             for(int m = 0; m < M; m++) {
    //                 uni[n][m] = pos2Idx(n, m);
    //             }
    //         }
    //     }

    //     int find(int n, int m) {
    //         if(uni[n][m] == pos2Idx(n, m)) return uni[n][m];
    //         return uni[n][m] = find(uni[n][m] / N, uni[n][m] % N);
    //     }

    //     void setUnion(int an, int am, int bn, int bm) {
    //         int a = find(an, am);
    //         int b = find(bn, bm);

    //         if(a == b) return;

    //         uni[an][am] = b;
    //     }

    //     int pos2Idx(int n, int m) {
    //         return n * N + m;
    //     }
    // }

    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    static int N, M;
    static int[][] map;
    static Queue<int[]> q = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N][M];

        for(int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            for(int m = 0; m < M; m++) {
                map[n][m] = Integer.parseInt(st.nextToken());
                if(map[n][m] != 0) q.offer(new int[] {n, m});
            }
        }
        int year = 0;
        while(true) {
            int iceberg = getIceberg();
            if(iceberg == 0) {
                year = 0;
                break;
            } else if(iceberg > 1) break;
            nextYear();
            year++;
        }

        System.out.println(year);
    }

    static void nextYear() {
        Queue<int[]> cost = new LinkedList<>();
        while(!q.isEmpty()) {
            int[] p = q.poll();
            int surround = 0;
            for(int i = 0; i < 4; i++) {
                int nn = p[0] + dr[i];
                int nm = p[1] + dc[i];

                if(map[nn][nm] == 0) surround++;
            }

            cost.offer(new int[] {p[0], p[1], surround});
        }

        while(!cost.isEmpty()) {
            int[] c = cost.poll();
            map[c[0]][c[1]] = Math.max(0, map[c[0]][c[1]] - c[2]);

            if(map[c[0]][c[1]] > 0) q.offer(new int[] {c[0], c[1]});
        }
    }

    static int getIceberg() {
        if(q.isEmpty()) return 0;
        boolean[][] v = new boolean[N][M];
        int count = 0;

        for(int size = q.size(); size > 0; size--) {
            int[] p = q.poll();
            q.offer(p);

            if(v[p[0]][p[1]]) continue;
            v[p[0]][p[1]] = true;
            count++;
            if(count > 1) break;

            floodFill(p[0], p[1], v);
        }

        return count;
    }

    static void floodFill(int n, int m, boolean[][] v) {
        for(int i = 0; i < 4; i++) {
            int nn = n + dr[i];
            int nm = m + dc[i];

            if(v[nn][nm] || map[nn][nm] == 0) continue;
            v[nn][nm] = true;
            floodFill(nn, nm, v);
        }
    }
}