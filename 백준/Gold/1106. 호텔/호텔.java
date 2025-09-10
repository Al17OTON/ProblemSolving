import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    
    static int C, N;
    static int[] dp;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        C = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        dp = new int[C + 1];

        for(int i = 0; i <= C; ++i) dp[i] = 987654321;

        for(int n = 0; n < N; ++n) {
            int cost, customer;
            st = new StringTokenizer(br.readLine());
            cost = Integer.parseInt(st.nextToken());
            customer = Integer.parseInt(st.nextToken());

            customer = customer > C ? C : customer;

            dp[customer] = Math.min(cost, dp[customer]);

        }

        for(int n = 1; n <= C; ++n) {
            for(int i = 1; i <= C; ++i) {
                if(i < n) {
                    dp[n] = Math.min(dp[n - i] + dp[i], dp[n]);
                } else {
                    dp[n] = Math.min(dp[n], dp[i]);
                }
            }
        }

        System.out.println(dp[C]);
    }
}