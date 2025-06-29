import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    
    static int N;
    static boolean[] dp;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        dp = new boolean[N + 3];

        //true == SK
        dp[1] = true;
        dp[2] = false;
        dp[3] = true;

        for(int i = 4; i <= N; ++i) {
            dp[i] = !dp[i - 1] || !dp[i - 3];
        }
        
        System.out.println(dp[N] ? "SK" : "CY");
    }
}