import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static class Num implements Comparable<Num> {
        int num, count;

        public Num(int num, int count) {
            this.num = num;
            this.count = count;
        }

        public int compareTo(Num o) {
            if(this.count == o.count) return this.num - o.num;
            return this.count - o.count;
        }
    }

    static int R, C, K, R_MAX = 3, C_MAX = 3;;
    static int[][] map = new int[101][101];
    static int[] count = new int[101];
    static Queue<Integer> q = new LinkedList<>();
    static PriorityQueue<Num> pq = new PriorityQueue<>();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken()) - 1;
        C = Integer.parseInt(st.nextToken()) - 1;
        K = Integer.parseInt(st.nextToken());
        
        for(int i = 0; i < 3; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < 3; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(sim());
    }

    static int sim() {
        int time = 0;

        while(time <= 100 && map[R][C] != K) {
            if(R_MAX >= C_MAX) {
                R_function();
            } else {
                C_function();
            }
            time++;
        }

        return time > 100 ? -1 : time;
    }

    static void R_function() {
        int c_max = C_MAX;
        for(int r = 0; r < R_MAX; r++) {
            for(int c = 0; c < C_MAX; c++) {
                if(map[r][c] == 0) continue;
                ++count[map[r][c]];
                if(count[map[r][c]] == 1) q.offer(map[r][c]);
                map[r][c] = 0;
            }

            while(!q.isEmpty()) {
                int num = q.poll();
                pq.offer(new Num(num, count[num]));
                count[num] = 0;
            }

            int c_len = Math.min(pq.size(), 50);
            for(int i = 0; i < c_len; i++) {
                Num n = pq.poll();
                map[r][i * 2] = n.num;
                map[r][i * 2 + 1] = n.count;
            }
            c_max = Math.max(c_max, c_len * 2);
            pq.clear();
        }

        C_MAX = c_max;
    }

    static void C_function() {
        int r_max = R_MAX;
        for(int c = 0; c < C_MAX; c++) {
            for(int r = 0; r < R_MAX; r++) {
                if(map[r][c] == 0) continue;
                ++count[map[r][c]];
                if(count[map[r][c]] == 1) q.offer(map[r][c]);
                map[r][c] = 0;
            }

            while(!q.isEmpty()) {
                int num = q.poll();
                pq.offer(new Num(num, count[num]));
                count[num] = 0;
            }

            int r_len = Math.min(pq.size(), 50);
            for(int i = 0; i < r_len; i++) {
                Num n = pq.poll();
                map[i * 2][c] = n.num;
                map[i * 2 + 1][c] = n.count;
            }
            r_max = Math.max(r_max, r_len * 2);
            pq.clear();
        }
        R_MAX = r_max;
    }
}