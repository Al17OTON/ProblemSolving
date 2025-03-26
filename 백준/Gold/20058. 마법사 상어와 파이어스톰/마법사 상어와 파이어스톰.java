import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, Q, SIZE;
    static int[][] map;
    static int[][] copy; 
    static Queue<int[]> q = new LinkedList<>();
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
        SIZE = (int)Math.pow(2, N);
        map = new int[SIZE][SIZE];
        copy = new int[SIZE][SIZE];
        for(int r = 0; r < SIZE; ++r) {
            st = new StringTokenizer(br.readLine());
            for(int c = 0; c < SIZE; ++c) {
                map[r][c] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        for(int q = 0; q < Q; ++q) {
            int L = Integer.parseInt(st.nextToken());
            fireStorm(L);
        }

        boolean[][] v = new boolean[SIZE][SIZE];
        int sum = 0, max = 0;
        for(int r = 0; r < SIZE; ++r) {
            for(int c = 0; c < SIZE; ++c) {
                sum += map[r][c];
                if(!v[r][c] && map[r][c] > 0) {
                    max = Math.max(floodFill(r, c, v), max);
                }
            }
        }

        System.out.println(sum + "\n" + max);
    }

    static int floodFill(int r, int c, boolean[][] v) {
        int result = 1;
        Queue<int[]> ice = new LinkedList<>();
        ice.offer(new int[] {r, c});
        v[r][c] = true;
        while(!ice.isEmpty()) {
            int[] p = ice.poll();

            for(int d = 0; d < 4; ++d) {
                int nr = p[0] + dr[d];
                int nc = p[1] + dc[d];

                if(nr >= SIZE || nr < 0 || nc >= SIZE || nc < 0 || v[nr][nc] || map[nr][nc] < 1) continue;
                v[nr][nc] = true;
                ++result;
                ice.offer(new int[] {nr, nc});
            }
        }

        return result;
    }

    static void fireStorm(int L) {
        int size = (int)Math.pow(2, L);
        for(int r = 0; r < SIZE; r += size) {
            for(int c = 0; c < SIZE; c += size) {
                rotate(r, c, size);
            }
        }
    
        for(int r = 0; r < SIZE; ++r) {
            for(int c = 0; c < SIZE; ++c) {
                if(map[r][c] == 0) continue;

                int count = 0;
                for(int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if(nr >= SIZE || nr < 0 || nc >= SIZE || nc < 0) continue;
                    if(map[nr][nc] > 0) ++count;
                }
                if(count < 3) q.offer(new int[] {r, c});
            }
        }

        while(!q.isEmpty()) {
            int[] p = q.poll();
            --map[p[0]][p[1]];
        }
        
    }

    static void printMap(int l) {
        System.out.println("\nl = " + l);
        for(int r = 0; r < SIZE; ++r) System.out.println(Arrays.toString(map[r]));
    }

    static void rotate(int start_r, int start_c, int l) {
        for(int i = 0; i < l / 2; ++i) {
            int r = start_r + i;
            int c = start_c + i;
            int len = l - (2 * i) - 1;
            for(int j = 0; j < len; ++j) {
                swap(r, c + j, r + j, c + len);
            }

            r += 1;
            for(int j = 0; j < len; ++j) {
                swap(r + j, c, r - 1, c + (len - 1) - j);
            }

            r += len - 1;
            c += 1;
            for(int j = 0; j < len; ++j) {
                swap(r, c + j, r - len + 1 + j, c - 1);
            }
        }
    }

    static void swap(int r1, int c1, int r2, int c2) {
        int tmp = map[r1][c1];
        map[r1][c1] = map[r2][c2];
        map[r2][c2] = tmp;
    }
}