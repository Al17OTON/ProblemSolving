import java.util.*;
import java.io.*;

public class Main {

    static int N, L, R;
    static int[][] map;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        map = new int[N][N];

        for(int r = 0; r < N; r++) {
            st = new StringTokenizer(br.readLine());
            for(int c = 0; c < N; c++) {
                map[r][c] = Integer.parseInt(st.nextToken());
            }
        }

        int day = 0;
        while(true) {
            boolean flag = false;
            boolean[][] v = new boolean[N][N];
            for(int r = 0; r < N; r++) {
                for(int c = 0; c < N; c++) {
                    if(!v[r][c]) flag |= floodFill(r, c, v);
                }
            }

            if(!flag) break;
            day++;
        }

        System.out.println(day);
    }

    static boolean floodFill(int r, int c, boolean[][] v) {
        int sum = map[r][c];
        v[r][c] = true;
        Queue<int[]> q = new LinkedList(), unite = new LinkedList<>();
        q.offer(new int[] {r, c});
        unite.offer(new int[] {r, c});
        
        while(!q.isEmpty()) {
            int[] p = q.poll();

            for(int d = 0; d < 4; d++) {
                int nr = p[0] + dr[d];
                int nc = p[1] + dc[d];

                if(nr >= N || nr < 0 || nc >= N || nc < 0 || v[nr][nc]) continue;
                int sub = Math.abs(map[p[0]][p[1]] - map[nr][nc]);
                if(sub >= L && sub <= R) {
                    sum += map[nr][nc];
                    v[nr][nc] = true;
                    int[] next = new int[] {nr, nc};
                    q.offer(next);
                    unite.offer(next);
                }
            }
        }
        
        if(unite.size() == 1) return false;

        int pop = sum / unite.size();
        while(!unite.isEmpty()) {
            int[] p = unite.poll();
            map[p[0]][p[1]] = pop;
        }
        return true;
    }
}