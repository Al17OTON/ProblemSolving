import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int N;
    static long[] dp;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        dp = new long[N + 2];
        
        dp[1] = 1;
        dp[2] = 1;

        System.out.println(dfs(N));
    }

    static long dfs(int n) {
        if(dp[n] != 0) return dp[n];

        return dp[n] = dfs(n - 1) + dfs(n - 2);
    }
}