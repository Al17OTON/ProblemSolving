import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int N, K;
    static int[][] adj;
    static int[][] dp;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        adj = new int[N][N];
        dp = new int[N][N];
        for(int r = 0; r < N; ++r) {
            st = new StringTokenizer(br.readLine());
            for(int c = 0; c < N; ++c) {
                adj[r][c] = Integer.parseInt(st.nextToken());
                dp[r][c] = adj[r][c];
            }
        }

        for(int m = 0; m < N; ++m) {
            for(int s = 0; s < N; ++s) {
                for(int e = 0; e < N; ++e) {
                    dp[s][e] = Math.min(dp[s][e], dp[s][m] + dp[m][e]);
                }
            }
        }

        boolean[] v = new boolean[N];
        v[K] = true;
        System.out.println(dfs(K, 0, v, 1));
    }


    static int dfs(int k, int time, boolean[] v, int count) {
        if(count == N) return time;

        int min = Integer.MAX_VALUE;
        for(int i = 0; i < N; ++i) {
            if(i == k || v[i]) continue;
            v[i] = true;
            min = Math.min(min, dfs(i, time + dp[k][i], v, count + 1));
            v[i] = false;
        }
        return min;
    }

}