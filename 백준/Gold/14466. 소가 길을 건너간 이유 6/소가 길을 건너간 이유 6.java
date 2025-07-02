import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int[][] map;
    static int N, K, R;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    static Queue<int[]> cow = new LinkedList<>();
    static List<int[]>[][] roads;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        map = new int[N][N];
        roads = new List[N][N];

        for(int r = 0; r < R; ++r) {
            st = new StringTokenizer(br.readLine());
            int r1 = Integer.parseInt(st.nextToken()) - 1;
            int c1 = Integer.parseInt(st.nextToken()) - 1;
            int r2 = Integer.parseInt(st.nextToken()) - 1;
            int c2 = Integer.parseInt(st.nextToken()) - 1;

            if(roads[r1][c1] == null) roads[r1][c1] = new ArrayList<>();
            if(roads[r2][c2] == null) roads[r2][c2] = new ArrayList<>();

            roads[r1][c1].add(new int[] {r2, c2});
            roads[r2][c2].add(new int[] {r1, c1});
        }

        for(int k = 0; k < K; ++k) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken()) - 1;

            map[r][c] = 1;
            cow.offer(new int[] {r, c});
        }

        int total = 0;
        while(!cow.isEmpty()) {
            total += K - bfs(cow.poll());
        }
        System.out.println(total / 2);
    }

    static int bfs(int[] s) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(s);
        boolean[][] v = new boolean[N][N];
        v[s[0]][s[1]] = true;
        int meet = 1;

        while(!q.isEmpty()) {
            int[] p = q.poll();

            for(int d = 0; d < 4; ++d) {
                int nr = p[0] + dr[d];
                int nc = p[1] + dc[d];

                if(nr >= N || nr < 0 || nc >= N || nc < 0 || v[nr][nc] || checkRoad(nr, nc, p[0], p[1])) continue;

                v[nr][nc] = true;
                if(map[nr][nc] == 1) ++meet;
                q.offer(new int[] {nr, nc});
            }
        }

        return meet;
    }

    static boolean checkRoad(int r1, int c1, int r2, int c2) {
        if(roads[r1][c1] == null) return false;
        for(int[] road : roads[r1][c1]) {
            if(r2 == road[0] && c2 == road[1]) return true;
        }
        return false;
    }
}