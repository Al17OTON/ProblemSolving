import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static class Star implements Comparable<Star> {
        int x, y;
        public Star(int x, int y) {this.x = x; this.y = y;}

        public int compareTo(Star o) {
            if(this.x == o.x) return this.y - o.y;
            return this.x - o.x;
        }

        public String toString() {
            return x + " " + y;
        }
    }

    static int N, M, L, K, MAX = Integer.MAX_VALUE;
    static ArrayList<Star> star = new ArrayList<>();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for(int k = 0; k < K; k++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            star.add(new Star(x, y));
        }

        dfs(0, 0, Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MIN_VALUE, Integer.MIN_VALUE);
        System.out.println(MAX);
    }

    static void dfs(int idx, int count, int left, int up, int right, int down) {
        if(MAX <= count) return;
        if(idx == K) {
            MAX = count;
            return;
        }

        int tmp_left = Math.min(left, star.get(idx).y);
        int tmp_right = Math.max(right, star.get(idx).y);

        int tmp_up = Math.min(up, star.get(idx).x);
        int tmp_down = Math.max(down, star.get(idx).x);

        if(tmp_left == left && tmp_right == right && tmp_up == up && tmp_down == down) {
            dfs(idx + 1, count, left, up, right, down);
            return;
        }

        if(tmp_left + L < tmp_right || tmp_up + L < tmp_down) {
            dfs(idx + 1, count + 1, left, up, right, down);
            return;
        }

        dfs(idx + 1, count, tmp_left, tmp_up, tmp_right, tmp_down);
        dfs(idx + 1, count + 1, left, up, right, down);
    }

}