import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    
    static int N, M, W_POWER = 0, B_POWER = 0;
    static char[][] map;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new char[M][];

        for(int m = 0; m < M; m++) {
            map[m] = br.readLine().toCharArray();
        }

        floodFill();

        System.out.println(W_POWER + " " + B_POWER);
    }

    static void floodFill() {
        boolean[][] v = new boolean[M][N];
        
        for(int r = 0; r < M; r++) {
            for(int c = 0; c < N; c++) {
                if(v[r][c]) continue;
                int count = 1;
                v[r][c] = true;
                Queue<int[]> q = new LinkedList<>();
                q.offer(new int[] {r, c});

                while(!q.isEmpty()) {
                    int[] p = q.poll();

                    for(int d = 0; d < 4; d++) {
                        int nr = p[0] + dr[d];
                        int nc = p[1] + dc[d];

                        if(nr >= M || nr < 0 || nc >= N || nc < 0 || v[nr][nc] || map[nr][nc] != map[r][c]) continue;

                        v[nr][nc] = true;
                        q.offer(new int[] {nr, nc});
                        count++;
                    }
                }

                if(map[r][c] == 'W') W_POWER += count * count;
                else B_POWER += count * count;
            }
        }
    }
}