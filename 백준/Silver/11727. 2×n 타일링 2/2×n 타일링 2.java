import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int N;
    static int[] dp;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        dp = new int[N + 2];

        dp[1] = 1;
        dp[2] = 3;

        System.out.println(dfs(N) % 10007);
    }

    static int dfs(int n) {
        if(dp[n] != 0) return dp[n];

        return dp[n] = (dfs(n - 1) + (2 * dfs(n - 2))) % 10007;
    }
}