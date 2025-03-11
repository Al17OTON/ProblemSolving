import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int N, M, cloudCnt = 0, total = 0;
    static int[][] map;
    static boolean[][] prev;
    static int[][] cloud;
    static int[] dr = {0, 0, -1, -1, -1, 0, 1, 1, 1};
    static int[] dc = {0, -1, -1, 0, 1, 1, 1, 0, -1};
    static Queue<int[]> q = new LinkedList<>();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][N];
        prev = new boolean[N][N];
        cloud = new int[N * N][2];

        for(int r = 0; r < N; r++) {
            st = new StringTokenizer(br.readLine());
            for(int c = 0; c < N; c++) {
                map[r][c] = Integer.parseInt(st.nextToken());
            }
        }

        cloud[0][0] = N - 1;
        cloud[0][1] = 0;
        cloud[1][0] = N - 1;
        cloud[1][1] = 1;
        cloud[2][0] = N - 2;
        cloud[2][1] = 0;
        cloud[3][0] = N - 2;
        cloud[3][1] = 1;
        cloudCnt = 4;


        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int d = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());

            for(int i = 0; i < cloudCnt; i++) {
                cloud[i][0] += (dr[d] * s) % N;
                cloud[i][1] += (dc[d] * s) % N;

                if(cloud[i][0] >= N) cloud[i][0] -= N;
                if(cloud[i][0] < 0) cloud[i][0] += N;
                if(cloud[i][1] >= N) cloud[i][1] -= N;
                if(cloud[i][1] < 0) cloud[i][1] += N;

                map[cloud[i][0]][cloud[i][1]] += 1;
                prev[cloud[i][0]][cloud[i][1]] = true;
            }
            
            for(int i = 0; i < cloudCnt; i++) {
                int count = 0;
                for(int dd = 2; dd <= 8; dd += 2) {
                    int nr = cloud[i][0] + dr[dd];
                    int nc = cloud[i][1] + dc[dd];

                    if(nr >= N || nr < 0 || nc >= N || nc < 0 || map[nr][nc] == 0) continue;
                    count++;
                }
                q.offer(new int[] {i, count});
            }

            while(!q.isEmpty()) {
                int[] p = q.poll();
                map[cloud[p[0]][0]][cloud[p[0]][1]] += p[1];
            }
            cloudCnt = 0;
            for(int r = 0; r < N; r++) {
                for(int c = 0; c < N; c++) {
                    if(!prev[r][c] && map[r][c] >= 2) {
                        cloud[cloudCnt][0] = r;
                        cloud[cloudCnt][1] = c;
                        cloudCnt++;
                        map[r][c] -= 2;
                    }
                    prev[r][c] = false;
                }
            }
            
        }

        for(int r = 0; r < N; r++) {
            for(int c = 0; c < N; c++) {
                total += map[r][c];
            }
        }

        System.out.println(total);
    }
}