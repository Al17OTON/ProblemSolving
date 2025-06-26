import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    
    static int[][] dp;
    static int N, M;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        dp = new int[N + 1][M + 1];

        for(int r = 1; r <= N; ++r) {
            st = new StringTokenizer(br.readLine());
            for(int c = 1; c <= M; ++c) {
                int candy = Integer.parseInt(st.nextToken());
                dp[r][c] = candy + Math.max(Math.max(dp[r - 1][c], dp[r][c - 1]), dp[r - 1][c - 1]);
            }
        }

        System.out.println(dp[N][M]);
    }
}