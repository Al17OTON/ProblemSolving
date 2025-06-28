import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    
    static int N;
    static long[][] dp;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
        N = Integer.parseInt(br.readLine());

        dp = new long[10][N + 2];

        for(int i = 1; i <= N + 1; ++i) {
            for(int j = 0; j < 10; ++j) {
                if(j == 0) {
                    dp[j][i] = 1;
                    continue;
                }
                dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
                dp[j][i] %= 10007;
            }
        }

        System.out.println(dp[9][N + 1]);
    }
}