import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int N;
    static int[] dp;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
        N = Integer.parseInt(br.readLine());
        dp = new int[N + 1];
        dp[1] = 1;

        int num = 2;
        for(int i = 2; i <= N; ++i) {
            if(num * num == i) {
                dp[i] = 1;
                ++num;
                continue;
            }
            dp[i] = dp[i - 1] + dp[1];
            for(int j = i - 1; j > i / 2; --j) {
                dp[i] = Math.min(dp[i], dp[j] + dp[i - j]);
            }
        }

        System.out.println(dp[N]);
    }
}